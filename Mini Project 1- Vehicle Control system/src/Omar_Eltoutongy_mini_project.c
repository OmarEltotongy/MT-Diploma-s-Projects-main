/*
 ============================================================================
 Name        : Omar_Eltoutongy_mini_project.c
 Author      : Omar Eltoutongy
 Version     :
 Copyright   : Vehicle Control system from Omar Eltoutongy_
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void Vehicle_state(char option);
void Sensor_set_Menu(char option);
void advnced_display(short Engine_state,short AC_State,int vehicle_speed,int temp_value,short Engine_Temperature_Controller_State,int Engine_temp_value);

int main(void)
{
	//for scanf
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	//variables
	char option=0;
	char sensor_menu=0;

	//sensor values
	char light_sensor=0;
	char temp_sensor=0;
	char engine_temp_sensor=0;

	//data happened depends on sensor values
	int temp_value=0;
	int vehicle_speed=0;
	int Engine_temp_value=0;

	short AC_State=0;
	short Engine_Temperature_Controller_State=0;
	short Engine_state=0;

	//Ask the user if he/she wants
	printf("Please enter what u want:\nA. Turn on the vehicle engine.\n"
			"B. Turn off the vehicle engine.\nC. Quit the system.\n");

	scanf(" %c",&option);
	option = toupper(option); //to check one condition only
	//execute what he wants
	Vehicle_state(option); //function to print state as it will be repeated
	while(option !='C')
	{
		//for req3
		if(option =='B')
		{
			printf("Please enter what u want:\nA. Turn on the vehicle engine.\n"
					"B. Turn off the vehicle engine.\nC. Quit the system.\n");
			scanf(" %c",&option);
			option = toupper(option);
			Vehicle_state(option);
			if(option=='C')
				break;  //breaking the loop if he wants to quit
		}
		else if(option=='A')
		{
			do{ //select do while to at least do it once
				Engine_state=1;
				printf("Displaying Sensors set menu: \n\n");
				printf("a. Turn off the engine\n"
						"b. Set the traffic light color\n"
						"c. Set the room temperature (Temperature Sensor)\n"
						"d. Set the engine temperature (Engine Temperature Sensor)\n");
				scanf(" %c",&sensor_menu);
				sensor_menu=toupper(sensor_menu);

				Sensor_set_Menu(sensor_menu); //displaying the state of the sensor menu

				if(sensor_menu=='A')
				{
					option='B';
					Engine_state=0;
				}
				else if(sensor_menu=='B')
				{
					printf("This is sensor read value input for light: ");
					scanf(" %c",&light_sensor);
					if(light_sensor=='G')
					{
						printf("Setting the vehicle speed to 100 km/hr\n");
						vehicle_speed=100;
					}
					else if(light_sensor=='O')
					{
						printf("Setting the vehicle speed to 30 km/hr\n");
						vehicle_speed=30;
						//for speed =30;

					}
					else if(light_sensor=='R')
					{
						printf("Setting the vehicle speed to 0 km/hr\n");
						vehicle_speed=0;
					}
				}
				else if(sensor_menu=='C')
				{
					printf("This is sensor read value input for temperature: ");
					scanf(" %c",&temp_sensor);

					if((temp_sensor>0) && (temp_sensor<10))
					{
						printf("Turning AC ON\n");
						AC_State=1;
						temp_value=20;

					}
					else if(temp_sensor>30)
					{
						printf("Turning AC ON\n");
						AC_State=1;
						temp_value=20;
					}
					else
					{
						printf("Turning AC OFF\n");
						AC_State=0;
					}

				}
				else if(sensor_menu=='D')
				{
					printf("This is sensor read value input for temperature: ");
					scanf(" %c",&engine_temp_sensor);
					if(engine_temp_sensor<100)
					{
						printf("Engine Temperature Controller is ON\n");
						Engine_Temperature_Controller_State=1;
						Engine_temp_value=125;
					}
					else if(engine_temp_sensor>150)
					{
						printf("Engine Temperature Controller is ON\n");
						Engine_Temperature_Controller_State=1;
						Engine_temp_value=125;
					}
					else
					{
						printf("Engine Temperature Controller is OFF\n");
						Engine_Temperature_Controller_State=0;
					}
				}
				if(vehicle_speed==30) //with every loop the temp will raise unless if we need to raise just once we could move the block to the if condition
				{
					AC_State=1;
					temp_value=((temp_value*5)/4)+1;
					Engine_Temperature_Controller_State=1;
					Engine_temp_value=((Engine_temp_value*5)/4)+1;
					}

					advnced_display(Engine_state,AC_State,vehicle_speed,temp_value,Engine_Temperature_Controller_State,Engine_temp_value);

				}while(sensor_menu != 'A'); //to check if he chooses turning off


			}


		}
		printf("Thank u for dealing with Me <3\n");
	}
	//for vehicle state
	void Vehicle_state(char option)
	{
		if(option=='A')
		{
			printf("System State is: The vehicle engine is ON\n");
		}
		else if(option=='B')
		{
			printf("System State is: The vehicle engine is OFF\n");
		}
		else if(option=='C')
		{
			printf("System State is: Out  of system\n");
		}
	}
	//for sensor menu
	void Sensor_set_Menu(char option)
	{
		if(option=='A')
		{
			printf("System State is: The vehicle engine is OFF\n");
		}
		else if(option=='B')
		{
			printf("System State is: Setting the traffic light color\n");
		}
		else if(option=='C')
		{
			printf("System State is: Setting the room temperature\n");
		}
		else if(option=='D')
		{
			printf("System State is: Setting the engine temperature\n");
		}
	}
	// after applying the needs of the customer
	void advnced_display(short Engine_state,short AC_State,int vehicle_speed,int temp_value,short Engine_Temperature_Controller_State,int Engine_temp_value)
	{
		printf("Engine State: %hi\n",Engine_state);
		printf("AC State: %hi\n",AC_State);
		printf("Vehicle Speed: %i\n",vehicle_speed);
		printf("Temperature Value: %i\n",temp_value);
		printf("Engine Temperature Controller State: %hi\n",Engine_Temperature_Controller_State);
		printf("Engine Temperature Value: %i\n\n",Engine_temp_value);

	}
