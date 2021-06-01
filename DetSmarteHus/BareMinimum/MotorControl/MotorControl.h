/*
 * MotorControl.h
 *
 * Created: 28-05-2021 11:15:15
 *  Author: nick4978
 */ 


#ifndef MOTORCONTROL_H_
#define MOTORCONTROL_H_

#include <Arduino.h>

//Fan/Motor variables
extern int currentFanSpeed;
extern bool fanAutoMode;
extern const int motorPin;

//Temperature variables
extern int currentSetTemperatureDining;
extern int currentSetTemperatureKids;
extern int currentTemperaturesDining;
extern int currentTemperaturesKids;
extern int hysteresis;

//Calculate moter speed from potentiometerValue
int calculateMotorSpeed(int potentiometerValue);

//Calculate moter speed from procent
int calculateMotorSpeedFromProcent(int procent);

//Sets the motor speed
void setMotorSpeed();

#endif /* MOTORCONTROL_H_ */