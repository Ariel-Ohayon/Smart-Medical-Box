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
			break;
		case 3:
			option3();
			break;
		case 4:
			option4();
			break;
		case 5:
			option5();
			break;
		case 6:
			option6();
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
	int disp = 0;
	char key = 0;
	while(1)
	{
		if(disp == 0)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("Bleeding Select");
			lcd_setCursor(2,0);
			lcd_print("Press D to open");
			lcd_print_end_line();
		}
		else if(disp == 1)
		{
			door_open();
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("Stopping the");
			lcd_setCursor(2,0);
			lcd_print("bleeding with a");
			lcd_print_end_line();
		}
		else if(disp == 2)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("medical regimen");
			lcd_setCursor(2,0);
			lcd_print("or a medical");
			lcd_print_end_line();
		}
		else if(disp == 3)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("gas pack.");
			lcd_setCursor(2,0);
			lcd_print("Backing up the");
			lcd_print_end_line();
		}
		else if(disp == 4)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("bleeding site");
			lcd_setCursor(2,0);
			lcd_print("with a clean");
			lcd_print_end_line();
		}
		else if(disp == 5)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("pad to prevent");
			lcd_setCursor(2,0);
			lcd_print("further");
			lcd_print_end_line();
		}
		else if(disp == 6)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("infection.");
			lcd_print_end_line();
		}
		else if(disp == 7)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("press # to");
			lcd_setCursor(2,0);
			lcd_print("close the door back menu");
			lcd_print_end_line();
		}
		else if(disp == 8)
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
					disp = 8;
				}
			}
			else if(key == 'D')
			{
				disp++;
				if(disp == 9)
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

void option3()
{
	int disp = 0;
	char key = 0;
	while(1)
	{
		if(disp == 0)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("Fracture");
			lcd_setCursor(2,0);
			lcd_print("Press D to open");
			lcd_print_end_line();
		}
		else if(disp == 1)
		{
			door_open();
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("Support the");
			lcd_setCursor(2,0);
			lcd_print("injured area");
			lcd_print_end_line();
		}
		else if(disp == 2)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("with a medical");
			lcd_setCursor(2,0);
			lcd_print("regimen or a");
			lcd_print_end_line();
		}
		else if(disp == 3)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("medical gas");
			lcd_setCursor(2,0);
			lcd_print("pack.");
			lcd_print_end_line();
		}
		else if(disp == 4)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("#Evaluation");
			lcd_setCursor(2,0);
			lcd_print("suggestion:");
			lcd_print_end_line();
		}
		else if(disp == 5)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("call the EMS");
			lcd_setCursor(2,0);
			lcd_print("or go to a");
			lcd_print_end_line();
		}
		else if(disp == 6)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("first aid");
			lcd_setCursor(2,0);
			lcd_print("center for");
			lcd_print_end_line();
		}
		else if(disp == 7)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("medical");
			lcd_setCursor(2,0);
			lcd_print("treatment as");
			lcd_print_end_line();
		}
		else if(disp == 8)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("soon as");
			lcd_setCursor(2,0);
			lcd_print("possible.");
			lcd_print_end_line();
		}
		else if(disp == 9)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("press # to");
			lcd_setCursor(2,0);
			lcd_print("close the door back menu");
			lcd_print_end_line();
		}
		else if(disp == 10)
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
					disp = 10;
				}
			}
			else if(key == 'D')
			{
				disp++;
				if(disp == 11)
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

void option4()
{
	int disp = 0;
	char key = 0;
	while(1)
	{
		if(disp == 0)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("Deep cut");
			lcd_setCursor(2,0);
			lcd_print("Press D to open");
			lcd_print_end_line();
		}
		else if(disp == 1)
		{
			door_open();
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("Apply pressure");
			lcd_setCursor(2,0);
			lcd_print("to the cut to");
			lcd_print_end_line();
		}
		else if(disp == 2)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("stop the");
			lcd_setCursor(2,0);
			lcd_print("bleeding and");
			lcd_print_end_line();
		}
		else if(disp == 3)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("keep the area");
			lcd_setCursor(2,0);
			lcd_print("clean.");
			lcd_print_end_line();
		}
		else if(disp == 4)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("Clean the cut");
			lcd_setCursor(2,0);
			lcd_print("with hot soapy");
			lcd_print_end_line();
		}
		else if(disp == 5)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("water, if the");
			lcd_setCursor(2,0);
			lcd_print("cut is too deep");
			lcd_print_end_line();
		}
		else if(disp == 6)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("drip hydrogen");
			lcd_setCursor(2,0);
			lcd_print("peroxide to");
			lcd_print_end_line();
		}
		else if(disp == 7)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("stop the");
			lcd_setCursor(2,0);
			lcd_print("bleeding and");
			lcd_print_end_line();
		}
		else if(disp == 8)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("prevent");
			lcd_setCursor(2,0);
			lcd_print("infection, then");
			lcd_print_end_line();
		}
		else if(disp == 9)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("cover it with a");
			lcd_setCursor(2,0);
			lcd_print("wound plaster.");
			lcd_print_end_line();
		}
		else if(disp == 10)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("press # to");
			lcd_setCursor(2,0);
			lcd_print("close the door back menu");
			lcd_print_end_line();
		}
		else if(disp == 11)
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
					disp = 11;
				}
			}
			else if(key == 'D')
			{
				disp++;
				if(disp == 12)
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

void option5()
{
	int disp = 0;
	char key = 0;
	while(1)
	{
		if(disp == 0)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("Asthma attack");
			lcd_setCursor(2,0);
			lcd_print("Press D to open");
			lcd_print_end_line();
		}
		else if(disp == 1)
		{
			door_open();
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("Let the person");
			lcd_setCursor(2,0);
			lcd_print("breathe easily");
			lcd_print_end_line();
		}
		else if(disp == 2)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("and be at rest.");
			lcd_setCursor(2,0);
			lcd_print("If he has");
			lcd_print_end_line();
		}
		else if(disp == 3)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("trouble");
			lcd_setCursor(2,0);
			lcd_print("breathing, help");
			lcd_print_end_line();
		}
		else if(disp == 4)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("him use his");
			lcd_setCursor(2,0);
			lcd_print("inhaler or a");
			lcd_print_end_line();
		}
		else if(disp == 5)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("nebulizer.");
			lcd_setCursor(2,0);
			lcd_print("#If the attack");
			lcd_print_end_line();
		}
		else if(disp == 6)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("does not");
			lcd_setCursor(2,0);
			lcd_print("improve, the");
			lcd_print_end_line();
		}
		else if(disp == 7)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("assessment");
			lcd_setCursor(2,0);
			lcd_print("suggests the");
			lcd_print_end_line();
		}
		else if(disp == 8)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("following:");
			lcd_setCursor(2,0);
			lcd_print("call the");
			lcd_print_end_line();
		}
		else if(disp == 9)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("emergency");
			lcd_setCursor(2,0);
			lcd_print("center or take");
			lcd_print_end_line();
		}
		else if(disp == 10)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("the injured");
			lcd_setCursor(2,0);
			lcd_print("person to the");
			lcd_print_end_line();
		}
		else if(disp == 11)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("nearest");
			lcd_setCursor(2,0);
			lcd_print("hospital.");
			lcd_print_end_line();
		}
		else if(disp == 12)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("press # to");
			lcd_setCursor(2,0);
			lcd_print("close the door back menu");
			lcd_print_end_line();
		}
		else if(disp == 13)
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
					disp = 13;
				}
			}
			else if(key == 'D')
			{
				disp++;
				if(disp == 14)
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

void option6()
{
	int disp = 0;
	char key = 0;
	while(1)
	{
		if(disp == 0)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("Allergy attack");
			lcd_setCursor(2,0);
			lcd_print("Press D to open");
			lcd_print_end_line();
		}
		else if(disp == 1)
		{
			door_open();
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("If a person is");
			lcd_setCursor(2,0);
			lcd_print("having an");
			lcd_print_end_line();
		}
		else if(disp == 2)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("allergic attack");
			lcd_setCursor(2,0);
			lcd_print("and has had one");
			lcd_print_end_line();
		}
		else if(disp == 3)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("one in the past");
			lcd_setCursor(2,0);
			lcd_print("help them use");
			lcd_print_end_line();
		}
		else if(disp == 4)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("epinephrine or");
			lcd_setCursor(2,0);
			lcd_print("another drug");
			lcd_print_end_line();
		}
		else if(disp == 5)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("they are using.");
			lcd_print_end_line();
		}
		else if(disp == 6)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("#If the attack");
			lcd_setCursor(2,0);
			lcd_print("does not");
			lcd_print_end_line();
		}
		else if(disp == 7)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("improve, the");
			lcd_setCursor(2,0);
			lcd_print("assessment");
			lcd_print_end_line();
		}
		else if(disp == 8)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("suggests the");
			lcd_setCursor(2,0);
			lcd_print("following: call");
			lcd_print_end_line();
		}
		else if(disp == 9)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("an amblunce or");
			lcd_setCursor(2,0);
			lcd_print("take the");
			lcd_print_end_line();
		}
		else if(disp == 10)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("injured person");
			lcd_setCursor(2,0);
			lcd_print("to the nearest");
			lcd_print_end_line();
		}
		else if(disp == 11)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("hospital.");
			lcd_print_end_line();
		}
		else if(disp == 12)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("press # to");
			lcd_setCursor(2,0);
			lcd_print("close the door back menu");
			lcd_print_end_line();
		}
		else if(disp == 13)
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
					disp = 13;
				}
			}
			else if(key == 'D')
			{
				disp++;
				if(disp == 14)
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
