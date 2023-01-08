# nixie-clock-2
Simple nixie clock based on ATMega861 microcontroller

<table>
  <tr>
    <td width=50%><img src="https://github.com/eshazen/nixie-clock-2/blob/master/doc/Block_Diagram.png">
    <td><img src="https://github.com/eshazen/nixie-clock-2/blob/master/doc/bus.jpg">
</table>

```hardware/DriverBoard```

ExpressPCB layout for MCU/Driver board with ATTiny861A driving 4 IN-2B nixies.

```hardware/nixie_socket```

KiCAD design for a two-digit nixie mounting/breakout board

```software/clock```

C code for ATTiny861A to drive the clock display

```software/ESP8266```

Very simple NTP client to get the time via WiFi and send to the ATTiny

## Notes

Thinking of building one for the Kitchen.  Instead of ESP8622, thinking
of one of many DS3231 I2C RTC modules.  This could use the header wires
now used for the ESP

On power-up/reboot, the ESP module transmits a blast of serial stuff
at a high bit rate.  This crashes the AVR code.  There's a 30 sec
timer which runs before enabling serial, but apparently the power-up
reset of the ESP sometimes fails.  So for now a reliable
power-up procedure:

* Apply AC power
* Press the reset button on the ESP fairly promptly

Then after 30s timeout things should come up OK.  I'd try to fix
this but can't easily locate my programming adapter for the AVR.
