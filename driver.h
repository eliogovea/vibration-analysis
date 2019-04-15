#pragma once

#include <QWidget>
#include <QFrame>

#include "reader.h"
#include "signalchart.h"

class Driver : public QFrame {
    Q_OBJECT
    public:
        Driver(int windowSize, QWidget* parent = 0);
    public slots:
        void getNewData(AccData);
        void getNewX(double);
        void getNewY(double);
        void getNewZ(double);
        void getNewAbs(double);
    private:
        int width = 900;
        int height = 640;
        int windowSize;
        Reader* reader;
        SignalChart* x;
        SignalChart* y;
        SignalChart* z;
        SignalChart* l;
        void processNew(double, SignalChart*);
};
