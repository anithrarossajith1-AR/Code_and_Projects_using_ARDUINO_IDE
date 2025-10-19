#include<Servo.h>
Servo Servomotor;
int position = 0;
void setup() 
{
  Servomotor.attach(5);
  
}

void loop() 
{
  for(position=0;position<=180;position+=1)
  {
    Servomotor.write(position);
    delay(100);
  }
  for(position=180;position>=0;position-=1)
  {
    Servomotor.write(position);
    delay(100);

  }
  
}
