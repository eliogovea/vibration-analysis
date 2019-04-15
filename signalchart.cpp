#include <vector>
#include <complex>
#include <iostream>

#include <QWidget>
#include <QFrame>
#include <QVBoxLayout>

#include "buffer.h"
#include "chart.h"
#include "signalchart.h"

SignalChart::SignalChart(int windowSize, QWidget* parent) : windowSize(windowSize), QFrame(parent) {
    resize(700, 700);

    buffer = new Buffer<double>(windowSize);
    x = new std::vector<double>(windowSize);
    X = new std::vector<base>(windowSize);
    absX = new std::vector<double>(windowSize);
    fft = new FFT();

    QHBoxLayout* hbox = new QHBoxLayout(this);
    hbox->setSpacing(1);

    chartx = new Chart(this);
    chartX = new Chart(this);

    hbox->addWidget(chartx);
    hbox->addWidget(chartX);

    setLayout(hbox);
}

void SignalChart::getNewX(double v) {
    std::cout << "????\n";
    buffer->addValue(v);
    for (int i = 0; i < windowSize; i++) {
        x->at(i) = buffer->at(i);
    }
    fft->transform(x, X, windowSize, false);
    for (int i = 0; i < windowSize; i++) {
        absX->at(i) = abs(X->at(i));
    }
    chartx->setXToDraw(x);
    chartx->repaint();

    chartX->setXToDraw(absX);
    chartX->repaint();
}
