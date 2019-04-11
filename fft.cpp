#include <complex>
#include <QVector>

#include "fft.h"

FFT::FFT() {
    //
}

bool FFT::isPowerOfTwo(int value) {
    return ((value > 0) && ((value & (value - 1)) == 0));
}

int FFT::getLog(int value) {
    int lg = 0;
    while ((1 << lg) < value) {
        lg++;
    }
    // assert((1 << lg) == value);
    return lg;
}

int FFT::reverseBits(int value, int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result = (result << 1) | (value & 1);
        value >>= 1;
    }
    return result;
}

std::vector <double> rectangleWindow(int size) {
    return std::vector <double> (size, 1);
}

void applyWindow(std::vector <double>* x, std::vector <double>* w) {
    // assert(x->size() == w->size());
    for (int i = 0; i < (int)x->size(); i++) {
        x->at(i) *= w->at(i);
    }
}

void FFT::transform(std::vector <double> *x, std::vector <base> *X, int n) {
    // assert(isPowerOfTow(n)); // TODO
    if ((int)X->size() < n) {
        X->resize(n);
    }

    int ln = getLog(n);
    
    for (int i = 0; i < n; i++) {
        if (i >= (int)X->size()) {
            break;
        }
        X->at(reverseBits(i, ln)) = base(x->at(i));
    }

    for (int len = 2; len <= n; len <<= 1) {
        int halfLen = len >> 1;
        double angle = -2.0 * PI / (double)len;
        auto root = base(cos(angle), sin(angle));
        for (int i = 0; i < n; i += len) {
            auto w = base(1, 0);
            for (int j = 0; j < halfLen; j++) {
                base u = X->at(i + j);
                base v = X->at(i + j + halfLen) * w;
                X->at(i + j) = u + v;
                X->at(i + j + halfLen) = u - v;
                w *= root;
            }
        }
    }
}
