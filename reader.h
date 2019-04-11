#pragma once

#include <cstring>
#include <fstream>

#include "accdata.h"

class Reader {
    public:
        Reader(std::string);
        bool readNewLine();
        AccData getLastValue();
    private:
        std::string const path;
        std::ifstream input;
        AccData lastValue = AccData();
        AccData newValue = AccData();
};
