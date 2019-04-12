#include <iostream>
#include <cstring>

#include <QApplication>

#include "chart.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    Chart window(1 << 14, 100, "/dev/stdin", nullptr);

    window.show();

    return app.exec();
}
