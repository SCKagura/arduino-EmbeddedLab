#define LED 21
hw_timer_t *My_timer = NULL;

// เรียก onTimer() เมื่อเกิด Interrupt
void IRAM_ATTR onTimer(){
  digitalWrite(LED, !digitalRead(LED));
}

void setup() {
  pinMode(LED, OUTPUT);
  My_timer = timerBegin(0, 80, true);  // เริ่มต้น Timer 0 ที่ prescale 80 เพื่อให้ค่าตั้งค่าที่ตำนับเพิ่มขึ้นทุก 1 uSec
  timerAttachInterrupt(My_timer, &onTimer, true); // แนบการกระทำที่ต้องการให้เกิดขึ้นเมื่อเกิดการตั้งค่า Timer Interrupt
  int studentID = 63000002; // รหัสนักศึกษา
  int frequency = (studentID % 100) * 10; // นำเลขท้ายสองตัวของรหัสนักศึกษามาคูณด้วย 10 เพื่อให้เป็นความถี่
  timerAlarmWrite(My_timer, 1000000 / frequency, true);  // ตั้งค่า Alarm ให้เกิดทุกครั้งที่ผ่านไปครั้งละ (1 วินาที / ความถี่)
  timerAlarmEnable(My_timer);  // เปิดใช้งาน Alarm
}

void loop() {
  // ไม่มีการทำงานใน Loop() เนื่องจากใช้ Timer Interrupt ในการสร้างสัญญาณ Square Wave
}
