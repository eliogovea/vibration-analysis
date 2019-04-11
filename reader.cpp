#include <cstring>
#include <fstream>

#include "reader.h"

Reader::Reader(std::string _path, int _bufferSize) : path(_path), bufferSize(_bufferSize) {
    input.open(path);
}

std::string Reader::readNewLine() {
    try {
        std::getline(input, line);
    } catch (std::ifstream::failure e) {
        // TODO
        line = "";
    }
    return line;
}
