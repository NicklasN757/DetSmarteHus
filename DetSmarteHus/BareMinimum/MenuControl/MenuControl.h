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
#include <Servo.h>

extern LiquidCrystal lcd;

//Servo variables
extern Servo servoMotor;

//Menu Stages variables
extern int currentMenuStage;
extern int previousMenuStage;

//Keypad pressed key variable
extern char pressedKey;

//Fan variables
extern int currentFanSpeed;
extern bool fanAutoMode;

//Temperature and humidity variables
extern int currentSetTemperatureDining;
extern int currentSetTemperatureKids;
extern int currentTemperaturesDining;
extern int currentTemperaturesKids;
extern int currentHumidity;
extern int currentSetHumidity;

//Window variables
extern bool WindowIsOpen;
extern bool windowAutoMode;

//Sets the menu stage
void menuController(char keyPress);

#endif /* MENUCONTROL_H_ */