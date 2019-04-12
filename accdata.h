#pragma once

#include <iostream>

#include <QMetaType>

class AccData {
    public:
        double x, y, z;
        AccData(double x = 0, double y = 0, double z = 0);
        friend std::istream& operator >> (std::istream& in, AccData& obj);
};

Q_DECLARE_METATYPE(AccData)
