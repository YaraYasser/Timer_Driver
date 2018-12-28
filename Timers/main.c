/*
 * Timers.c
 *
 * Created: 12/28/2018 8:03:07 AM
 * Author : user
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
# define F_CPU 8000000UL
#include <util/delay.h>
#include "Timer.h"
volatile unsigned char counterLED1 = 0,counterLED2 = 0;
volatile unsigned short counterLED3 = 0;
int main(void)
{
   	Timer0_vInit();
	while(1)
	{
	   if(counterLED1 == 100)
	   {
		   DDRD |= (1<<7);
		   PORTD ^= (1<<7);
		   counterLED1=0;
		   
	   }
	
	   if(counterLED2 == 200)
	   {
		  DDRD |= (1<<6);
		  PORTD ^= (1<<6);
		 counterLED2=0;
	   }   
		if(counterLED3 == 300)
		{
			DDRD |= (1<<5);
			PORTD ^= (1<<5);
			counterLED3=0;
		}
	
	
		


	}
   
}

ISR(TIMER0_COMP_vect)
{	
	
	counterLED1++;	
	counterLED2++;
	counterLED3++;
}

