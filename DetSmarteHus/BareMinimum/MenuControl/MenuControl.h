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

extern int currentFanSpeed;

void lcdMenuLoader(int menuStage);

#endif /* MENUCONTROL_H_ */