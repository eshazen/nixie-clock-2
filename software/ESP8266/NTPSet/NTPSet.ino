/*
 * Connect to NTP time server via WiFi
 * Once every 10s send out a message via serial to UART0 at 9600 baud
 * "*hhmm$"
 */

#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char *ssid     = "my_ssid";
const char *password = "my_passwd";

// we're at UTC-4 currently
const long utcOffsetInSeconds = (-4*3600);

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

void setup(){
  Serial.begin(9600);
  
  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
  }

  timeClient.begin();
}

static int hh, mm;

void loop() {
  timeClient.update();

  hh = timeClient.getHours();
  mm = timeClient.getMinutes();

  Serial.print("*");
  Serial.print( hh/10);
  Serial.print( hh%10);
  Serial.print( mm/10);
  Serial.print( mm%10);
  Serial.println("$");
  
    delay(10000);
}
