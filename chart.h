#pragma once

#include <vector>

#include <QFrame>

class Chart : public QFrame {
    Q_OBJECT
    public:
        Chart(QWidget* parent = 0);
        void setXToDraw(std::vector<double>*);
    protected:
        void paintEvent(QPaintEvent *);
    private:
        int width = 320;
        int height = 120;
        std::vector<double> *x = nullptr; // !!!
        void doDrawing();
};
