// Nixie Clock II
//
// 1Hz timer interrupts
// pin-change interrupt on PA5 starts timer-driven UART
// set time via UART at 9600 baud   "*hhmm$"
//
// boot-up rubbish out of ESP8266 seems to crash our cheezy UART,
// so delay 30s at power-up before enabling
//
// 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <ctype.h>

volatile uint8_t sec, min, min10, hr, hr10;

// counts at TIMER_HZ rate
volatile uint16_t tick1k;	/* 9600Hz counter */
volatile uint8_t tick1s;	/* startup 1Hz counter */
volatile uint8_t ready;

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
}

// interrupt at 9600Hz
ISR( TIMER0_OVF_vect)		// timer1 ISR
{
  TCNT0H = CNT_HI;
  TCNT0L = CNT_LOW;
  uart_tick();
  ++tick1k;
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
    if( ready && (send = uart_getc())) {
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
      tick1k = 0;
      PORTB ^= nLED;		/* toggle LED */

      // increment tick1s until 1 minute has passed, then
      // initialize UART
      if( !ready) {
	++tick1s;
	if( tick1s == 30) {	/* power up delay 1 minute */
	  ready = 1;
	  GIMSK = _BV(PCIE1);		/* enable UART pin change interrupt */
	}
	// display count-down time
	min10 = tick1s / 10;
	min = tick1s % 10;
      }

#ifdef TESTDPY
      inc_min();
      inc_hr();
#endif
#ifdef INTERNAL_TIME
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
  TIMSK = (1 << TOIE0);		/* enable timer interrupt */

  /* reset system clock divider to 1 so 8MHz clock */
  CLKPR = _BV(CLKPCE);
  CLKPR = 0;

  /* enable interrupt on PA5 (PCINT5) */
  uart_init();
  //  don't enable PC interrupt until ready
  //  PCMSK0 = _BV(PCINT5);
  PCMSK1 = 0;

  /* try fiddling with oscillator calibration */
  /* this seems about right */
  OSCCAL = 0x8d;

  ready = 0;
  // enable UART (pin change) interrupt mask
  PCMSK0 = _BV(PCINT5);
}

