#include <iostream>
#include <cstring>

#include <QApplication>

#include "chart.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    Chart window(64, 1000, "/dev/stdin", nullptr);

    window.show();

    return app.exec();
}
