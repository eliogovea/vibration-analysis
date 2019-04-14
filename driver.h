#pragma once

#include <QObject>

#include "reader.h"
#include "accdata.h"
#include "buffer.h"
#include "fft.h"
#include "chart.h"

class Driver : public QObject {
    Q_OBJECT
    public:
        Driver(int windowSize);
    public slots:
        void getNewData(AccData);
        void getNewX(double);
        void getNewY(double);
        void getNewZ(double);
    private:
        int windowSize;

        Reader* reader;

        Buffer<double>* bx;
        Buffer<double>* by;
        Buffer<double>* bz;
        Buffer<AccData>* bv;

        std::vector<double>* x;
        std::vector<double>* y;
        std::vector<double>* z;
        std::vector<double>* v;
        
        std::vector<std::complex<double>>* X;
        std::vector<std::complex<double>>* Y;
        std::vector<std::complex<double>>* Z;
        std::vector<std::complex<double>>* V;

        Chart* chartX;
        Chart* chartY;
        Chart* chartZ;
        Chart* chartV;

        FFT* fft;

        void processNew(double nx, Buffer<double>* b, std::vector<double>* x, std::vector<std::complex<double>>* X, Chart*);
};
