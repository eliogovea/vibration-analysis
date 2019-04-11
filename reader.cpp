#include <cstring>
#include <fstream>

#include <QString>

#include "reader.h"

Reader::Reader(std::string _path) : path(_path) {
    input.open(path);
    watcher.addPath(QString::fromStdString(path));


    QObject::connect(&watcher, &QFileSystemWatcher::fileChanged, this, &Reader::readNewLine);

//    connect(&watcher, SIGNAL(fileChanged(const QString&)), this, SLOT(readNewLine()));
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
    } else {
        lastValue.x = 0;
        lastValue.y = 0;
        lastValue.z = 0;
    }

    std::cout << lastValue.x << " " << lastValue.y << " " << lastValue.z << "\n";

    return ok;
}

AccData Reader::getLastValue() {
    return lastValue;
}
