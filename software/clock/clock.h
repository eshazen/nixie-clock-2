//--- I/O pins ---

// nixie shift register data output
#define SR_OUT _BV(0)
// nixie shift register clear (active low)
#define SR_CLR _BV(1)
// nixie shift register clock (rising edge)
#define SR_CLK _BV(2)
// nixie shift register input (diagnostic)
#define SR_IN _BV(3)

// on-board LED output
#define nLED _BV(6);

// set buttons
#define SET_MIN _BV(4)
#define SET_HR _BV(5)

// GPS serial input
#define GPS_IN _BV(6)

//--- timer constants
// #define ONE_HZ (65535-(F_CPU/1024))
// #define CNT_LOW (ONE_HZ&0xff)
// #define CNT_HI ((ONE_HZ>>8)&0xff)

#define TIMER_HZ (125000)

// divide-by-800 for 9600 baud
// (calculate 833 but who knows?)
#define CNT_VAL (65535-800)
#define CNT_LOW (CNT_VAL&0xff)
#define CNT_HI ((CNT_VAL>>8)&0xff)

// values for half-period
#define CNT_HALF_VAL (65535-400)
#define CNT_HALF_LOW (CNT_HALF_VAL&0xff)
#define CNT_HALF_HI ((CNT_HALF_VAL>>8)&0xff)

// divide-by-1 mode
#define CNT_PS_CODE 1
