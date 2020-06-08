This directory has the ExpressPCB classic design files for a
four-digit nixie clock driver board.  Power is provided by two
inputs... 120V ac through an *isolation transformer* and 5V from any
convenient supply.  Nixies are driven by SN75461 transistor array
drivers.  Note the 90V zener on the common terminal... this protects
the driver chips in case no digits are illuminated.

The drivers are in turn controlled by a long shift register built of
74LS164 octal serial-to-parallel shift register ICs, driven by 4 GPIOs
on the uC.  

The circuitry consisting of C4, R2 etc was supposed to provide a 60Hz
interrupt to the MCU for timekeeping but it never worked right and I
decided to use NTP time loaded serially from an ESP8266.

J4 is an old-school Atmel 10 pin programming connector.  You'll
probably need to make an adapter (as I did) to program the board with
a modern 6-pin cable.

There's an ambient light sensor which may be used at some point to dim
the nixies at night.

Q1 is a MOSFET which is intended to drive an external alarm buzzer.

J2 has 3 GPIOs, of which I use only pin 3 as a serial input.
