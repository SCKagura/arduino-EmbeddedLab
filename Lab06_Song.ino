#define Button 23
#define Buzzer 34
hw_timer_t *My_timer = NULL;
int C = 1047;
int G = 1568;
int A = 1760;
int F = 1397;
int E = 1319;
int D = 1175;
int Note = 1000000 / C; // calculate initial alarm value for frequencu C
int On = 1;
int press = 5;
int sp = 50 ;


void IRAM_ATTR onTimer(){
  if(On == 1){
    digitalWrite(Buzzer, !digitalRead(Buzzer)); //if on, turn off
  } else {
    digitalWrite(Buzzer, LOW); //else turn on
  }
  timerAlarmWrite(My_timer, Note, true); // update value
}

void IRAM_ATTR IO_INT_ISR() //value of button pressed
{
  press--;
  if(press == 0){
    press = 5;
  }
  Serial.println(press);
}
void setup(){
  pinMode(Buzzer, OUTPUT);
  pinMode(Button, INPUT);
  digitalWrite(Buzzer, LOW);
  My_timer = timerBegin(0, 80, true);// use tiemr 0 and set prescale to 80 so 1 tick is 1 uSec
  timerAttachInterrupt(My_timer, &onTimer, true);// point to the ISR
  timerAlarmWrite(My_timer, Note, true);  // set alarm every 1 sec
  timerAlarmEnable(My_timer);  // enable the alarm
  attachInterrupt(Button, IO_INT_ISR, RISING);
  Serial.begin(9600);

}
 void quarter(int press){
  On = 1;
  delay(press*sp);
  On = 0;
  delay(press*2*sp);
 }
void Half(int press){
  On = 1;
  delay(press*sp);
  On = 0;
  delay(press*2*sp);
}

void loop(){
  Note = 1000000 / C ;
  quarter(press);
  quarter(press);
  Note = 1000000 / G;
  quarter(press);
  quarter(press);
  Note = 1000000 / A;
  quarter(press);
  quarter(press);
  Note = 1000000 / G;
  Half(press);

  Note = 1000000 / F ;
  quarter(press);
  quarter(press);
  Note = 1000000 / E;
  quarter(press);
  quarter(press);
  Note = 1000000 / D;
  quarter(press);
  quarter(press);
  Note = 1000000 / C;
  Half(press);

  Note = 1000000 / G;
  quarter(press);
  quarter(press);
  Note = 1000000 / F ;
  quarter(press);
  quarter(press);
  Note = 1000000 / E;
  quarter(press);
  quarter(press);
  Note = 1000000 / D;
  Half(press);

  Note = 1000000 / G;
  quarter(press);
  quarter(press);
  Note = 1000000 / F ;
  quarter(press);
  quarter(press);
  Note = 1000000 / E;
  quarter(press);
  quarter(press);
  Note = 1000000 / D;
  Half(press);
}

