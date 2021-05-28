#include "TemperatureControl.h"

float calculateTemp(int sensorValue)
{
	float temp = log(10000.0 * (1024.0 / sensorValue - 1));
	float tempK = 1/(0.001129148 + (0.000234125 + (0.0000000876741 * temp * temp)) * temp);
	float tempC = tempK - 273.15;
	return tempC;
}