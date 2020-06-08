Software for Nixie Clock on ExpressPCB board with ATMega861A

Drives four IN-2B nixies attached via ribbon cables to two-digit
breakout boards.  The wiring is a bit crazy and you will probably have
to just work it out yourself.

9600 baud serial I/O working with some effort:

Timer interrupt at 9600Hz using divide-by-1
clock source (8MHz) divided by 800.
(calculated value 833)

Transmit using timer interrupt.

Receive using pin-change to start, set timer
to half-value to reset timer interrupts to occur
in the middle of the bit period.

Time is updated (only) by serial messages received at 9600 baud with
the format "*hhmm$".

Build using Makefile.  Expects avr-libc and avr-gcc, binutils and
avrdude to be installed.

"make flash" to program your board once you set the avrdude options.
