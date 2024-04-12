/*
 * The library written by Ariel Ohayon
 * The library using the basic matrix keypad with pins 4-7,8-11
 */
#include <Arduino.h>

void Keypad_Init()
{
	DDRD = 0xF0;
	PORTD |= 0xF0;
  
	DDRB &= 0xF0;
	PORTB |= 0x0F;	// Define Pull up resistors
}

char Read_Key()
{
	char keys[4][4]={
		{'1','2','3','A'},
		{'4','5','6','B'},
		{'7','8','9','C'},
		{'*','0','#','D'}};
	
	PORTD |= 0xF0;
	
	for(int i=0; i<4; i++)
	{
		PORTD &= ~(1 << (i+4));
		for(int j=0; j<4; j++)
		{
			if(! (PINB & (1 << (j))) )
			{
				return(keys[i][j]);
			}
		}
		PORTD |= (1 << (i+4));
	}
	return 0;
}

char Wait_Until_Press()
{
	char val = 0;
	while( (val = Read_Key()) == 0 );
	return (val);
}
