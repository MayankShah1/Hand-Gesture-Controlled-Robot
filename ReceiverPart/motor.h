#include <avr/io.h>

/*
 * MOTOR M1 connected at pin PB-O and PB-1
 * MOTOR M2 connected at pin PB-2 and PB-3
 * Motor operations and respective pin configurations
 * stop : 0000
 * forward : 1010
 * backward : 0101
 * axial_right : 0110
 * axial_left : 1001
 * differential_right : 0010
 * differential_left : 1000
*/

/*stop the car*/
void stop()
{
	PORTB = 0B00000000;
}

/*move car forward*/
void forward()
{
	PORTB = 0B00001010;
}

/*move car backward*/
void backward()
{
	PORTB = 0B00000101;
}

/*take an axial-left turn*/
void axial_left()
{
	PORTB = 0B00000110;
}

/*take an axial-right turn*/
void axial_right()
{
	PORTB = 0B00001001;
}

/*take a differential-left turn*/
void differential_left()
{
	PORTB = 0B00000010;
}

/*take a differential-right turn*/
void differential_right()
{
	PORTB = 0B00001000;
}


