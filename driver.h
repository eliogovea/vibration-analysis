#pragma once

#include <QObject>

#include "reader.h"
#include "signalchart.h"

class Driver : public QObject {
    Q_OBJECT
    public:
        Driver(int windowSize);
    public slots:
        void getNewData(AccData);
        void getNewX(double);
        void getNewY(double);
        void getNewZ(double);
        void getNewAbs(double);
    private:
        int windowSize;
        Reader* reader;
        SignalChart* x;
        SignalChart* y;
        SignalChart* z;
        SignalChart* l;
        void processNew(double, SignalChart*);
};
