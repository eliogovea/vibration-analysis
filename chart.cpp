#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <limits>

#include <QObject>
#include <QPainter>
#include <QThread>

#include "chart.h"
#include "buffer.h"
#include "fft.h"
#include "accdata.h"

extern template class Buffer<AccData>;

Chart::Chart(int _windowSize, int _timeDelay, std::string inputFile, QWidget* parent) : 
    windowSize(_windowSize), 
    timeDelay(_timeDelay),
    QWidget(parent) 
{
    QThread *inputThread = new QThread;
    reader = new Reader(inputFile);
    reader->moveToThread(inputThread);
    QObject::connect(inputThread, &QThread::started, reader, &Reader::start);
    QObject::connect(reader, &Reader::newDataX, this, &Chart::getDouble);
    inputThread->start();

    buffer = new Buffer<AccData>(_windowSize);
    fft = new FFT();

    resize(WIDTH, HEIGHT);
    // startTimer(timeDelay);
}

void Chart::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);
    doDrawing();
    QWidget::paintEvent(e);
}

void Chart::keyPressEvent(QKeyEvent *e) {
    // TODO use key
    // int key = e->key();

    Q_UNUSED(e);
    repaint();
    QWidget::keyPressEvent(e); 
}

void Chart::timerEvent(QTimerEvent *e) {
    Q_UNUSED(e);

    buffer->addValue(reader->getLastValue());

    repaint();

    QWidget::timerEvent(e);
}

void Chart::doDrawing() {
    // TODO
    QPainter qp(this);
    QPen pen(Qt::black, 2, Qt::SolidLine);
    qp.setPen(pen);
/*
    // generate random points, for testing
    int last_x = 0;
    int last_y = 0;
    for (int x = 0; x < WIDTH; x += 5) {
        int y = qrand() % HEIGHT;
        qp.drawLine(last_x, last_y, x, y);
        last_x = x;
        last_y = y;
    }
*/

    static auto x = new std::vector <double>(windowSize);
    x->resize(windowSize);

    static auto X = new std::vector <std::complex <double>>;
    X->resize(windowSize);

    for (int i = 0; i < (int)buffer->size(); i++) {
        x->at(i) = buffer->at(i).x;
    }

    fft->transform(x, X, windowSize, false);

    double mx = std::numeric_limits<double>::min();
    double mn = std::numeric_limits<double>::max();

    for (int i = 0; i < windowSize; i++) {
        mx = std::max(mx, std::abs(X->at(i)));
        mn = std::min(mn, std::abs(X->at(i)));
    }

    // first half only
    for (int i = 0, last_x = 0, last_y = 0, xx, yy; i < windowSize / 2; i++) {
        xx = (double)i / (0.5 * (double)windowSize) * (double)WIDTH;
        yy = (abs(X->at(i)) - mn) / (mx - mn) * HEIGHT;
        yy = HEIGHT - yy;

        // int y = (buffer->at(i).x - (-1)) / 2.0 * (double)HEIGHT;

        if (i > 0) {
            qp.drawLine(last_x, last_y, xx, yy);
        }

        last_x = xx;
        last_y = yy;
    }
}

void Chart::getData(AccData v) {
    // std::cout << "new data: " << v.x << " " << v.y << " " << v.z << "\n";
    buffer->addValue(v);
}

void Chart::getDouble(double v) {
    // std::cout << "new single value" << v << "\n";
    buffer->addValue(AccData(v, 0, 0));
    repaint();
}
