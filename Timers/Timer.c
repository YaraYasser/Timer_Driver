#include <avr/interrupt.h>
#include "macros.h"
void Timer0_vInit(void)
{
	
	/*ctc MODE */
	SET_BIT(TCCR0,WGM01);
	/*ENABLE INTERUPT*/
  SET_BIT(TIMSK,OCIE0);
  sei();
  /* REQUEST EVERY 10MS*/ 	
  OCR0 = 78;
  /*Choose  clock prescaler*/
  SET_BIT(TCCR0,CS00);
  SET_BIT(TCCR0,CS02); 	
}

