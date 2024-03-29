#pragma once

#include <QObject>
#include <QSerialPort>

#include "accdata.h"

class Reader : public QObject {
    Q_OBJECT
    public:
        Reader();
    signals:
        void newDataX(double x);
        void newDataY(double y);
        void newDataZ(double z);
        void newDataAbs(double v);
        void newData(AccData v);
    public slots:
        bool start();
        void handleReadyRead();
    private:
        AccData newValue = AccData();
        QSerialPort *serial;
        QByteArray raw;
};
