#pragma once

#include <complex>
#include <vector>
#include <cmath>

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
        std::vector <double> ractangleWindow(int);
        void applyWindow(std::vector <double>*, std::vector <double>*);

        // fft
        void transform(std::vector <double>*, std::vector <base>*, int, bool);  

        std::vector<double>* a;
        std::vector<std::complex<double>>* A;
};
