#include "motor.h"
#include <avr/io.h>
#include <util/delay.h>

int main(){

	MCUCSR |= (1<<JTD);
	MCUCSR |= (1<<JTD);
	
	DDRB = 0X0F; /*for motor connection*/
	
	DDRC &= ~15; /*As the receiver is connected at 4 pins of PORTC*/
	
	PORTC |= 15; /*So the resistors are pulled up to sense input*/
	
	while(1)
	{
		if(((PINC & 1) == 0) && ((PINC & 2) == 0) && ((PINC & 4) == 0) && ((PINC & 8) == 0))
		{
			stop();
		}
		else if(PINC & 1)
		{	
			PORTB = 1;
			differential_left();
			_delay_ms(100);
		}
		else if(PINC & 2)
		{
			PORTB = 2;
			differential_right();
			_delay_ms(100);
		}
		else if(PINC & 4)
		{
			PORTB = 4;
			backward();
			_delay_ms(100);
		}
		else if(PINC & 8)
		{
			PORTB = 8;
			forward();
			_delay_ms(100);
		}
	}
	return 0;
}