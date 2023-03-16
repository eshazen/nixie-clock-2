/*
 * Connect to NTP time server via WiFi
 * Once every 10s send out a message via serial to UART0 at 9600 baud
 * "*hhmm$"
 * 
 * Attempt to correct for DST in US Eastern zone
 */

#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <TimeLib.h>
#include <time.h>
#include <Timezone.h>

const char *ssid     = "wiggle24";
const char *password = "123456789b";

// we're at UTC-4 currently
const long utcOffsetInSeconds = (-4*3600);

TimeChangeRule usEDT = {"EDT", Second, Sun, Mar, 2, -240};  //UTC - 4 hours
TimeChangeRule usEST = {"EST", First, Sun, Nov, 2, -300};   //UTC - 5 hours
Timezone usEastern(usEDT, usEST);

// Define NTP Client to get time
WiFiUDP ntpUDP;
// NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);
NTPClient timeClient(ntpUDP, "pool.ntp.org", 0L);

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
  time_t localTime = usEastern.toLocal( timeClient.getEpochTime());
  
  struct tm *ptm = gmtime((time_t *)&localTime);

  hh = ptm->tm_hour;
  mm = ptm->tm_min;

  Serial.print("*");
  Serial.print( hh/10);
  Serial.print( hh%10);
  Serial.print( mm/10);
  Serial.print( mm%10);
  Serial.println("$");
  
    delay(10000);
}
