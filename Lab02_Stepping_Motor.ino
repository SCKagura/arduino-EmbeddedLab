#define input1 18
#define input2 19
#define input3 22
#define input4 23
void setup()
{
  Serial.begin(9600) ;
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  pinMode(input3, OUTPUT);
  pinMode(input4, OUTPUT);
 
}

void loop()
{
  // หมุนตามเข็มนาฬิกา
  digitalWrite(input1, HIGH);
  digitalWrite(input2, LOW);
  digitalWrite(input3, LOW);
  digitalWrite(input4, LOW);
  delay(5); 
  digitalWrite(input1,LOW);
 digitalWrite(input2, HIGH);
 delay(5) ;
 digitalWrite(input2,LOW);
 digitalWrite(input3, HIGH);
 delay(5) ;
 digitalWrite(input3,LOW);
 digitalWrite(input4, HIGH);
 delay(5) ;
}
