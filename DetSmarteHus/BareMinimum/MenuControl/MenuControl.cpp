#include "MenuControl.h"

int ns = NULL;

void lcdMenuLoader(int menuStage = 0, int nsv = 0)
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
		
		//Heat main menu
		case 1:
			lcd.setCursor(0, 0);
			lcd.write("A<Fan");
			lcd.setCursor(9 ,0);
			lcd.write("Temps>B");
			lcd.setCursor(0, 1);
			lcd.write("C<Window");
		break;
		
#pragma region Fan Controls Menus
		//Fan Control menu if Auto Mode is on
		case 2:
			lcd.setCursor(0, 0);
			lcd.write("Auto Mode is on!");
			lcd.setCursor(0, 1);
			lcd.write("A<T.Off");
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
			lcd.setCursor(0, 1);
			lcd.write("A<Dec.");
			lcd.setCursor(10, 1);
			lcd.write("Inc.>B");
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
		
		//Set temperature chose room Menu
		case 6:
			lcd.setCursor(0, 0);
			lcd.write("<->Chose Room<->");
			lcd.setCursor(0, 1);
			lcd.write("A<Dining");
			lcd.setCursor(10, 1);
			lcd.write("Kids>B");
		break;
		
		//Set temperatures menu for Dinning room
		case 7:
			lcd.setCursor(0, 0);
			lcd.write("Set temp:"); 
			lcd.print(currentSetTemperatureDining); lcd.write(223);
			lcd.setCursor(0, 1);
			lcd.write("A<Dec.");
			lcd.setCursor(10, 1);
			lcd.write("Inc.>B");
		break;
		
		//Set temperatures menu for Kids room 
		case 8:
			lcd.setCursor(0, 0);
			lcd.write("Set temp:");
			lcd.print(currentSetTemperatureKids); lcd.write(223);
			lcd.setCursor(0, 1);
			lcd.write("A<Dec.");
			lcd.setCursor(10, 1);
			lcd.write("Inc.>B");
		break;
		
		//Current temperatures menu
		case 9:
			lcd.setCursor(0, 0);
			lcd.write("Dining: "); lcd.print(currentTemperaturesDining); lcd.write(223);;
			lcd.setCursor(0, 1);
			lcd.write("Kids:   "); lcd.print(currentTemperaturesKids); lcd.write(223);
		break;
#pragma endregion

#pragma region Windows Menus
		//Window control menu if Auto Mode is on
		case 10:
			lcd.setCursor(0, 0);
			lcd.write("Auto Mode is on!");
			lcd.setCursor(0, 1);
			lcd.write("A<T.Off");
			lcd.setCursor(9, 1);
			lcd.write("Humi.>B");
		break;
		
		//Window control menu if Auto Mode is Off
		case 11:
			lcd.setCursor(0, 0);
			if (WindowIsOpen)
			{
				lcd.write("A<Close window");
			}
			else if (!WindowIsOpen)
			{
				lcd.write("A<Open window");
			}
			lcd.setCursor(0, 1);
			lcd.write("B<T.Auto");
			lcd.setCursor(9, 1);
			lcd.write("Humi.>C");
		break;
		
		//Current humidity windows control menu
		case 12:
			lcd.setCursor(0, 0);
			lcd.write("Humidity:"); lcd.print(currentHumidity); lcd.write("%");
			lcd.setCursor(0, 1);
			lcd.write("A<Set Allowed");
		break;
		
		//Set allowed humidity
		case 13:
			lcd.setCursor(0, 0);
			lcd.write("Al.Humidity:"); lcd.print(currentSetHumidity); lcd.write("%");
			lcd.setCursor(0, 1);
			lcd.write("A<Dec.");
			lcd.setCursor(10, 1);
			lcd.write("Inc.>B");
		break;
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

void menuController(char keyPress)
{
	if (keyPress)
	{
		//If the back to main menu button is pressed
		if (keyPress == '#')
		{
			lcd.clear();
			previousMenuStage = 0;
			currentMenuStage = 0;
		}
		//If the back to last menu button is pressed
		else if (keyPress == '*')
		{
			lcd.clear();
			currentMenuStage = previousMenuStage;
		}
		//If A, B, C or D is pressed
		else if (keyPress == 'A' || keyPress == 'B' || keyPress == 'C' || keyPress == 'D')
		{
			lcd.clear();
			switch (currentMenuStage)
			{
#pragma region Main Menu
				//Menu controls for the main menu
				case 0:
					if (keyPress == 'A')
					{
						currentMenuStage = 1;
					}
					else if (keyPress == 'B')
					{
						currentMenuStage = 0;
					}
				break;
#pragma endregion
#pragma region Heat Menu
				//Menu controls for the heat settings
				case 1:
					if (keyPress == 'A')
					{
						if (fanAutoMode)
						{
							currentMenuStage = 2;
						}
						else
						{
							currentMenuStage = 3;
						}
						previousMenuStage = 1;
					}
					else if (keyPress == 'B')
					{
						currentMenuStage = 5;
						previousMenuStage = 1;
					}
					else if (keyPress == 'C')
					{
						currentMenuStage = 10;
						previousMenuStage = 1;
					}
					
					
				break;
#pragma endregion
#pragma region Fan Menu(Auto Mode On)
				//Menu controls for fan if Auto Mode is on
				case 2:
					if (keyPress == 'A') 
					{
						fanAutoMode = false;
						currentMenuStage = 3;
						previousMenuStage = 1;
						currentFanSpeed = 0;
					}
				break;
#pragma endregion
#pragma region Fan Menu(Auto Mode Off)
				//Menu controls for fan if Auto Mode is off
				case 3:
					if (keyPress == 'A')
					{
						fanAutoMode = true;
						currentMenuStage = 2;
						previousMenuStage = 1;
					}
					else if (keyPress == 'B')
					{
						currentMenuStage = 4;
						previousMenuStage = 3;
					}
				break;
#pragma endregion
#pragma region Fan Speed Menu
				//Menu Controls for the fan speed
				case 4:
				
				if (keyPress == 'A')
				{
					currentFanSpeed -= 5;
					if (currentFanSpeed < 0)
					{
						currentFanSpeed = 0;
					}
				}
				else if (keyPress == 'B')
				{
					currentFanSpeed += 5;
					if (currentFanSpeed > 100)
					{
						currentFanSpeed = 100;
					}
				}
				previousMenuStage = 3;
				break;
#pragma endregion
#pragma region Temperatures Main Menu
				//Main menu controls for temperatures settings
				case 5:
					if (keyPress == 'A')
					{
						currentMenuStage = 6;
						previousMenuStage = 5;
					}
					else if (keyPress == 'B')
					{
						currentMenuStage = 9;
						previousMenuStage = 5;
					}
				break;
#pragma endregion
#pragma region Set Temperatures Chose Room Menu
				//Menu controls for chose room
				case 6:
					if (keyPress == 'A')
					{
						currentMenuStage = 7;
						previousMenuStage = 6;
					}
					else if (keyPress == 'B')
					{
						currentMenuStage = 8;
						previousMenuStage = 6;
					}
				break;
#pragma endregion
#pragma region Set Temperatures Menu(Dining)
				//Menu temperatures controls for the Dining Room
				case 7:
					if (keyPress == 'A')
					{
						currentSetTemperatureDining--;
					}
					else if (keyPress == 'B')
					{
						currentSetTemperatureDining++;
					}
				break;
#pragma endregion
#pragma region Set Temperatures Menu(Kids)
				//Menu temperatures controls for the Kids Room
				case 8:
					if (keyPress == 'A')
					{
						currentSetTemperatureKids--;
					}
					else if (keyPress == 'B')
					{
						currentSetTemperatureKids++;
					}
				break;
#pragma endregion
#pragma region Check Temperatures Menu
				//Menu check temperatures controls
				case 9:
					//This menu can´t do anything special
				break;
#pragma endregion
#pragma region Window Menu(Auto Mode On)
				//Menu window controls if Auto Mode is on
				case 10:
					if (keyPress == 'A')
					{
						windowAutoMode = false;
						currentMenuStage = 11;
					}
					else if (keyPress == 'B')
					{
						currentMenuStage = 12;
						previousMenuStage = 10;
					}
				break;
#pragma endregion
#pragma region Window Controls Menu(Auto Mode Off)
				//Menu window controls if Auto Mode is off
				case 11:
					if (keyPress == 'A')
					{
						if (WindowIsOpen)
						{
							WindowIsOpen = false;
						}
						else if (!WindowIsOpen)
						{
							WindowIsOpen = true;
						}
					}
					else if (keyPress == 'B')
					{
						currentMenuStage = 10;
						windowAutoMode = true;
					}
					else if (keyPress == 'C')
					{
						currentMenuStage = 12;
						previousMenuStage = 11;
					}
				break;
#pragma endregion
#pragma region Check Humidity Menu
				//Check humidity menu controls
				case 12:
					if (keyPress == 'A')
					{
						currentMenuStage = 13;
						previousMenuStage = 12;
					}
				break;
#pragma endregion
#pragma region Set allowed humidity Menu
				//Menu controls for set humidity menu
				case 13:
					if (keyPress == 'A')
					{
						currentSetHumidity -= 5;
						if (currentSetHumidity < 0)
						{
							currentSetHumidity = 0;
						}
					}
					else if (keyPress == 'B')
					{
						currentSetHumidity += 5;
						if (currentSetHumidity > 100)
						{
							currentSetHumidity = 100;
						}
					}
				break;
#pragma endregion
				default:
				break;
			}
		}
	}
	
	lcdMenuLoader(currentMenuStage, ns);	
}