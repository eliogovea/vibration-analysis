#include <iostream>
#include <cstring>

#include <QApplication>

#include "chart.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    Chart window(1024, 100, "input.txt", nullptr);

    window.show();

    return app.exec();
}
