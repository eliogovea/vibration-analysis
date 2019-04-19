#include <QWidget>
#include <QFrame>
#include <QVBoxLayout>
#include <QThread>

#include "reader.h"
#include "accdata.h"
#include "buffer.h"
#include "fft.h"
#include "chart.h"
#include "driver.h"

Driver::Driver(int _windowSize, QWidget* parent) : 
    windowSize(_windowSize), QFrame(parent) {

    resize(width, height);

    QVBoxLayout* vbox = new QVBoxLayout(this);

    x = new SignalChart(windowSize);
    y = new SignalChart(windowSize);
    z = new SignalChart(windowSize);
    l = new SignalChart(windowSize);

    vbox->addWidget(x);
    vbox->addWidget(y);
    vbox->addWidget(z);
    vbox->addWidget(l);

    QThread *inputThread = new QThread;
    reader = new Reader();
    reader->moveToThread(inputThread);
    QObject::connect(inputThread, &QThread::started, reader, &Reader::start);
    // QObject::connect(reader, &Reader::newData, this, &Driver::getNewData);
    QObject::connect(reader, &Reader::newDataX, this, &Driver::getNewX);
    QObject::connect(reader, &Reader::newDataY, this, &Driver::getNewY);
    QObject::connect(reader, &Reader::newDataZ, this, &Driver::getNewZ);
    QObject::connect(reader, &Reader::newDataAbs, this, &Driver::getNewAbs);
    inputThread->start();

    setLayout(vbox);
}

// TEST
void Driver::getNewX(double dx) {
    // std::cout << "new x " << dx << "\n";
    processNew(dx, x);
}

void Driver::getNewY(double dy) {
    // std::cout << "new y " << dy << "\n";
    processNew(dy, y);
}
void Driver::getNewZ(double dz) {
    // std::cout << "new z " << dz << "\n";
    processNew(dz, z);
}

void Driver::getNewAbs(double dl) {
    processNew(dl, l);
}

void Driver::getNewData(AccData d) {
    // TODO
}

void Driver::processNew(double v, SignalChart *sc) {
    sc->getNewX(v);
}
