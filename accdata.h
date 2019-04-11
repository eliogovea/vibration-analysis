#pragma once

#include <iostream>

class AccData {
    public:
        double x, y, z;
        AccData();
        friend std::istream& operator >> (std::istream& in, AccData& obj);
};
