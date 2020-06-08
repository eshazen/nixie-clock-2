// Nixie Clock II
//
// 1Hz timer interrupts
// set time via UART at 9600 baud   "*hhmm$"
//

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <ctype.h>

volatile uint8_t sec, min, min10, hr, hr10;

// counts at TIMER_HZ rate
volatile uint8_t tick125;
volatile uint16_t tick1k;	/* 1kHz counter */

#include "timeofday.h"
#include "clock.h"
#include "display.h"
#include "uart.h"

void ioinit();

// pin change interrupt
ISR( PCINT_vect)
{
  // disable further pin change interrupts
  GIMSK &= ~_BV(PCIE1);  
  // set timer to half way through bit period
  TCNT0H = CNT_HALF_HI;
  TCNT0L = CNT_HALF_LOW;
  uart_rx_start();
  //  PORTB ^= nLED;		/* toggle LED */
}

// interrupt at 125kHz
ISR( TIMER0_OVF_vect)		// timer1 ISR
{
  TCNT0H = CNT_HI;
  TCNT0L = CNT_LOW;
  uart_tick();
  //  if( ++tick125 == 125) {
  //    tick125 = 0;
    ++tick1k;
    //  }
}

uint8_t send = 32;

// receive buffer for time messages
#define TIME_LEN 10
static char buff[TIME_LEN];
static char *p;

int main (void)
{
  ioinit();
  sei();
  uint16_t i;
  
  while( 1) {

    
#ifdef UART_SET
    if( send = uart_getc()) {
      if( send == '*') {
	p = buff;
      } else if( send == '$') {
	if( (p-buff) == 4) {
	  hr10  = buff[0] - '0';
	  hr    = buff[1] - '0';
	  min10 = buff[2] - '0';
	  min   = buff[3] - '0';
	}
      } else if( isdigit( send) && (p-buff) < TIME_LEN) {
	*p++ = send;
      }
    }
#endif

    if( tick1k >= 9600) {
      PORTB ^= nLED;		/* toggle LED */
      tick1k = 0;
#ifdef TESTDPY
      inc_min();
      inc_hr();
#else	
      inc_time();
#endif
      set_digits( hr10, hr, min10, min);
    }
  }
}

void ioinit() {
  DDRB = _BV(3) | _BV(6);       /* PB3, PB6 output */
  DDRA = 7;			/* set 3 LSBs as output */

  PORTB = 0;

  DDRA |= _BV(4);		/* only PA4 is output */

  PORTB |= nLED;		/* turn off LED */

  PORTA = 0;			/* all low including nCLR */
  /* deassert CLR, activate pull-ups on buttons */
  PORTA |= SR_CLR | SET_MIN | SET_HR;
  
  TCNT0H = CNT_HI;
  TCNT0L = CNT_LOW;

  TCCR0A = 0x80;		/* set only TCW0 for 16 bits */
  TCCR0B = CNT_PS_CODE;		/* set clock prescale */
  TIMSK = (1 << TOIE0);

  /* reset system clock divider to 1 so 8MHz clock */
  CLKPR = _BV(CLKPCE);
  CLKPR = 0;

  /* enable interrupt on PA5 (PCINT5) */
  PCMSK0 = _BV(PCINT5);
  PCMSK1 = 0;
  GIMSK = _BV(PCIE1);

  /* try fiddling with oscillator calibration */
  /* this seems about right */
  OSCCAL = 0x8d;

  uart_init();
}

