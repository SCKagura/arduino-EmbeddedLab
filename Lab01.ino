#define LED     23
#define BUTTON  32

void setup() {
  pinMode(BUTTON, INPUT); // set arduino pin to input mode
  pinMode(LED, OUTPUT);  // set arduino pin to output mode
  Serial.begin(9600) ;
}


void loop() {
  if(digitalRead(BUTTON)==LOW) { 
    digitalWrite(LED, HIGH);
    Serial.println("1") ;
  }
  
  if(digitalRead(BUTTON)==HIGH)
  {
    digitalWrite(LED, LOW) ;
    Serial.println("0") ;

  }
}