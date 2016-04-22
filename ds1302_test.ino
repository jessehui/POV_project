#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 RTC;

void setup () {
    Serial.begin(9600);
    Wire.begin();
    Serial.println("START");
    //RTC_Millis.begin();
    //RTC_Millis.adjust();
    RTC.begin();
    //RTC.adjust(DateTime("Apr 21 2016","19:29:30"));
  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(__DATE__,__TIME__));
  }
}
void loop () {

    Serial.println("In loop");
    //DateTime()
   // DateTime DateTime();
    DateTime now = RTC.now(); 
    
    Serial.println("Datetime received");
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(' ');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println(); 
    delay(1000);
}

