#pragma once

#include <QWidget>

class RandomPoints : public QWidget {
    public:
        RandomPoints(int _timeDelay, QWidget* parent = 0);
    protected:
        void paintEvent(QPaintEvent *);
        void keyPressEvent(QKeyEvent *);
        void timerEvent(QTimerEvent *);
    private:
        static const int WIDTH = 300;
        static const int HEIGHT = 300;

        void doDrawing();

        int timeDelay;
};
