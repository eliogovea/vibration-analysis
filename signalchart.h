#pragma once

#include <QObject>
#include <QWidget>
#include <QFrame>

#include <vector>
#include <complex>

#include "buffer.h"
#include "fft.h"
#include "chart.h"

class SignalChart : public QFrame {
    Q_OBJECT
    using base = std::complex<double>;
    public:
        SignalChart(int windowSize, QWidget* parent = 0);
    public slots:
        void getNewX(double);
    private:
        int width = 720;
        int height = 120;
        int windowSize;
        Buffer<double>* buffer;
        std::vector<double>* x;
        std::vector<base>* X;
        std::vector<double>* absX;
        FFT* fft;

        Chart* chartx;
        Chart* chartX;
};
