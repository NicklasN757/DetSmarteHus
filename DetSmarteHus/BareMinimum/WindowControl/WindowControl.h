/*
 * WindowControl.h
 *
 * Created: 28-05-2021 14:24:39
 *  Author: nick4978
 */ 


#ifndef WINDOWCONTROL_H_
#define WINDOWCONTROL_H_

#include <Arduino.h>
#include <Servo.h>

//Servo variables
extern Servo servoMotor;

//Window variables
extern bool WindowIsOpen;
extern bool windowAutoMode;

//Temperature and humidity variables
extern int currentSetTemperatureKids;
extern int currentTemperaturesKids;
extern int currentHumidity;
extern int currentSetHumidity;
extern int humidityhysteresis;

void WindowController();

#endif /* WINDOWCONTROL_H_ */