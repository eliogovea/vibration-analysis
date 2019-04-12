#pragma once

#include <cstring>
#include <fstream>

#include <QObject>
#include <QFileSystemWatcher>

#include "accdata.h"

class Reader : public QObject {
    Q_OBJECT
    public:
        Reader(std::string);
        AccData getLastValue();
    signals:
        void newDataX(double x);
        void newDataY(double y);
        void newDataZ(double z);
        void newData(AccData v);
    public slots:
        bool readNewLine();
        bool start();
    private:
        // QFileSystemWatcher watcher;
        std::string const path;
        std::ifstream input;
        AccData lastValue = AccData();
        AccData newValue = AccData();
};
