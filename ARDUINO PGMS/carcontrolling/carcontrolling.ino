#define TRIG 3
#define ECHO 2
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int f=0;
float distance,time;
String input= " ";
void setup()
{
  Serial.begin(9600);
  
  pinMode(9,OUTPUT);//motor1
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);

  pinMode(11,OUTPUT);//motor2
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);

  
  pinMode(4,OUTPUT);//buzzer&led
  
  pinMode(TRIG,OUTPUT);//ultra
  pinMode(ECHO,INPUT);
  
  lcd.init();//intializing lcd
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print(" ");
  
  analogWrite(9, 0);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);

  analogWrite(11, 0);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  
}

void loop()
{
  
  digitalWrite(TRIG,LOW);//ultra
  delayMicroseconds(2);
  
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(10);
  
  digitalWrite(TRIG,LOW);
  
  time=pulseIn(ECHO,HIGH);
  distance=(time*0.034)/2;
  
  //Serial.println(" cm distance");
  //Serial.print(distance);
  
  if(Serial.available())
  {
    input=Serial.readStringUntil('\n');
    input.trim();
  }
    if(input=="forward")
    {
      analogWrite(9,3); //forward
      digitalWrite(8, LOW);
      digitalWrite(7, HIGH);
      
      analogWrite(11,3); 
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      
      lcd.clear();//intializing lcd
      lcd.setCursor(0,0);
      lcd.print("FORWARD MOVING");
      
     if(distance<100)
      {
     analogWrite(9,0); 
     digitalWrite(8, LOW);
     digitalWrite(7, LOW);
     
     analogWrite(11,0);
     digitalWrite(12, LOW);
     digitalWrite(13, LOW);

     // blink buzzer/led
     digitalWrite(4, HIGH);
     delay(200);
     digitalWrite(4, LOW);
     delay(200);

     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("OBSTACLE STOP!");
      }
       else if(distance>=100)
      {
     digitalWrite(4, LOW);
    
      } 
      
    }
    
   else if(input=="reverse")
    {
      analogWrite(9,3); //reverse
      digitalWrite(8, HIGH);
      digitalWrite(7, LOW);
      
      analogWrite(11,3);
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      
      lcd.clear();//intializing lcd
      lcd.setCursor(0,0);
      lcd.print("REVERSE MOVING");
      
     if(distance<100)
      {
     analogWrite(9,0); 
     digitalWrite(8, LOW);
     digitalWrite(7, LOW);
     
     analogWrite(11,0);
     digitalWrite(12, LOW);
     digitalWrite(13, LOW);

     // blink buzzer/led
     digitalWrite(4, HIGH);
     delay(200);
     digitalWrite(4, LOW);
     delay(200);

     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("OBSTACLE STOP!");
      }
     else if(distance>100)
      {
       digitalWrite(4, LOW);
      } 
    }
    
    else if(input=="stop")
    {
      analogWrite(9,0); 
      digitalWrite(8, LOW);
      digitalWrite(7, LOW);
      
      analogWrite(11,3);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      
      lcd.clear();//intializing lcd
      lcd.setCursor(0,0);
      lcd.print("STOP");
    }
}
