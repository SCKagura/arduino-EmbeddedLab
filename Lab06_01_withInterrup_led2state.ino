#define Button_Pin   35
#define LED1_Pin     23
#define LED2_Pin     22

volatile bool buttonState = false;

void IRAM_ATTR IO_INT_ISR() {
  buttonState = !buttonState; // สลับค่าสถานะของปุ่มเมื่อมีการกด
}

void setup() {
  pinMode(LED1_Pin, OUTPUT);
  pinMode(LED2_Pin, OUTPUT);
  pinMode(Button_Pin, INPUT_PULLUP); // กำหนดให้ปุ่มเป็น INPUT_PULLUP เพื่อไม่ต้องใช้เรซิเตอร์ภายนอก
  attachInterrupt(Button_Pin, IO_INT_ISR, RISING); // interrupt on rising edge
}

void loop() {
  digitalWrite(LED1_Pin, !digitalRead(LED1_Pin)); // กระพริบ LED1 ทุก ๆ 1 วินาที
  delay(1000);
  
  if (buttonState) {
    digitalWrite(LED2_Pin, HIGH); // สถานะปัจจุบันของปุ่มเป็น HIGH แสดงว่ากดปุ่มแล้ว
  } else {
    digitalWrite(LED2_Pin, LOW); // สถานะปัจจุบันของปุ่มเป็น LOW แสดงว่าปล่อยปุ่ม
  }
}
