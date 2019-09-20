# Vibration

Real time visualization of the spectrum of the data from a digital accelerometer with [Qt](https://www.qt.io/) and  [QCustomPlot](https://www.qcustomplot.com/). The data is expected to be received through a serial port ```/dev/ttyUSB0```.

On the left side the app shows a plot of the acceleration on each axis and the absolute value. On the right side there are four plots of the spectrum of each signal from the left side. For the spectrum a rectangular window is used. The results depend on the sampling frequency (expected to be constant), so every chart's _x-axis_ goes from 0 to 0.5 and _x_ value represents the frequency _x_ multiplied by the sampling frequency (the limist are because of the [Nyquist theorem](https://en.wikipedia.org/wiki/Nyquist%E2%80%93Shannon_sampling_theorem)).

### Details
Each data frame will be a line with the format "x y z\n\r"

### Dependencies
- Qt

## Build
```
qmake
make
```

## Run
```
./vib
```
## **TODO**
- [ ] Describe the complete system (ADXL345, Arduino, Rasberry Pi, XBee).
- [ ] Choose a better window for the FFT.
- [ ] Add option for serial port.
- [ ] Check the sampling frequency and show it in the charts.
- [ ] Allow the user to choose the data stream (serial port will not be fast enough for some applications).
- [ ] Add screenshots.
