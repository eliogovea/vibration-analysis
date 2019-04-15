#include <iostream>
#include <cmath>

#include "accdata.h"

AccData::AccData(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {

}

double AccData::abs() const {
    return sqrt(x * x + y * y + z * z);
}

std::istream& operator >> (std::istream& in, AccData& obj) {
    in >> obj.x >> obj.y >> obj.z;
    return in;
}
