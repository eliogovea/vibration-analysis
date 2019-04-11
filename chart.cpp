#include <QPainter>
#include <iostream>

#include "chart.h"

Chart::Chart(int _windowSize, int _timeDelay, std::string inputFile, QWidget* parent) : 
    windowSize(_windowSize), 
    timeDelay(_timeDelay),
    QWidget(parent) 
{
    reader = new Reader(inputFile);
    buffer = new Buffer(_windowSize);
    fft = new FFT();

    startTimer(timeDelay);
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

    // generate random points, for testing
//    int last_x = 0;
//    int last_y = 0;
//    for (int x = 0; x < WIDTH; x += 5) {
//        int y = qrand() % HEIGHT;
//        qp.drawLine(last_x, last_y, x, y);
//        last_x = x;
//        last_y = y;
//    }
//
    int last_x;
    int last_y;
    for (int i = 0; i < (int)buffer->size(); i++) {
        int x = (double)i / (buffer->size()) * (double)WIDTH;
        int y = (buffer->at(i).x - (-1)) / 2.0 * HEIGHT;
        if (i > 0) {
            qp.drawLine(last_x, last_y, x, y);
        }
        last_x = x;
        last_y = y;
    }
}

