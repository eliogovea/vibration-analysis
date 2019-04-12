#include "buffer.h"
#include "accdata.h"

template <class T>
Buffer<T>::Buffer(int _size) : _size(_size), head(0), values(_size) {

};

template <class T>
void Buffer<T>::addValue(T v) {
    values[head] = v;
    head++;
    if (head == _size) {
        head = 0;
    }
}

template <class T>
size_t Buffer<T>::size() const {
    return _size;
}

template <class T>
const T& Buffer<T>::at(int idx) const {
    if (head + idx < _size) {
        return values[head + idx];
    }
    return values[head + idx - _size];
}

template <class T>
const T& Buffer<T>::operator[] (int idx) const {
    return at(idx);
}

// !!!
template Buffer<AccData>::Buffer(int _size);
template void Buffer<AccData>::addValue(AccData);
template size_t Buffer<AccData>::size() const;
template const AccData& Buffer<AccData>::at(int) const;
template const AccData& Buffer<AccData>::operator[] (int) const ;

template Buffer<double>::Buffer(int);
template void Buffer<double>::addValue(double);
template size_t Buffer<double>::size() const;
template const double& Buffer<double>::at(int) const;
template const double& Buffer<double>::operator[] (int) const ;
