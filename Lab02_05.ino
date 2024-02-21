#define PIN1 32
#define PIN2 33
#define PIN7 25

void setup()
{
  pinMode(PIN1, OUTPUT);
  pinMode(PIN2, OUTPUT);
  pinMode(PIN7, OUTPUT);
}

void reverse()
{
  digitalWrite(PIN1, HIGH);
  digitalWrite(PIN2, HIGH);
  digitalWrite(PIN7, LOW);
}

void forward()
{
  digitalWrite(PIN1, HIGH);
  digitalWrite(PIN2, LOW);
  digitalWrite(PIN7, HIGH);
}

void stop1()
{
  digitalWrite(PIN1, HIGH);
  digitalWrite(PIN2, HIGH);
  digitalWrite(PIN7, HIGH);
}

void stop2()
{
  digitalWrite(PIN1, HIGH);
  digitalWrite(PIN2, LOW);
  digitalWrite(PIN7, LOW);
}

void stop3()
{
  digitalWrite(PIN1, LOW);
}

void loop()
{
  reverse();
  delay(3000);
  forward();
  delay(3000);
  stop1();
  delay(3000);
  stop2();
  delay(3000);
  stop3();
  delay(3000);
}