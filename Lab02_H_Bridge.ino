#define Enable 23
#define Input1 22
#define Input2 19
#define LED1   13
#define LED2   12

void setup()
{
  pinMode(Enable, OUTPUT);
  pinMode(Input1, OUTPUT);
  pinMode(Input2, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  digitalWrite(Enable, LOW);  // ตั้งค่า Enable เป็น LOW เพื่อปิดการทำงานของมอเตอร์
}

void loop()
{
  // หมุนตามเข็มนาฬิกา
  digitalWrite(Input1, HIGH);
  digitalWrite(Input2, LOW);
  digitalWrite(Enable, HIGH);  // เปิดการทำงานของมอเตอร์
  showDirection(true);  // แสดงทิศทางการหมุน

  delay(5000);  // รอเวลา 5 วินาที

  // หมุนทวนเข็มนาฬิกา
  digitalWrite(Input1, LOW);
  digitalWrite(Input2, HIGH);
  showDirection(false);  // แสดงทิศทางการหมุน

  delay(5000);  // รอเวลา 5 วินาที

  // ปิดการทำงานของมอเตอร์
  digitalWrite(Enable, LOW);
}

void showDirection(bool clockwise)
{
  if (clockwise)
  {
    digitalWrite(LED1, HIGH);  // แสดง LED1 เพื่อบอกทิศทางการหมุนตามเข็มนาฬิกา
    digitalWrite(LED2, LOW);
  }
  else
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);  // แสดง LED2 เพื่อบอกทิศทางการหมุนทวนเข็มนาฬิกา
  }
}
