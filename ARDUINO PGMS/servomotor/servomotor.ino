#include<Servo.h>
Servo Servomotor;
void setup() 
{
  Servomotor.attach(7);
  Servomotor.write(0);

}

void loop() 
{
  Servomotor.write(90);
  delay(500);
  Servomotor.write(180);
  delay(500);
  Servomotor.write(0);
  delay(500);
  Servomotor.write(45);
  delay(500);
}
