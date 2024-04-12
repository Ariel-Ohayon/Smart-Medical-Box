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
	lcd_init();
	lcd_clear();
	lcd_setCursor(1,1);
	lcd_print("Smart Medical");
	lcd_setCursor(2,7);
	lcd_print("Box");
	/* lcd_data(up);
	   lcd_data(down); */
	Keypad_Init();
	gate.attach(gate_pin);
	gate_close();
	
	lcd_clear();
	lcd_setCursor(1,0);
	lcd_print("For menu press #");
	while(Read_Key() != '#');
}

void loop() {
	lcd_clear();
	lcd_setCursor(1,4);
	lcd_print("Menu");
	lcd_setCursor(2,0);
	lcd_print("1.Tahboshet");
	lcd_print_end_line();
	while(1);
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
	lcd_setCursor(1,13);
	lcd_print("|A");
	lcd_data(up);
	lcd_setCursor(2,13);
	lcd_print("|D");
	lcd_data(down);
}