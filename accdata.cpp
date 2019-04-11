#include <iostream>

#include "accdata.h"

AccData::AccData() : x(0), y(0), z(0) {

}

std::istream& operator >> (std::istream& in, AccData& obj) {
    in >> obj.x >> obj.y >> obj.z;
    return in;
}
