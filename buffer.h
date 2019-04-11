#include <vector>

#include "accdata.h"

class Buffer {
    private:
        int _size;
        int head;
        std::vector <AccData> values;
    public:
        Buffer(int);
        void addValue(AccData);
        size_t size() const;
        AccData at(int) const;
        AccData operator [] (int idx) const;

};
