#include <Wire.h>
#include <LCD_I2C.h>
#include <PubSubClient.h>  // Install the PubSubClient library in Arduino IDE

LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change accordingly

#define LDR_PIN A0
#define input1 18
#define input2 19
#define input3 27
#define input4 23

int LDR_Value = 0;
int stepperAngle = 0;

const char* mqttServer = "your_mqtt_broker_address";
const int mqttPort = 1883;
const char* mqttUser = "your_mqtt_username";
const char* mqttPassword = "your_mqtt_password";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(9600);
  pinMode(LDR_PIN, INPUT);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  pinMode(input3, OUTPUT);
  pinMode(input4, OUTPUT);

  lcd.begin();
  lcd.backlight();

  // Connect to MQTT broker
  client.setServer(mqttServer, mqttPort);
}

void loop() {
  LDR_Value = analogRead(LDR_PIN);

  // Map LDR values to Stepper Motor angle (0-180)
  stepperAngle = map(LDR_Value, 0, 1023, 0, 180);

  // Publish motor degree to MQTT topic
  publishToMQTT(stepperAngle);

  // Rotate the Stepper Motor based on the mapped angle
  rotateStepperMotor(stepperAngle);

  // Update LCD display
  updateLCD();

  delay(1000);  // Adjust the delay according to your requirements
}

void rotateStepperMotor(int targetAngle) {
  // Implement your stepper motor control logic here
  // ...
}

void updateLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Stepper Angle: ");
  lcd.print(stepperAngle);
  lcd.setCursor(0, 1);
  lcd.print("LDR Value: ");
  lcd.print(LDR_Value);
}

void publishToMQTT(int value) {
  // Connect to MQTT broker
  if (!client.connected()) {
    reconnect();
  }

  // Publish motor degree to MQTT topic
  char topic[50];
  sprintf(topic, "stepper/motor/degree");
  client.publish(topic, String(value).c_str());

  // Wait a moment to allow the message to be sent
  delay(50);
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ArduinoClient", mqttUser, mqttPassword)) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}
