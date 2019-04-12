#include <iostream>

#include "accdata.h"

AccData::AccData(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {

}

std::istream& operator >> (std::istream& in, AccData& obj) {
    in >> obj.x >> obj.y >> obj.z;
    return in;
}
