#ifdef SIMULATE

#include <stdio.h>
#include <stdint.h>

#include "display.h"

int main( int argc, char *argv[])
{
  char *t = argv[1];

  set_digits( t[0]-'0', t[1]-'0', t[2]-'0', t[3]-'0');
  putchar( '|');
  putchar( '\n');
}
#else

#include <avr/io.h>
#include "clock.h"
#include "display.h"

#endif


//
// device-independent display code
//


#ifdef SCRAMBLE
// unscramble wiring for V2
static uint8_t tmap[] = { 6, 4, 0, 1, 2, 3, 5, 7, 9, 8 };
static uint8_t dmap[] = { 4, 5, 2, 3, 1, 0 };
#endif


// set the 4 digits (hhmm) of the display
// h10 is 0-5, h1 is 0-9, m10 is 0-5, m1 is 0-9
void set_digits( uint8_t h10, uint8_t h1, uint8_t m10, uint8_t m1) {

#ifdef SCRAMBLE
  set_digit( dmap[h10], 6);
  //  set_digit( h10, 6);
  set_digit( tmap[h1], 10);
  set_digit( dmap[m10], 6);
  //  set_digit( m10, 6);
  set_digit( tmap[m1], 10);
#else
  set_digit( h10, 6);
  set_digit( h1, 10);
  set_digit( m10, 6);
  set_digit( m1, 10);
#endif  
}


// clock the shift register len times
// with a single '1' in position len-v
//

void set_digit( uint8_t v, uint8_t len)
{
#ifdef SIMULATE
  putchar( '|');
#endif  
  for( uint8_t i=0; i<len; i++)
    sr_clk( i == (len-v-1));
}


void sr_clk( uint8_t b)
{
#ifdef SIMULATE
  putchar(b ? '*' : '.');
#else  
  if( b)
    PORTA |= SR_OUT;		/* set data bit */
  else
    PORTA &= ~(SR_OUT);

  PORTA &= ~(SR_CLK);		/* clock low */
  PORTA |= SR_CLK;		/* clock high */
#endif
}

