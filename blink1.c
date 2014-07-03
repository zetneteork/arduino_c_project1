#include <avr/io.h>
#include <util/delay.h>

/* initialize all variables */
int BLINK_DELAY_MS = 200;
int BLINK_DELAY_MS_FAST = 100;
int ROUND = 0;
int X = 0;

/* same time for on & off */
void blink (int DELAY)
{
  /* set pin 5 high to turn led on */
  PORTB |= _BV(PORTB5);
  _delay_ms(DELAY);

  /* set pin 5 low to turn led off */
  PORTB &= ~_BV(PORTB5);
  _delay_ms(DELAY);
}

/* diffent time on & off */
void blink (int ON,int OFF)
{
  /* set pin 5 high to turn led on */
  PORTB |= _BV(PORTB5);
  _delay_ms(ON);

  /* set pin 5 low to turn led off */
  PORTB &= ~_BV(PORTB5);
  _delay_ms(OFF);
}

/* run only every 20 round */
void EVERY20ROUND (int X, int ROUND)
{
int I;
if ( X == 20 ){
for (I = 0; I < 10; I++){
  /* set pin 5 high to turn led on */
  PORTB |= _BV(PORTB5);
  _delay_ms(50);

  /* set pin 5 low to turn led off */
  PORTB &= ~_BV(PORTB5);
  _delay_ms(50);
  }
  
}
}

int main (void)
{
  /* set pin 5 of PORTB for output*/
  DDRB |= _BV(DDB5);

  while(1) {
    blink(BLINK_DELAY_MS);
    blink(BLINK_DELAY_MS_FAST);
	
	if ((X % 2) != 0)
	blink(0,(BLINK_DELAY_MS * 2));
	if (X == 10)
	{
	blink((BLINK_DELAY_MS * 8),0);
	}
	
	EVERY20ROUND(X, ROUND);
	
	
	X++;
  }

  return 0;
}

