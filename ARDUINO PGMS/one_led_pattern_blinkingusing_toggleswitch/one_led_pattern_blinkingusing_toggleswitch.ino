int x=0;
void setup() 
{
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  pinMode(10,INPUT);

}

void loop() 
{
  int c;
  c=digitalRead(10);
  //Serial.println(c);
  Serial.println(x);

  if(c==1)
  {
    while(digitalRead(10)==1);
    x++;

    if(x>2)
    {
      x=0;
    }
  }
  if(x==0)
  {
    digitalWrite(8,HIGH);
  }
  else if(x==1)
  {
    digitalWrite(8,HIGH);
    delay(500);
    digitalWrite(8,LOW);
    delay(500);
  }
  else if(x==2)
  {
    digitalWrite(8,LOW);
  }
}
