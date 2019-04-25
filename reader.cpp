#include <cmath>

#include <QObject>
#include <QDebug>
#include <QSerialPort>
#include <QByteArray>


#include <QString>

#include "reader.h"

Reader::Reader() {

}

void Reader::handleReadyRead() {
    if (!serial->canReadLine()) {
        return;
    }

    QString line = serial->readLine();

    double x, y, z;
    QTextStream stream(&line);

    stream >> x >> y >> z;

    double l = sqrt(x * x + y* y + z * z);

    emit newDataX(x);
    emit newDataY(y);
    emit newDataZ(z);
    emit newDataAbs(l);

    // qDebug() << x << " " << y << " " << z << "\n";
}

bool Reader::start() {
    serial = new QSerialPort();
    serial->setPortName("ttyUSB0");

    serial->setParity(QSerialPort::NoParity);

    serial->setBaudRate(QSerialPort::Baud115200, QSerialPort::AllDirections);

    serial->setStopBits(QSerialPort::OneStop);

    serial->setFlowControl(QSerialPort::NoFlowControl);

    serial->open(QIODevice::ReadOnly);

    if (!serial->isOpen()) {
        qDebug() << "can't open\n";
        return false;
    }

    connect(serial, &QSerialPort::readyRead, this, &Reader::handleReadyRead);

/*
    qDebug() << "start reading\n";

    QString line;
    QByteArray arr;

    while (serial->isOpen()) {
        arr = serial->readAll();
        qDebug() << arr.size();
        for (int i = 0; i < arr.size(); i++) {
            qDebug() << i << " " << QChar(arr[i]);
        }
    }

    qDebug() << "closed\n";
*/
/*
    while (std::cin >> newValue) {
        // emit newData(newValue);
        emit newDataX(newValue.x);
        emit newDataY(newValue.y);
        emit newDataZ(newValue.z);
        emit newDataAbs(newValue.abs());
    }
*/
}
