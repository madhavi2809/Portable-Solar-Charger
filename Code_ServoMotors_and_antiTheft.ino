#include <Servo.h>

int speed;
int LED = 13;
char input;

Servo s1;
Servo s2;

const int button1 = 8;
const int button2 = 9;
const int buzzer = 10;

void setup() 
{
s1.attach(12);
s2.attach(11);
pinMode(button1, INPUT);
pinMode(button2, INPUT);
pinMode(buzzer, OUTPUT);
}

void loop() 
{
  for(int i=0; i<=0; i+=1)
  {
    s1.write(i);
    delay(40);
  }
  for(int i=0; i<=0; i+=1)
  {
    s1.write(i);
    delay(40);
  }
  if(digitalRead(button1)==HIGH)
  {
    pinMode(buzzer,LOW);
    if(digitalRead(button2)==HIGH)
    {
      pinMode(buzzer,LOW);
      for(int i = 0;i <= 90; i+=1)
      {
        s2.write(i);
        delay(3000);
      }
      for(int i= 90; i<=0;i+=1)
      {
        s2.write(i);
        delay(4000);
      }
    }
    else if(digitalRead(button1)==LOW)
      {
        pinMode(buzzer,HIGH);
      }
    else {
      pinMode(buzzer,LOW);
    }
  }
  else if(digitalRead(button1)==LOW)
    {
      pinMode(buzzer,HIGH);
    }
  else 
    {
      pinMode(buzzer,LOW);
    }
}
