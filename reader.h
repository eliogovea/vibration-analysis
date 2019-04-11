#pragma once

#include <cstring>
#include <fstream>

#include <QObject>
#include <QFileSystemWatcher>

#include "accdata.h"

class Reader : public QObject {
    public:
        Reader(std::string);
        AccData getLastValue();
    private:
        QFileSystemWatcher watcher;
        std::string const path;
        std::ifstream input;
        AccData lastValue = AccData();
        AccData newValue = AccData();
    public slots:
        bool readNewLine();
        
};
