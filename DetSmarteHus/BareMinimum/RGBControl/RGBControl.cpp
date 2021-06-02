#include "RGBControl.h"

//Sets the color of the RGB
void RGBColor(int redValue, int greenValue, int blueValue)
{
	analogWrite(redLEDPin, redValue);
	analogWrite(greenLEDPin, greenValue);
	analogWrite(blueLEDPin, blueValue);
}

//Controls the RGB based on temps
void RGBController()
{
	//If there is to cold
	if (currentTemperaturesDining < (currentSetTemperatureDining - hysteresis))
	{
		RGBColor(0, 0, 255);
	}
	//If there is almost to cold
	else if (currentTemperaturesDining < (currentSetTemperatureDining - (hysteresis / 2)))
	{
		RGBColor(0, 200, 125);
	}
	//If the temperatures are in the allowed area
	else if (currentTemperaturesDining >= (currentSetTemperatureDining - hysteresis) && currentTemperaturesDining <= (currentSetTemperatureDining + hysteresis))
	{
		RGBColor(0, 255, 0);
	}
	//If there is almost to hot
	else if (currentTemperaturesDining > (currentSetTemperatureDining + (hysteresis / 2)))
	{
		RGBColor(200, 125, 0);
	}
	//If there is to hot
	else if (currentTemperaturesDining > (currentSetTemperatureDining + hysteresis))
	{
		RGBColor(255, 0, 0);
	}
}