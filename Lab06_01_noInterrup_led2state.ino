#define Button_Pin 35
#define LED1_Pin 23
#define LED2_Pin 22

unsigned long previousMillis = 0; // เก็บค่าเวลาล่าสุดที่เริ่มต้นการกระพริบ LED1
const long interval = 1000;        // ช่วงเวลาในการกระพริบ LED1 (หน่วย: มิลลิวินาที)

bool led2State = false; // สถานะปัจจุบันของ LED2 (เริ่มต้นดับ)

void setup()
{
  pinMode(LED1_Pin, OUTPUT);
  pinMode(LED2_Pin, OUTPUT);
  pinMode(Button_Pin, INPUT);
}

void loop()
{
  // ตรวจสอบสถานะของปุ่ม
  if (digitalRead(Button_Pin) == HIGH)
  {
    // กำหนดสถานะให้ LED2 ตรงกับสถานะปัจจุบัน
    digitalWrite(LED2_Pin, led2State);
    // เปลี่ยนสถานะ LED2
    led2State = !led2State;
  }
  
  // ตรวจสอบเวลาเพื่อกระพริบ LED1
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval)
  {
    // บันทึกค่าเวลาปัจจุบัน
    previousMillis = currentMillis;

    // สลับสถานะ LED1
    digitalWrite(LED1_Pin, !digitalRead(LED1_Pin));
  }
}
