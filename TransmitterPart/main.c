#include <avr/io.h>

int main()
{
	
	MCUCSR |= (1<<JTD);
	MCUCSR |= (1<<JTD);
	
	int x,y,z;
	
	DDRA = 0X00; /*to use input pins*/
	DDRC = 0XFF; /*to use all pins for LED*/
	
	PORTA = 0XFF;
	ADCSRA = 0X87;
	
	while(1)
	{
		ADMUX = 0XE0;
		ADCSRA |= (1 << ADSC);
		while(!(ADCSRA & (1 << ADIF)));
		x = ADCH;
	
		ADMUX = 0XE1;
		ADCSRA |= (1 << ADSC);
		while(!(ADCSRA & (1 << ADIF)));
		y = ADCH;
	
		ADMUX = 0XE2;
		ADCSRA |= (1 << ADSC);
		while(!(ADCSRA & (1 << ADIF)));
		z= ADCH;
	
		
		if(x > 142)	// Right direction
		{
			PORTC = 1;
		}
		else if(x < 132 && y > 132 && y < 142) // Left Direction
		{
			PORTC = 2;
		}
		else if(y > 145 && x > 132 && x < 142) // Forward direction
		{
			PORTC = 4;
		}
		else if(y < 132 && x > 132 && x < 142) // Backward direction
		{
			PORTC = 8;
		}
		else if(x > 132 && x < 142 && y > 132 && y < 142) // Stop direction
		{
			PORTC = 0;
		}
		else // Stop direction
		{
			PORTC = 0;
		}
	}
	
	return 0;
}