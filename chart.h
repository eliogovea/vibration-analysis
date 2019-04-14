#pragma once

#include <vector>

#include <QWidget>

class Chart : public QWidget {
    Q_OBJECT
    public:
        Chart(QWidget* parent = 0);
        void setXToDraw(std::vector<double>*);
        void doDrawing(std::vector<double>* x);
    protected:
        void paintEvent(QPaintEvent *);
    private:
        int width = 320;
        int height = 240;
        std::vector<double> *x;
};
