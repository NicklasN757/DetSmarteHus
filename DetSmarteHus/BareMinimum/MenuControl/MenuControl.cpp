#include "MenuControl.h"

void lcdMenuLoader(int menuStage = 0)
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
		lcd.write("C<Windows");
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
		case 5:
		lcd.setCursor(0, 0);
		lcd.write("");
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