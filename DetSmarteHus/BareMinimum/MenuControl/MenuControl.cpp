#include "MenuControl.h"

void lcdMenuLoader(int menuStage = 0, int ns = 0)
{
	switch (menuStage)
	{
		//Main menu
		case 0:
			lcd.setCursor(0, 0);
			lcd.write("<>Chose Option<>");
			lcd.setCursor(0, 1);
			lcd.write("A<Heat");
			lcd.setCursor(8, 1);
			lcd.write("Lights>B");
		break;
		
#pragma region Heat Menus
		//Heat menu
		case 1:
			lcd.setCursor(0, 0);
			lcd.write("A<Fan");
			lcd.setCursor(9 ,0);
			lcd.write("Temps>B");
			lcd.setCursor(0, 1);
			lcd.write("C<Window");
			lcd.setCursor(10, 1);
			lcd.write("Back>D");
		break;
		
#pragma region Fan Controls Menus
		//Fan Control menu if Auto Mode is on
		case 2:
			lcd.setCursor(0, 0);
			lcd.write("Auto Mode is on!");
			lcd.setCursor(0, 1);
			lcd.write("A<T.Off");
			lcd.setCursor(10, 1);
			lcd.write("Back>B");
		break;
		
		//Fan Control menu if Auto Mode is off
		case 3:
			lcd.setCursor(0, 0);
			lcd.write("<>Fan Controls<>");
			lcd.setCursor(0, 1);
			lcd.write("A<T.Auto");
			lcd.setCursor(9, 1);
			lcd.write("Speed>B");
		break;
		
		//Fan Speed Control menu
		case 4:
			lcd.setCursor(0, 0);
			lcd.write("Speed:"); lcd.print(currentFanSpeed); lcd.write("%");
			lcd.setCursor(10, 0);
			lcd.write("Done>A");
			lcd.setCursor(0, 1);
			lcd.write("B<Dec.");
			lcd.setCursor(10, 1);
			lcd.write("Inc.>C");
		break;
		
#pragma endregion
		
#pragma region Temperature Menus
		//Temperature Menu
		case 5:
			lcd.setCursor(0, 0);
			lcd.write("<>Temperatures<>");
			lcd.setCursor(0, 1);
			lcd.write("A<Set");
			lcd.setCursor(9, 1);
			lcd.write("Check>B");
		break;
		
		//Set temperature Menu
		case 6:
			lcd.setCursor(0, 0);
			lcd.write("<->Chose Room<->");
			lcd.setCursor(0, 1);
			lcd.write("A<Dining");
			lcd.setCursor(10, 1);
			lcd.write("Kids>B");
		break;
		
		//Set temperatures for room Menu
		//ns1 = Dining Room, ns2 = Kids Room
		case 7:
			lcd.setCursor(0, 0);
			lcd.write("Set:"); 
			if (ns == 1)
			{
				lcd.print(currentSetTemperatureDining); 
			}
			else if (ns == 2)
			{
				lcd.print(currentSetTemperatureKids);
			}
			else
			{
				lcd.write("??");
			}
			lcd.write(223);
			lcd.setCursor(10, 0);
			lcd.write("Done>A");
			lcd.setCursor(0, 1);
			lcd.write("B<Dec.");
			lcd.setCursor(10, 1);
			lcd.write("Inc.>C");
		break;
		
		//Current temperatures menu
		case 8:
			lcd.setCursor(0, 0);
			lcd.write("Dining:"); lcd.print(currentTemperaturesDining); lcd.write(223);
			lcd.setCursor(10, 0);
			lcd.write("Done>A");
			lcd.setCursor(0, 1);
			lcd.write("Kids:  "); lcd.print(currentTemperaturesKids); lcd.write(223);
			lcd.setCursor(11, 1);
			lcd.write("Set>B");
		break;
#pragma endregion

#pragma region Windows Menus
		//Window menu if Auto Mode is on
		case 9:
			lcd.setCursor(0, 0);
			lcd.write("Auto Mode is on!");
			lcd.setCursor(0, 1);
			lcd.write("A<T.Off");
			lcd.setCursor(10, 1);
			lcd.write("Back>B");
		break;
		
		//Window control menu
		//ns1 = window is open, ns2 = window is closed
		case 10:
			lcd.setCursor(0, 0);
			lcd.write("<>Window Cont.<>");
			lcd.setCursor(0, 1);
			if (ns == 1)
			{
				lcd.write("A<Close");
			}
			else if (ns == 2)
			{
				lcd.write("A<Open");
			}
			lcd.setCursor(10, 1);
			lcd.write("Back>B");
		break;
#pragma endregion

#pragma endregion
		
		//Error menu
		default:
			lcd.setCursor(0, 0);
			lcd.write("Unknown Stage!");
			lcd.setCursor(0, 1);
			lcd.write("Try \"Reset\"!!!");
		break;
	}
}