#pragma once

#include <QWidget>
#include <complex>

#include "reader.h"
#include "buffer.h"
#include "fft.h"

class Chart : public QWidget {
    public:
        Chart(int _windowSize, int _timeDelay, std::string inputFile, QWidget* parent = 0);
    protected:
        void paintEvent(QPaintEvent *);
        void keyPressEvent(QKeyEvent *);
        void timerEvent(QTimerEvent *);
        void doDrawing();
    private:
        int WIDTH = 300;
        int HEIGHT = 300;
        int windowSize;
        int timeDelay;
        Reader* reader;
        Buffer* buffer;
        FFT* fft;
};
