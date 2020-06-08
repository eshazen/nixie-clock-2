#include <avr/io.h>
#include "uart.h"

void uart_init() {
  UART_OUT_PORT |= UART_OUT_VALUE;
  bit = 0;
}

void uart_putc( char c)
{
  bit = 1;
  word = 0xe00 + (c << 1);
}

uint8_t uart_busy() {
  return( bit != 0);
}

//
// called from ISR every 9600 Hz
//
void uart_tick() {
  if( bit) {			/* sending? */
#if UART_TICKS_PER_BIT
    if( ++tick == UART_TICKS_PER_BIT)
#endif
      {
	tick = 0;
	if( word & bit)
	  UART_OUT_PORT |= UART_OUT_VALUE;
	else
	  UART_OUT_PORT &= UART_OUT_MASK;
	bit <<= 1;
	if( bit == 0x800) {
	  bit = 0;
	}
      }
  }

  if( rx_bit) {			/* receiving?  */
    if( UART_IN_PORT & UART_IN_VALUE)
      rx_word |= rx_bit;
    rx_bit <<= 1;
    if( rx_bit == 0x400) {
      rx_valid = (rx_word >> 1) & 0xff;
      rx_bit = 0;
      GIMSK |= _BV(PCIE1);
    }
  }
}

void uart_rx_start()
{
  rx_bit = 1;
  rx_word = 0;
}


uint8_t uart_getc() {
  uint8_t t;
  t = rx_valid;
  rx_valid = 0;
  return t;
}
  
