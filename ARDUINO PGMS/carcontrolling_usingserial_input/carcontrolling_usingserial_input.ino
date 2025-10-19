#include<SoftwareSerial.h>
SoftwareSerial bt(2,3); /* (Rx,Tx) */	

#define TRIG 4
#define ECHO 5
float time,distance;
char input= ' ';
void setup() 
{
  bt.begin(9600);	

  Serial.begin(9600);//ultra
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);

  pinMode(5,OUTPUT);//motor1
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);

  pinMode(10,OUTPUT);//motor2
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);

}

void loop() 
{
  
char c;

  digitalWrite(TRIG,LOW);
  delayMicroseconds(2);
  
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(10);
  
  digitalWrite(TRIG,LOW);
  
  time=pulseIn(ECHO,HIGH);
  distance=(time*0.034)/2;
  //Serial.println(" cm distance");
  //Serial.print(distance);

  //if(Serial.available())
  //{
   // input=Serial.readStringUntil('\n');
   // input.trim();
  //}
    if(bt.available())/* If data is available on serial port *///forward
    {
      c=Serial.write(bt.read());	/* Print character received on to the serial monitor */
      Serial.println(c);
      if (c=='f')
      {
        analogWrite(5, 225);
        digitalWrite(7, HIGH);
        digitalWrite(6, LOW);

        analogWrite(10, 225);
        digitalWrite(9, HIGH);
        digitalWrite(8, LOW);
        if(distance<100)
        {
          analogWrite(5, 0);
          digitalWrite(7, LOW);
          digitalWrite(6, LOW);

          analogWrite(10, 0);
          digitalWrite(9, LOW);
          digitalWrite(8, LOW);
        }
      }
      else if(c=="reverse") //reverse
      {
        analogWrite(5, 225);
        digitalWrite(7, LOW);
        digitalWrite(6, HIGH);

        analogWrite(10, 225);
        digitalWrite(9, LOW);
        digitalWrite(8, HIGH);
        
        if(distance<100)
        {
          analogWrite(5, 0);
          digitalWrite(7, LOW);
          digitalWrite(6, LOW);

          analogWrite(10, 0);
          digitalWrite(9, LOW);
          digitalWrite(8, LOW);
        }
      }
      else if(c=="stop")//stop
      {
        analogWrite(5, 0);
        digitalWrite(7, LOW);
        digitalWrite(6, LOW);

        analogWrite(10, 0);
        digitalWrite(9, LOW);
        digitalWrite(8, LOW);
      }
    }
}
