int f=0;
void setup()
{
  Serial.begin(9600);
  pinMode(8, INPUT);
}

void loop()
{
  int c;
  c=digitalRead(8);

  if(f==0 && c==0)
  {
    f=1;
    Serial.println(" moisture content is present");
  }
  else if(f==1 && c==1)
  {
    f=0;
    Serial.println(" no moisure content is present");
  }
  
}
