#include "buffer.h"
#include "accdata.h"

Buffer::Buffer(int _size) : _size(_size), head(0), values(_size) {};

void Buffer::addValue(AccData v) {
    values[head] = v;
    head++;
    if (head == _size) {
        head = 0;
    }
}

size_t Buffer::size() const {
    return _size;
}

AccData Buffer::at(int idx) const {
    if (head + idx < _size) {
        return values[head + idx];
    }
    return values[head + idx - _size];
}

AccData Buffer::operator[] (int idx) const {
    return at(idx);
}
