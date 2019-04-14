#include <QObject>
#include <QThread>

#include "reader.h"
#include "accdata.h"
#include "buffer.h"
#include "fft.h"
#include "chart.h"
#include "driver.h"

Driver::Driver(int _windowSize) : windowSize(_windowSize) {
    QThread *inputThread = new QThread;
    reader = new Reader();
    reader->moveToThread(inputThread);
    QObject::connect(inputThread, &QThread::started, reader, &Reader::start);
    // QObject::connect(reader, &Reader::newData, this, &Driver::getNewData);
    QObject::connect(reader, &Reader::newDataX, this, &Driver::getNewX);
    QObject::connect(reader, &Reader::newDataY, this, &Driver::getNewY);
    QObject::connect(reader, &Reader::newDataZ, this, &Driver::getNewZ);
    inputThread->start();


    bx = new Buffer<double>(windowSize);
    by = new Buffer<double>(windowSize);
    bz = new Buffer<double>(windowSize);
    bv = new Buffer<AccData>(windowSize);

    x = new std::vector<double>(windowSize);
    y = new std::vector<double>(windowSize);
    z = new std::vector<double>(windowSize);
    v = new std::vector<double>(windowSize);

    X = new std::vector<std::complex<double>>(windowSize);
    Y = new std::vector<std::complex<double>>(windowSize);
    Z = new std::vector<std::complex<double>>(windowSize);
    V = new std::vector<std::complex<double>>(windowSize);

    chartX = new Chart();
    chartY = new Chart();
    chartZ = new Chart();
    chartV = new Chart();

    chartX->show();
    chartY->show();
    chartZ->show();
    // chartV->show();

    fft = new FFT();
}

// TEST
void Driver::getNewX(double dx) {
    // std::cout << "new x " << dx << "\n";
    processNew(dx, bx, x, X, chartX);
}

void Driver::getNewY(double dy) {
    // std::cout << "new y " << dy << "\n";
    processNew(dy, by, y, Y, chartY);
}
void Driver::getNewZ(double dz) {
    // std::cout << "new z " << dz << "\n";
    processNew(dz, bz, z, Z, chartZ);
}

void Driver::getNewData(AccData d) {
    // std::cout << "new data " << d.x << " " << d.y << " " << d.z;

    // TODO process each fft in a separated thread
    
    processNew(d.x, bx, x, X, chartX);
    // processNew(v.y, by, y, Y, chartY);
    // processNew(v.z, bz, z, Z, chartZ);

    // TODO process abs value
}

void Driver::processNew(double nx, Buffer<double>* b, std::vector<double>* x, std::vector<std::complex<double>>* X, Chart* chart) {
    b->addValue(nx);
    for (int i = 0; i < windowSize; i++) {
        x->at(i) = b->at(i);
    }
    fft->transform(x, X, windowSize, false);
    for (int i = 0; i < windowSize; i++) {
        x->at(i) = abs(X->at(i));
    }
    chart->setXToDraw(x);
    chart->repaint();
}
