#pragma once

#include <complex>
#include <vector>
#include <cmath>

class FFT {
    using base = std::complex <double>;
    static constexpr double PI = acos(-1);
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
        void transform(std::vector <double>*, std::vector <base>*, int n);  

        std::vector <double> * X;
        
};
