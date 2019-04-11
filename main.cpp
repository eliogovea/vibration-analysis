#include <iostream>

#include <QApplication>

#include "chart.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    RandomPoints window(1000);

    window.show();

    return app.exec();
}
