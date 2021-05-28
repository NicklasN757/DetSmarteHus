/*
 * TemperatureControl.h
 *
 * Created: 28-05-2021 09:47:22
 *  Author: nick4978
 */ 


#ifndef TEMPERATURECONTROL_H_
#define TEMPERATURECONTROL_H_

#include <Arduino.h>

float calculateTemp(int sensorValue);

extern int currentSetTemperatureDining;
extern int currentSetTemperatureKids;
extern int currentTemperaturesDining;
extern int currentTemperaturesKids;
extern int hysteresis;

#endif /* TEMPERATURECONTROL_H_ */