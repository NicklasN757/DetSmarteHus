/*
 * TemperatureControl.h
 *
 * Created: 28-05-2021 09:47:22
 *  Author: nick4978
 */ 


#ifndef TEMPERATURECONTROL_H_
#define TEMPERATURECONTROL_H_

#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

extern DHT dht;

extern int currentSetTemperatureDining;
extern int currentSetTemperatureKids;
extern int currentTemperaturesDining;
extern int currentTemperaturesKids;
extern int hysteresis;

float calculateTemp(int sensorValue);
void GetCurrentTemperature();

#endif /* TEMPERATURECONTROL_H_ */