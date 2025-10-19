#define TRIG 4
#define ECHO 5
float time,distance;
void setup()
{
  Serial.begin(9600);
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
}
void loop()
{
  digitalWrite(TRIG,LOW);
  delayMicroseconds(2);
  
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(10);
  
  digitalWrite(TRIG,LOW);
  
  time=pulseIn(ECHO,HIGH);
  distance=(time*0.034)/2;
  
  Serial.println(" cm distance");
  Serial.print(distance);
  
  
}

  
  
