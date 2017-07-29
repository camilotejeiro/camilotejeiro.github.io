---
title: PVT Invariant Voltage Controlled Low Pass Filter
---

This project built into the previously designed adjustable high order low pass
filter, the idea was to design a PID controller that will make the low pass
filter cuttoff frequency be determined only by the user and not by PVT (process,
voltage or temperature) variations. In general terms what this means is that now
the system was completely independent of weather conditions, fabrication
processes or even slight variation in supply voltages. To implement the
calibration system we used an ATMEGA 328 uController with an Arduino ISP, we
also made use of Digital to Analog Converters, a peak to peak detector, a
voltage controlled oscillator and analog circuitry for analog/digital
interfacing. More details can be found in the design report

Here is the design report for the project:

[PVT Invariant Voltage Controlled Low Pass Filter](/assets/2014-08-27-pvt-invariant-voltage-controlled-low-pass-filter_1.pdf)

Here is the code for the ATMEGA 328 uController (.ino source code): 

[Lab 3 Source Code](/assets/2014-08-27-pvt-invariant-voltage-controlled-low-pass-filter_2.ino)

[Here is a video](https://youtu.be/Pdd09ADTbhs)

And some neat pictures taken of the complete circuit.

![Circuit Picture 1](/assets/2014-08-27-pvt-invariant-voltage-controlled-low-pass-filter_3.jpg)
![Circuit 2](/assets/2014-08-27-pvt-invariant-voltage-controlled-low-pass-filter_4.jpg)
![Circuit 3](/assets/2014-08-27-pvt-invariant-voltage-controlled-low-pass-filter_5.jpg)
![Circuit w.  ISP](/assets/2014-08-27-pvt-invariant-voltage-controlled-low-pass-filter_6.jpg)
