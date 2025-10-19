void setup() 
{
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);

}

void loop() 
{
  analogWrite(9,255);
  digitalWrite(8,LOW);
  digitalWrite(7,HIGH);

  analogWrite(11,255);
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
}
