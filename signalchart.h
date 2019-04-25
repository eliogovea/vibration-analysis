#pragma once
#include <limits>

#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QVector>

#include <vector>
#include <complex>

#include "qcustomplot.h"

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
        Buffer<double> buffer;
        QVector<double> t;
        QVector<double> f;
        QVector<double> x;
        QVector<base> X;
        QVector<double> absX;
        FFT fft;
        QCustomPlot* plotx;
        QCustomPlot* plotX;
        double lastPointKey = std::numeric_limits<double>::min();
};
