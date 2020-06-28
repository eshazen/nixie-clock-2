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
