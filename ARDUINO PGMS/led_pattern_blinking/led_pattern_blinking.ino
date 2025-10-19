void setup() 
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(9,OUTPUT);

}

void loop() 
{
  char c;
  if(Serial.available())
  {
    c=Serial.read();

    if(c=='a')
    {
      digitalWrite(13,HIGH);
      digitalWrite(12,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(9,HIGH);
      
    }

    else if(c=='b')
    {
      digitalWrite(13,HIGH);
      digitalWrite(12,LOW);
      digitalWrite(11,HIGH);
      digitalWrite(9,LOW);
    }
    
    else if(c=='d')
    {
      digitalWrite(13,LOW);
      digitalWrite(12,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(9,LOW);
    }

    else if(c=='e')
    {
      digitalWrite(13,HIGH);
      digitalWrite(12,LOW);
      digitalWrite(11,LOW);
      digitalWrite(9,HIGH);
    }

  }

}
