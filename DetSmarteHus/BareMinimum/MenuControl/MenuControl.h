/*
 * MenuControl.h
 *
 * Created: 28-05-2021 09:05:42
 *  Author: nick4978
 */ 


#ifndef MENUCONTROL_H_
#define MENUCONTROL_H_

#include <Arduino.h>
#include <LiquidCrystal.h>

extern LiquidCrystal lcd;

//Fan variables
extern int currentFanSpeed;

//Temperature and humidity variables
extern int currentSetTemperatureDining;
extern int currentSetTemperatureKids;
extern int currentTemperaturesDining;
extern int currentTemperaturesKids;
extern int currentHumidity;
extern int currentSetHumidity;

//Window variables
extern bool WindowIsOpen;

//Loads the right menu based on menuStage
void lcdMenuLoader(int menuStage, int ns);

#endif /* MENUCONTROL_H_ */