#include <complex>
#include <iostream>
#include <algorithm>

#include <QVector>
#include <QWidget>
#include <QFrame>
#include <QVBoxLayout>

#include "buffer.h"
#include "chart.h"
#include "signalchart.h"

SignalChart::SignalChart(int windowSize, QWidget* parent) :
    windowSize(windowSize), 
    buffer(windowSize),
    t(windowSize),
    f(windowSize),
    x(windowSize),
    X(windowSize),
    absX(windowSize),
    fft(),
    QFrame(parent)
{

    resize(width, height);

    for (int i = 0; i < windowSize; i++) {
        t[i] = (double)i / (double)windowSize;
        f[i] = (double)i / (double)windowSize - 0.5;
    }

    QHBoxLayout* hbox = new QHBoxLayout(this);
    hbox->setSpacing(1);

    plotx = new QCustomPlot(this);
    plotx->addGraph();
    plotx->xAxis->setRange(0, 1);

    plotX = new QCustomPlot(this);
    plotX->addGraph();
    plotX->xAxis->setRange(-0.5, 0.5);

    hbox->addWidget(plotx);
    hbox->addWidget(plotX);

    setLayout(hbox);
}

void SignalChart::getNewX(double v) {
    buffer.addValue(v);
    for (int i = 0; i < windowSize; i++) {
        x[i] = buffer[i];
    }
    fft.transform(x, X, windowSize, true);
    for (int i = 0; i < windowSize; i++) {
        absX[i] = abs(X[i]);
    }

    double minx = x[0];
    double maxx = x[0];
    double minX = absX[0];
    double maxX = absX[0];

    for (int i = 1; i < windowSize; i++) {
        minx = std::min(minx, x[i]);
        maxx = std::max(maxx, x[i]);
        minX = std::min(minX, absX[i]);
        maxX = std::max(maxX, absX[i]);
    }

    plotx->graph(0)->setData(t, x);
    plotx->yAxis->setRange(minx, maxx);
    plotx->replot();

    plotX->graph(0)->setData(f, absX);
    plotX->yAxis->setRange(minX, maxX);
    plotX->replot();
}
