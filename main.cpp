#include <iostream>
#include <cstring>

#include <QApplication>

#include "driver.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
/*
    Chart chart_1;
    chart_1.show();

    Chart chart_2;
    chart_2.show();

    std::vector<double> v(100);
    for (auto &x : v) {
        x = qrand() % 100;
    }
    chart_1.setXToDraw(&v);
    for (auto &x : v) {
        x = qrand() % 100;
    }
    chart_2.setXToDraw(&v);
*/
/*
    SignalChart schart(1 << 10);
    schart.show();
*/
    Driver driver(1 << 10);
    return app.exec();
}
