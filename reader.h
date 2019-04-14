#pragma once

#include <QObject>

#include "accdata.h"

class Reader : public QObject {
    Q_OBJECT
    public:
        Reader();
    signals:
        void newDataX(double x);
        void newDataY(double y);
        void newDataZ(double z);
        void newData(AccData v);
    public slots:
        bool start();
    private:
        AccData newValue = AccData();
};
