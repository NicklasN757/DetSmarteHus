#include "WindowControl.h"

void WindowController()
{
	//Check if the Humidity is okay and open or closed the window
	if (windowAutoMode)
	{
		//Check if the Humidity is too low and sets the windows to "closed"
		if (currentHumidity < (currentSetHumidity - humidityhysteresis))
		{
			WindowIsOpen = false;
			servoMotor.write(180);
		}
		//Sets the window to "open"
		else
		{
			WindowIsOpen = true;
			servoMotor.write(0);
		}
	}
}

