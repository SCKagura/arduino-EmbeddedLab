#include <Adafruit_PCF8574.h>

#define PCF8574_Address 0x20

Adafruit_PCF8574 pcf;

void setup() {
  Serial.begin(9600);
  Serial.println("Adafruit PCF8574 LED control with button");

  if (!pcf.begin(PCF8574_Address, &Wire)) {
    Serial.println("Couldn't find PCF8574");
  }

  pcf.pinMode(7, OUTPUT); // LED
  pcf.pinMode(0, INPUT);  // Button
}

void loop() {

  // ถ้าปุ่มถูกกด
  if ( pcf.digitalRead(0)== HIGH) {
    pcf.digitalWrite(7, HIGH);  // เปิด LED
    Serial.println("High");
  } else {
    pcf.digitalWrite(7, LOW);   // ปิด LED
    Serial.println("LOw") ; 
  }
}
