#include <avr/io.h>
#include <util/delay.h>

/* initialize all variables */
int BLINK_DELAY_MS = 140;
int BLINK_DELAY_MS_FAST = 70;
int ROUND = 0;
int X = 0;

/* same time for on & off */
void blink (int DELAY)
{
  blink(DELAY,DELAY);
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
      blink(50,50);
    }
  }

}

int main (void)
{
  /* set pin 5 of PORTB for output*/
  DDRB |= _BV(DDB5);

  while(1) {
    X++;

    blink(BLINK_DELAY_MS);
    blink(BLINK_DELAY_MS_FAST);

    if ((X % 2) != 0)
      blink(0,(BLINK_DELAY_MS * 2));
    /* every 10 round */
    if (X == 10)
    {
      blink((BLINK_DELAY_MS * 8),0);
    }

    EVERY20ROUND(X, ROUND);

    /* reset after 20 round */
    if (X >= 20)
      X = 0;

  }

  return 0;
}