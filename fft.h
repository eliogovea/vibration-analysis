#pragma once

#include <complex>
#include <vector>
#include <cmath>

#include <QVector>

class FFT {
    using base = std::complex <double>;
    static constexpr double PI = acos(-1);
    static constexpr size_t MAX_SIZE = 1 << 15; // fix ???
    public:
        FFT();

        // util
        bool isPowerOfTwo(int);
        int getLog(int);
        int reverseBits(int, int);

        // window
        QVector<double> ractangleWindow(int);
        void applyWindow(QVector<double>, QVector<double>);

        // fft
        void transform(const QVector<double>&, QVector<base>&, int, bool);
        std::vector<base> A;
};
