#pragma once

#include <QWidget>
#include <complex>

#include "reader.h"
#include "buffer.h"
#include "fft.h"
#include "accdata.h"

class Chart : public QWidget {
    Q_OBJECT
    public:
        Chart(int _windowSize, int _timeDelay, std::string inputFile, QWidget* parent = 0);
    public slots:
        void getData(AccData);
        void getDouble(double);
    protected:
        void paintEvent(QPaintEvent *);
        void keyPressEvent(QKeyEvent *);
        void timerEvent(QTimerEvent *);
        void doDrawing();
    private:
        int WIDTH = 320; 
        int HEIGHT = 240;
        int windowSize;
        int timeDelay;
        Reader* reader;
        Buffer* buffer;
        FFT* fft;
};
