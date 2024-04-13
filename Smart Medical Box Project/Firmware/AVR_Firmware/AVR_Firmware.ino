#define up 0
#define down 1
#define gate_pin 12
#include "MyKeypad.h"
#include "LCD_I2C.h"
#include <Servo.h>

Servo gate;

// -- Functions -- //
void gate_close();
void gate_open();
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
	gate.attach(gate_pin);
	gate_close();
	
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
			delay(3000);
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
	}
}

void option1()
{
	lcd_clear();
	lcd_setCursor(1,0);
	lcd_print("Option 1");
	lcd_setCursor(2,0);
	lcd_print("Selected");
}

void option2()
{
	lcd_clear();
	lcd_setCursor(1,0);
	lcd_print("Option 2");
	lcd_setCursor(2,0);
	lcd_print("Selected");
}

void option3()
{
	lcd_clear();
	lcd_setCursor(1,0);
	lcd_print("Option 3");
	lcd_setCursor(2,0);
	lcd_print("Selected");
}

void option4()
{
	lcd_clear();
	lcd_setCursor(1,0);
	lcd_print("Option 4");
	lcd_setCursor(2,0);
	lcd_print("Selected");
}

void option5()
{
	lcd_clear();
	lcd_setCursor(1,0);
	lcd_print("Option 5");
	lcd_setCursor(2,0);
	lcd_print("Selected");
}

void gate_open()
{
	gate.write(180);
}

void gate_close()
{
	gate.write(90);
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
			lcd_print("1.Option 1");
			lcd_print_end_line();
		}
		else if(disp == 1)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("2.Option 2");
			lcd_setCursor(2,0);
			lcd_print("3.Option 3");
			lcd_print_end_line();
		}
		else if(disp == 2)
		{
			lcd_clear();
			lcd_setCursor(1,0);
			lcd_print("4.Option 4");
			lcd_setCursor(2,0);
			lcd_print("5.Option 5");
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
					disp = 2;
				}
			}
			else if(key == 'D')
			{
				disp++;
				if(disp == 3)
				{
					disp = 0;
				}
			}
			else if(key >= '1' && key <= '5')
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
