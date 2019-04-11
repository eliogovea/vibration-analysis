#include <QPainter>

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
    repaint();
    QWidget::timerEvent(e);
}

void Chart::doDrawing() {
    // TODO
    // generate random points, for testing
    QPainter qp(this);
    QPen pen(Qt::black, 2, Qt::SolidLine);
    qp.setPen(pen);

    int last_x = 0;
    int last_y = 0;
    for (int x = 0; x < WIDTH; x += 5) {
        int y = qrand() % HEIGHT;
        qp.drawLine(last_x, last_y, x, y);
        last_x = x;
        last_y = y;
    }
}
