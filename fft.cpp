#include <complex>
#include <vector>

#include "fft.h"

FFT::FFT() {
    a = new std::vector<double>(MAX_SIZE);
    A = new std::vector<std::complex<double>>(MAX_SIZE);
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

void FFT::transform(std::vector <double> *x, std::vector <base> *X, int n, bool shift = true) {
    // assert(isPowerOfTow(n)); // TODO
    if ((int)X->size() < n) {
        X->resize(n);
    }

    int ln = getLog(n);
    
    for (int i = 0; i < n; i++) {
        if (i >= (int)X->size()) {
            break;
        }
        A->at(reverseBits(i, ln)) = base(x->at(i));
    }

    for (int len = 2; len <= n; len <<= 1) {
        int halfLen = len >> 1;
        double angle = -2.0 * PI / (double)len;
        auto root = base(cos(angle), sin(angle));
        for (int i = 0; i < n; i += len) {
            auto w = base(1, 0);
            for (int j = 0; j < halfLen; j++) {
                base u = A->at(i + j);
                base v = A->at(i + j + halfLen) * w;
                A->at(i + j) = u + v;
                A->at(i + j + halfLen) = u - v;
                w *= root;
            }
        }
    }

    if (shift) {
        int pos_X = 0;
        int pos_A = n >> 1;
        for (int i = 0; i < (n >> 1); i++) {
            X->at(pos_X++) = A->at(pos_A++);
        }
        pos_A = 0;
        for (int i =0 ; i < (n >> 1); i++) {
            X->at(pos_X++) = A->at(pos_A++);
        }
    } else {
        for (int i = 0; i < n; i++) {
            X->at(i) = A->at(i);
        }
    }
}
