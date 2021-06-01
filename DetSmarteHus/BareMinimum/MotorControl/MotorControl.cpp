#include "MotorControl.h"

//Calculate Motor Speed from potentiometerValue
int calculateMotorSpeed(int potentiometerValue)
{
	return potentiometerValue / 4;
}

//Calculate Motor Speed from procent
int calculateMotorSpeedFromProcent(int procent)
{
	return (255 / 100) * procent; 
}

//Sets Motor speed
void setMotorSpeed()
{
	if (fanAutoMode)
	{
		//If there is to cold
		if (currentTemperaturesDining < (currentSetTemperatureDining - hysteresis))
		{
			currentFanSpeed = 0;
		}
		//If there is almost to cold
		else if (currentTemperaturesDining < (currentSetTemperatureDining - (hysteresis / 2)))
		{
			analogWrite(motorPin, calculateMotorSpeedFromProcent(50));
			currentFanSpeed = 25;
		}
		//If the temperatures are in the allowed area
		else if (currentTemperaturesDining >= (currentSetTemperatureDining - hysteresis) && currentTemperaturesDining <= (currentSetTemperatureDining + hysteresis))
		{
			currentFanSpeed = 50;
		}
		//If there is almost to hot
		else if (currentTemperaturesDining > (currentSetTemperatureDining + (hysteresis / 2)))
		{
			currentFanSpeed = 75;
		}
		//If there is to hot
		else if (currentTemperaturesDining > (currentSetTemperatureDining + hysteresis))
		{
			currentFanSpeed = 100;
		}
	}
	analogWrite(motorPin, calculateMotorSpeedFromProcent(currentFanSpeed));
}