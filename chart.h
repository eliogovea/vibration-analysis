#pragma once

#include <QWidget>
#include <complex>

#include "reader.h"

class Chart : public QWidget {
    public:
        Chart(int _windowSize, int _timeDelay, Reader* _reader = nullptr, QWidget* parent = 0);
    protected:
        void paintEvent(QPaintEvent *);
        void keyPressEvent(QKeyEvent *);
        void timerEvent(QTimerEvent *);
        void doDrawing();
    private:
        static const int WIDTH = 300;
        static const int HEIGHT = 300;
        int windowSize;
        int timeDelay;
        Reader* reader;
};
