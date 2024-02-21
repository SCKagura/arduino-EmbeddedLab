#define LDR  35
int LDR_Value=0;
int static_variable = 500;

void setup() {
  Serial.begin(9600);
  pinMode(27,OUTPUT) ;
}

void loop() {
  LDR_Value = analogRead(LDR);

  Serial.print("Variable_1:");
  Serial.print(LDR_Value);
  Serial.print(",");
  int Treshold1 = 500 ;
  int Treshold2 = 1800 ;
  Serial.print("Variable_2:");
  Serial.println(Treshold1);
  Serial.print("Variable_3:");
  Serial.println(Treshold2);
  // if(LDR_Value <Treshold ){
  //   digitalWrite(27,HIGH); 
  // }else{
  //   digitalWrite(27,LOW) ;
  // }
  if(LDR_Value > Treshold2){
    digitalWrite(27,LOW); 
  }
  if(LDR_Value < Treshold1){
    digitalWrite(27, HIGH) ;
  }
  delay(200);
}