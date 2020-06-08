//
// time of day manipulation functions
//

#ifdef SIMULATE

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include "timeofday.h"


volatile uint8_t sec, min, min10, hr, hr10;

int main( int argc, char *argv[]) {
  char *s = argv[1];

  hr10 = s[0] - '0';
  hr = s[1] - '0';
  min10 = s[2] - '0';
  min = s[3] - '0';
  sec = (s[4] -'0')*10 + (s[5]-'0');

  while( 1) {
    printf("%d%d:%d%d:%02d\n", hr10, hr, min10, min, sec);
    inc_time();
    sleep( 1);
  }
}

#else

#include <avr/io.h>
#include "timeofday.h"

#endif


uint8_t inc_sec() {
  ++sec;
  if( sec < 60) return 1;
  sec = 0;
  return 0;
}

uint8_t inc_min() {
  ++min;
  if( min < 10) return 1;
  min = 0;
  ++min10;
  if( min10 < 6) return 1;
  min10 = 0;
  return 0;
}

uint8_t inc_hr() {
  if( hr == 3 && hr10 == 2) {	/* check for midnight */
    hr = hr10 = 0;
    return 0;
  }
  ++hr;
  if( hr < 10) return 1;
  ++hr10;
  hr = 0;
  return 0;
}

void inc_time() {

  if( inc_sec()) return;
  if( inc_min()) return;
  inc_hr();
}
