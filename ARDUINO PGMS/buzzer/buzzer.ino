void setup() 
{
  pinMode(5,OUTPUT);

}

void loop() 
{
  int i;
  for(i=0;i<=225;i++)
  {
    analogWrite(5,i);
    delay(10);
  }
  for(i=225;i>=0;i--)
  {
    analogWrite(5,i);
    delay(10);
  }
  

}
