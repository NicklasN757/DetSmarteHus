#include "MotorControl.h"

int calculateMotorSpeed(int potentiometerValue)
{
	return potentiometerValue / 4;
}