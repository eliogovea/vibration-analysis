#include <vector>
#include <algorithm>
#include <limits>

#include <QObject>
#include <QPainter>

#include "chart.h"

Chart::Chart(QWidget* parent) : QWidget(parent) {
    resize(width, height);
}

void Chart::setXToDraw(std::vector<double>* x) {
    this->x = x;
}

void Chart::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);
    doDrawing(x);
    QWidget::paintEvent(e);
}

void Chart::doDrawing(std::vector<double>* x) {
    QPainter qp(this);
    QPen pen(Qt::black, 2, Qt::SolidLine);
    qp.setPen(pen);

    int n = x->size();

    double mx = std::numeric_limits<double>::min();
    double mn = std::numeric_limits<double>::max();

    for (int i = 0; i < n; i++) {
        mx = std::max(mx, x->at(i));
        mn = std::min(mn, x->at(i));
    }

    for (int i = 0, lastX = 0, lastY = 0; i < n; i++) {
        int xx = (double)i / (double)n * (double)width;
        int yy = (x->at(i) - mn) / (mx - mn) * height;
        yy = height - yy;
        if (i > 0) {
            qp.drawLine(lastX, lastY, xx, yy);
        }
        lastX = xx;
        lastY = yy;
    }
}
