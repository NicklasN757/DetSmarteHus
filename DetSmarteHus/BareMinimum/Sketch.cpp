#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Keypad.h>
#include <Servo.h>

#include "MenuControl/MenuControl.h"
#include "TemperatureControl/TemperatureControl.h"
#include "MotorControl/MotorControl.h"
#include "WindowControl/WindowControl.h"
#include "RGBControl/RGBControl.h"

int currentMenuStage;
int previousMenuStage = 0;
char pressedKey;

#pragma region FanControlSettings
	//Pin number
	const int motorPin = 6;
	//Speed in %
	int currentFanSpeed = 0;
	//Fan Auto Mode
	bool fanAutoMode = false;
#pragma endregion

#pragma region TemperatureControlSettings
	//Set temperatures for the dining room
	int currentSetTemperatureDining = 24;
	//Set temperatures for the kids room
	int currentSetTemperatureKids = 22;
	//Current temperatures
	int currentTemperaturesDining;
	int currentTemperaturesKids;
	//Hysteresis
	int hysteresis = 3;
	//Current humidity
	int currentHumidity;
	//Set humidity
	int currentSetHumidity = 40;
	//Humidity hysteresis
	int humidityhysteresis = 10;
#pragma endregion

#pragma region WindowControlSettings
	//Bool to check if windows is open
	bool WindowIsOpen = false;
	//Windows Auto Mode
	bool windowAutoMode = true;
#pragma endregion

#pragma region LCD setup
//LCD is connected to these pins
//const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
const int rs = 37, en = 36, d4 = 32, d5 = 34, d6 = 33, d7 = 35;

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

#pragma region DHT11 sensor setup
#define DHTTYPE DHT11
#define DHTPIN 13

DHT dht(DHTPIN, DHTTYPE);
#pragma endregion

#pragma region Servo Setup
	//Pin Number
	const int servoMotorPin = 8;
	//Servo object
	Servo servoMotor;
#pragma endregion

#pragma region RGB Setup
	const int redLEDPin = 2;
	const int greenLEDPin = 3;
	const int blueLEDPin = 4;
#pragma endregion

void setup() 
{
	pinMode(redLEDPin, OUTPUT);
	pinMode(greenLEDPin, OUTPUT);
	pinMode(blueLEDPin, OUTPUT);
	lcd.begin(16, 2);
	dht.begin();
	servoMotor.attach(servoMotorPin);
}

void loop() 
{
	GetCurrentTemperatureAndHumidity();
	setMotorSpeed();
	WindowController();
	RGBController();
	pressedKey = kpd.getKey();
	menuController(pressedKey);
	pressedKey = NULL;
}
