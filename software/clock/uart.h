//
// software UART using timer interrup for bit timing
//

// number of timer ticks per bit
#define UART_TICKS_PER_BIT 1

#define UART_OUT_PORT PORTA
#define UART_OUT_BIT 4

#define UART_OUT_VALUE (_BV(UART_OUT_BIT))
#define UART_OUT_MASK (~(_BV(UART_OUT_BIT)))

#define UART_IN_PORT PINA
#define UART_IN_BIT 5
#define UART_IN_VALUE  (_BV(UART_IN_BIT))

volatile uint16_t bit;		/* bit counter 1..10, 0=not running */
volatile uint8_t tick;		/* count timer ticks */
uint16_t word;			/* character to transmit with star+stop*/

volatile uint16_t rx_bit;
volatile uint16_t rx_word;

volatile uint8_t rx_valid;

// output string to UART from flash
void uart_puts_P( const char* s);

void uart_puts( const char* s);

uint8_t uart_getc();

// load a transmit character for sending
void uart_putc( char c);

// check if UART is busy (1 if busy)
uint8_t uart_busy();

// call from timer ISR each timer tick
void uart_tick();

void uart_init();

// start receiving a character
void uart_rx_start();
