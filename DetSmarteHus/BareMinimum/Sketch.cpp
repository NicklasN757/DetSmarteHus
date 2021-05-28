#include <Arduino.h>
#include <Servo.h>
#include <LiquidCrystal.h>
#include <Keypad.h>

#include "MenuControl/MenuControl.h"

int motorPin = 6;
int motorPotentiometerPin = A10;
int thermistorPin = A11;

int potentiometerValue;
int currentMenuStage;

#pragma region FanControlSettings
	//Speed in %
	int currentFanSpeed = 0;
	//Fan Auto Mode
	bool fanAutoMode = true;
#pragma endregion

#pragma region TemperatureControlSettings
	int currentSetTemperatureDining = 22;
	int currentSetTemperatureKids = 20;
	int currentTemperaturesDining;
	int currentTemperaturesKids;
	int hysteresis = 4;
#pragma endregion

#pragma region LCD setup
//LCD is connected to these pins
const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#pragma endregion

#pragma region Kepad setup
//Row count
const byte Rows = 4;
//Cols count

const byte Cols = 4;

//Keypad map 
char Keys[Rows][Cols] = {
	{'1', '2', '3', 'A'},
	{'4', '5', '6', 'B'},
	{'7', '8', '9', 'C'},
	{'*', '0', '#', 'D'}
};

// Connected keypad ROW0, ROW1, ROW2 and ROW3 to these pins.
byte rowPins[Rows] = {29, 28, 27, 26};
// Connected keypad COL0, COL1 and COL2 to these pins.
byte colPins[Cols] = {25, 24, 23, 22};
	
Keypad kpd = Keypad(makeKeymap(Keys), rowPins, colPins, Rows, Cols);
#pragma endregion

float calculateTemp(int sensorValue)
{
	float temp = log(10000.0 * (1024.0 / sensorValue - 1));
	float tempK = 1/(0.001129148 + (0.000234125 + (0.0000000876741 * temp * temp)) * temp);
	float tempC = tempK - 273.15;
	return tempC;
}

int calculateMotorSpeed(int potentiometerValue)
{
	return potentiometerValue / 4;
}

void setup() 
{
	lcd.begin(16, 2);
	lcdMenuLoader(3);
}

void loop() 
{
	
}
