#include <WiFi.h>
#include <MQTT.h>
#include "RTClib.h"
#include <LCD_I2C.h>
const char ssid[] = "@JumboPlusIoT";
const char pass[] = "9vefax3l";


RTC_DS1307 rtc;
LCD_I2C lcd(0x27, 16, 2);


const char mqtt_broker[]="test.mosquitto.org";
const char mqtt_topic[]="arduino_group2.29";
const char mqtt_client_id[]="arduino_group2.29"; // must change this string to a unique value
int MQTT_PORT=1883;

WiFiClient net;
MQTTClient client;
#define input 33
#define en 23 
#define input1 22 
#define input2 19 

void connect() {
  Serial.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\nconnecting...");
  while (!client.connect(mqtt_client_id)) {  
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected!");

  client.subscribe(mqtt_topic);
  // client.unsubscribe("/hello");
}
void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  client.begin(mqtt_broker, MQTT_PORT, net);
  client.onMessage(messageReceived);
  connect();
  pinMode(en, OUTPUT);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  pinMode(input, INPUT_PULLUP);
}
void messageReceived(String &topic, String &payload) {
  Serial.println("incoming: " + topic + " - " + payload);
  if(payload == "OPEN"){
    ShowStatus("OPEN") ;
    openDoor() ;
  }
  if(payload == "CLOSE"){
    ShowStatus("C") ;
    closeDoor() ;
  }
}

void ShowStatus(String status){
  if(status == "OPEN"){
    lcd.println("       The Door Is Opening...     ") ;
  }
  if(status == "CLOSE"){
    lcd.println("       The Door Is Closing") ;
  }
}

void stopMotor() {
  digitalWrite(en, LOW);
  digitalWrite(input1, LOW);
  digitalWrite(input2, LOW);
}

void openDoor() {
  Serial.println("Open door") ;
  digitalWrite(en, HIGH);
  digitalWrite(input1, LOW);
  digitalWrite(input2, HIGH);
  delay(200);
  lcd.clear() ;
  lcd.println("       The Door Opened") ;
  stopMotor();
}

void closeDoor() {
  Serial.println("CLose door") ;
  digitalWrite(en, HIGH);
  digitalWrite(input1, HIGH);
  digitalWrite(input2, LOW);
  delay(200);
  lcd.clear() ;
  lcd.println("       The Door Closed") ;
  stopMotor();
}

void loop() {
   client.loop();
  delay(10);  // <- fixes some issues with WiFi stability

  if (!client.connected()) {
    connect();
  }
  
  
}