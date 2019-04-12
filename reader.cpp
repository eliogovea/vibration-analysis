#include <cstring>
#include <fstream>

#include <QString>

#include "reader.h"

Reader::Reader(std::string _path) : path(_path) {
    input.open(path);

    // watcher.addPath(QString::fromStdString(path));
    // QObject::connect(&watcher, &QFileSystemWatcher::fileChanged, this, &Reader::readNewLine);
}

bool Reader::readNewLine() {
    bool ok = true;
    try {
        input >> newValue.x >> newValue.y >> newValue.z;
    } catch (std::ifstream::failure e) {
        ok = false;
    }

    if (ok) {
        lastValue = newValue;
    }

    return ok;
}

bool Reader::start() {
    std::cout << "start reading\n";
    while (std::cin >> lastValue) {
        emit newData(lastValue);
        emit newDataX(lastValue.x);
        emit newDataY(lastValue.y);
        emit newDataZ(lastValue.z);
    }
}

AccData Reader::getLastValue() {
    return lastValue;
}
