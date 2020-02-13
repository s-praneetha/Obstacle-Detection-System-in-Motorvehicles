#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int leftmotor1=15;
int leftmotor2=16;
int rightmotor1=17;
int rightmotor2=18;


void setup() {
  pinMode(leftmotor1,OUTPUT);
  pinMode(leftmotor2,OUTPUT);
  pinMode(rightmotor1,OUTPUT);
  pinMode(rightmotor2,OUTPUT);
  pinMode(6,OUTPUT);//u1 front trig
  pinMode(7,INPUT); //echo
  pinMode(8,OUTPUT);//u2 back trig
  pinMode(9,INPUT);  //echo
  pinMode(14,OUTPUT);//buzzer
  pinMode(13,OUTPUT);//led1
  pinMode(10,OUTPUT);//led2
  lcd.begin(16, 2);
  Serial.begin(9600);
}
void loop() {

  digitalWrite(6,LOW);      //sending a pulse to front
  delayMicroseconds(2);
  digitalWrite(6,HIGH);
  delayMicroseconds(10);
  digitalWrite(6,LOW);
  float t1=pulseIn(7,HIGH);
  t1=t1/2;
  float d1=0.0343*t1;
  if(d1<50)
  {
    digitalWrite(14,HIGH);
    delay(500);
    digitalWrite(14,LOW);
    Serial.print("Object is at a distance:");
    Serial.println(d1);
    lcd.display();
    lcd.setCursor(0,0);
    lcd.print("OBJECT DETECTED");
    digitalWrite(leftmotor1,LOW);
    digitalWrite(leftmotor2,LOW);
    digitalWrite(rightmotor1,LOW);
    digitalWrite(rightmotor2,LOW);
    delay(100);
  }
  else
  { lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("TRAFFIC CLEAR");
    digitalWrite(leftmotor1,HIGH);
    digitalWrite(leftmotor2,LOW);
    digitalWrite(rightmotor1,LOW);
    digitalWrite(rightmotor2,HIGH);
    delay(100);
   digitalWrite(rightmotor1,LOW);
    digitalWrite(rightmotor2,LOW);
    digitalWrite(leftmotor1,LOW);
    digitalWrite(leftmotor2,LOW);
    delay(10);  
    digitalWrite(14,LOW);
    }
  digitalWrite(8,LOW);      //sending a pulse from back
  delayMicroseconds(2);
  digitalWrite(8,HIGH);
  delayMicroseconds(10);
  digitalWrite(8,LOW);
  float t2=pulseIn(9,HIGH);
  t2=t2/2;
  float d2=0.0343*t2;
  if(d2>0)
  {
    if(d2<20){
    digitalWrite(10,HIGH);
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(10,LOW);
    digitalWrite(13,LOW);
    lcd.noDisplay();
    }
  }
  delay(100);
}
