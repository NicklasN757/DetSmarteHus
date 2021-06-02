/*
 * RGBControl.h
 *
 * Created: 01-06-2021 14:49:18
 *  Author: nick4978
 */ 
#ifndef RGBCONTROL_H_
#define RGBCONTROL_H_

#include <Arduino.h>

//RGB variables
extern const int redLEDPin;
extern const int greenLEDPin;
extern const int blueLEDPin;

//Temperature variables
extern int currentSetTemperatureDining;
extern int currentSetTemperatureKids;
extern int currentTemperaturesDining;
extern int currentTemperaturesKids;
extern int hysteresis;

//Controls the RGB
void RGBController();

#endif /* RGBCONTROL_H_ */