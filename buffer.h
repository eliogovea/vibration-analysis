#pragma once

#include <vector>

template <class T>
class Buffer {
    private:
        int _size;
        int head;
        std::vector <T> values;
    public:
        Buffer(int);
        void addValue(T);
        size_t size() const;
        const T& at(int) const;
        const T& operator [] (int idx) const;
};

