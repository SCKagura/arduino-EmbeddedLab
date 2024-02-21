// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include "RTClib.h"
#include <LCD_I2C.h>
RTC_DS1307 rtc;
LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change according
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup () {
  Serial.begin(57600);
  lcd.begin(); // If you are using more I2C devices using the Wire library use lcd.begin(false)
                 // this stop the library(LCD_I2C) from calling Wire.begin()
    lcd.backlight();
#ifndef ESP8266
  while (!Serial); // wait for serial port to connect. Needed for native USB
#endif

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
     rtc.adjust(DateTime(2024, 1, 5, 14, 59, 0));
  }

  // When time needs to be re-set on a previously configured device, the
  // following line sets the RTC to the date & time this sketch was compiled
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  // This line sets the RTC with an explicit date & time, for example to set
  // January 21, 2014 at 3am you would call:
  // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));

}

void loop () {
    DateTime now = rtc.now();

    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
Serial.print(" ");
Serial.print(now.hour(), DEC);
Serial.print(':');
Serial.print(now.minute(), DEC);
Serial.print(':');
Serial.println(now.second(), DEC);

    lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
     lcd.print(" ");
    lcd.print(now.hour(), DEC);
    lcd.print(':');
    lcd.print(now.minute(), DEC);
    lcd.print(':');
    lcd.print(now.second(), DEC);
    // lcd.println();

    // Serial.print(" since midnight 1/1/1970 = ");
    // Serial.print(now.unixtime());
    // Serial.print("s = ");
    // Serial.print(now.unixtime() / 86400L);
    // Serial.println("d");

    // calculate a date which is 7 days, 12 hours, 30 minutes, and 6 seconds into the future
    // DateTime future (now + TimeSpan(7,12,30,6));

    // lcd.print(" now + 7d + 12h + 30m + 6s: ");
    // lcd.print(future.year(), DEC);
    // lcd.print('/');
    // lcd.print(future.month(), DEC);
    // lcd.print('/');
    // lcd.print(future.day(), DEC);
    // lcd.print(' ');
    // lcd.print(future.hour(), DEC);
    // lcd.print(':');
    // lcd.print(future.minute(), DEC);
    // lcd.print(':');
    // lcd.print(future.second(), DEC);
    // lcd.println();

    Serial.println();
    delay(1000);
    lcd.clear();
}