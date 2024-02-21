#define buttonPin 27    // ขาที่เชื่อมต่อ LED
#define ledPin 5

void setup() {
  Serial.begin(9600) ;
  pinMode(buttonPin, INPUT);  // ตั้งค่าขาปุ่มเป็น INPUT_PULLUP เพื่อให้มี resistor ดึงสูง
  pinMode(ledPin, OUTPUT);          // ตั้งค่าขา LED เป็น OUTPUT
}

void loop() {
  // อ่านค่าปุ่ม
  int buttonState = digitalRead(buttonPin);
  Serial.println("Button state: "+buttonState);
  

  // หากปุ่มถูกกด
  if (buttonState == LOW) {
    // เปิด LED
    digitalWrite(ledPin, HIGH);
    Serial.println("HIGH") ;
  } else {
    // ปิด LED
    digitalWrite(ledPin, LOW);
    Serial.println("LOW") ;

  }
}
