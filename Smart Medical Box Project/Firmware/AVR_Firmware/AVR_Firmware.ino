#define up 0
#define down 1
#define door_pin 12
#include "MyKeypad.h"
#include "LCD_I2C.h"
#include <Servo.h>

Servo door;

// -- Functions -- //
void door_close();
void door_open();
// -- Functions -- //

void setup() {
	Serial.begin(9600);
	lcd_init();
	lcd_clear();
	lcd_setCursor(1,1);
	lcd_print("Smart Medical");
	lcd_setCursor(2,7);
	lcd_print("Box");
	Keypad_Init();
	door.attach(door_pin);
	door_close();
	
	lcd_clear();
	lcd_setCursor(1,0);
	lcd_print("For menu press #");
	while(Read_Key() != '#');
}

void loop()
{
	char option = menu();
	switch(option)
	{
		case 1:
			option1();
			break;
		case 2:
			option2();
			delay(3000);
			break;
		case 3:
			option3();
			delay(3000);
			break;
		case 4:
			option4();
			delay(3000);
			break;
		case 5:
			option5();
			delay(3000);
			break;
		case 6:
			option6();
			delay(3000);
			break;
	}
	door_close();
}

void option1()
{
	int disp = 0;
	char key = 0;
	while(1)
	{
		if(disp == 0)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("Burn Selected");
			lcd_setCursor(2,0);
			lcd_print("Press D to open");
			lcd_print_end_line();
		}
		else if(disp == 1)
		{
			door_open();
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("Extinguishing");
			lcd_setCursor(2,0);
			lcd_print("the fire or");
			lcd_print_end_line();
		}
		else if(disp == 2)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("heat source,");
			lcd_setCursor(2,0);
			lcd_print("and irradiating");
			lcd_print_end_line();
		}
		else if(disp == 3)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("the burn with");
			lcd_setCursor(2,0);
			lcd_print("cold water (but");
			lcd_print_end_line();
		}
		else if(disp == 4)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("not too cold)");
			lcd_setCursor(2,0);
			lcd_print("for 10-20");
			lcd_print_end_line();
		}
		else if(disp == 5)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("minutes to");
			lcd_setCursor(2,0);
			lcd_print("relieve the");
			lcd_print_end_line();
		}
		else if(disp == 6)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("pain and");
			lcd_setCursor(2,0);
			lcd_print("prevent further");
			lcd_print_end_line();
		}
		else if(disp == 7)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("damage to the");
			lcd_setCursor(2,0);
			lcd_print("skin.");
			lcd_print_end_line();
		}
		else if(disp == 8)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("Then put Biafin");
			lcd_setCursor(2,0);
			lcd_print("ointment on the");
			lcd_print_end_line();
		}
		else if(disp == 9)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("burn area as");
			lcd_setCursor(2,0);
			lcd_print("written on the");
			lcd_print_end_line();
		}
		else if(disp == 10)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("back of the");
			lcd_setCursor(2,0);
			lcd_print("ointment.");
			lcd_print_end_line();
		}
		else if(disp == 11)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("press # to");
			lcd_setCursor(2,0);
			lcd_print("close the door back menu");
			lcd_print_end_line();
		}
		else if(disp == 12)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("and back menu");
			lcd_print_end_line();
		}
		while(key == 0)
		{
			key = Read_Key();
			if(key == 'A')
			{
				disp--;
				if(disp < 0)
				{
					disp = 12;
				}
			}
			else if(key == 'D')
			{
				disp++;
				if(disp == 13)
				{
					disp = 0;
				}
			}
			else if(key == '#')
			{
				return 0;
			}
			else
			{
				key = 0;
			}
		}
		key = 0;
	}
}

void option2()
{
/*
	Bleeding
	
	Stopping the bleeding with a medical regimen or
	a medical gas pack.
	Backing up the bleeding site with a clean pad to
	prevent further infection.
*/
	lcd_clear();
	lcd_setCursor(1,0);
	lcd_print("Bleeding");
	lcd_setCursor(2,0);
	lcd_print("Selected");
}

void option3()
{
/*
	Fracture
	
	Support the injured area with a medical regimen or a
	medical gas pack.
	# Evaluation suggestion: Call the EMS or go to a first
	aid center for medical treatment as soon as possible.
*/
	lcd_clear();
	lcd_setCursor(1,0);
	lcd_print("Fracture");
	lcd_setCursor(2,0);
	lcd_print("Selected");
}

void option4()
{
/*
	Deep cut
	
	Apply pressure to the cut to stop the bleeding and keep
	the area clean.
	Clean the cut with hot soapy water, if the cut is too
	deep drip hydrogen peroxide to stop the bleeding and
	prevent infection, then cover it with a wound plaster.
*/
	lcd_clear();
	lcd_setCursor(1,0);
	lcd_print("Deep cut");
	lcd_setCursor(2,0);
	lcd_print("Selected");
}

void option5()
{

/*
	Asthma attack
	
	Let the person breathe easily and be at rest.
	If he has trouble breathing, help him use his inhaler
	or a nebulizer.
	# If the attack does not improve, the assessment
	suggests the following: call the emergency center or take
	the injured person to the nearest hospital.
*/
	lcd_clear();
	lcd_setCursor(1,0);
	lcd_print("Asthma attack");
	lcd_setCursor(2,0);
	lcd_print("Selected");
}

void option6()
{

/*
	Allergy attack
	
	
	If a person is having an allergic attack, and has had one
	in the past, help them use epinephrine or another drug
	they are using.
	# If the attack does not improve, the assessment suggests
	the following: call an ambulance or take the injured
	person to the nearest hospital
*/
	lcd_clear();
	lcd_setCursor(1,0);
	lcd_print("Allergy attack");
	lcd_setCursor(2,0);
	lcd_print("Selected");
}

void door_open()
{
	door.write(180);
}

void door_close()
{
	door.write(90);
}

void lcd_print_end_line()
{
	lcd_setCursor(1,15);
	lcd_data(up);
	lcd_setCursor(2,15);
	lcd_data(down);
}

char menu()
{
	int disp = 0;
	char key = 0;
	while(1)
	{
		if(disp == 0)
		{
			lcd_clear();
			lcd_setCursor(1,5);
			lcd_print("Menu");
			lcd_setCursor(2,0);
			lcd_print("1.Burn");
			lcd_print_end_line();
		}
		else if(disp == 1)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("2.Bleeding");
			lcd_setCursor(2,0);
			lcd_print("3.Fracture");
			lcd_print_end_line();
		}
		else if(disp == 2)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("4.Deep cut");
			lcd_setCursor(2,0);
			lcd_print("5.Asthma attack");
			lcd_print_end_line();
		}
		else if(disp == 3)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("6.Allergy");
			lcd_print_end_line();
		}
		while(key == 0)
		{
			key = Read_Key();
			if(key == 'A')
			{
				disp--;
				if(disp < 0)
				{
					disp = 3;
				}
			}
			else if(key == 'D')
			{
				disp++;
				if(disp == 4)
				{
					disp = 0;
				}
			}
			else if(key >= '1' && key <= '6')
			{
				return (key - '0');
			}
			else
			{
				key = 0;
			}
		}
		key = 0;
	}
}
