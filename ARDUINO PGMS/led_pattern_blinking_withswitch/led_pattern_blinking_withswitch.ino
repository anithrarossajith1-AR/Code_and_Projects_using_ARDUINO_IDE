int f=0;
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
  c=digitalRead(6);
  Serial.println(f);

  if(c==1)
  {
    while(digitalRead(6)==1);
    f++;

    if(f>4)
    {
      f=0;
    }
  }
    if(f==0)
    {
      digitalWrite(13,HIGH);
      digitalWrite(12,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(9,HIGH);
      
    }

    else if(f==1)
    {
      digitalWrite(13,HIGH);
      digitalWrite(12,LOW);
      digitalWrite(11,HIGH);
      digitalWrite(9,LOW);
    }
    
    else if(f==2)
    {
      digitalWrite(13,LOW);
      digitalWrite(12,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(9,LOW);
    }

    else if(f==3)
    {
      digitalWrite(13,HIGH);
      digitalWrite(12,LOW);
      digitalWrite(11,LOW);
      digitalWrite(9,HIGH);
    }

  }


