#include <cstring>
#include <fstream>

#include "reader.h"

Reader::Reader(std::string _path) : path(_path) {
    input.open(path);
}

bool Reader::readNewLine() {
    bool ok = true;
    try {
        input >> lastValue.x >> lastValue.y >> lastValue.z;
    } catch (std::ifstream::failure e) {
        ok = false;
    }

    if (ok) {
        lastValue = newValue;
    }

    return ok;
}

AccData Reader::getLastValue() {
    return lastValue;
}
