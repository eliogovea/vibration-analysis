#include <QObject>

#include "reader.h"

Reader::Reader() {

}

bool Reader::start() {
    std::cout << "start reading\n";
    while (std::cin >> newValue) {
        // emit newData(newValue);
        emit newDataX(newValue.x);
        emit newDataY(newValue.y);
        emit newDataZ(newValue.z);
    }
}
