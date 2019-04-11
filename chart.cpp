#include <QPainter>

#include "chart.h"

RandomPoints::RandomPoints(int _timeDelay, QWidget* parent) : QWidget(parent) {
    timeDelay = _timeDelay;
    resize(WIDTH, HEIGHT);
    startTimer(timeDelay);
}

void RandomPoints::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);
    doDrawing();
}

void RandomPoints::keyPressEvent(QKeyEvent *e) {
    // TODO use key
    // int key = e->key();

    Q_UNUSED(e);
    repaint();
    QWidget::keyPressEvent(e); 
}

void RandomPoints::timerEvent(QTimerEvent *e) {
    Q_UNUSED(e);
    repaint();
    QWidget::timerEvent(e);
}

void RandomPoints::doDrawing() {
    // TODO
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
