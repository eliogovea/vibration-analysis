#include <iostream>
#include <cstring>

#include <QApplication>

#include "driver.h"
#include "chart.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    auto driver = new Driver(1024);

    return app.exec();
}
