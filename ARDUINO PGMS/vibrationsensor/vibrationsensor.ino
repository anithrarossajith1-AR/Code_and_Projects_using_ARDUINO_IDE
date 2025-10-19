int f=0;
void setup() 
{
  Serial.begin(9600);
  pinMode(8,INPUT);

}

void loop() 
{
  int c;
  c=digitalRead(8);
  if (c == 1 && f == 0) 
  {
    Serial.println("vibration occured");
    f = 1;  
  }
  else if (c == 0 && f == 1) 
  {
    Serial.println("vibration not occured");
    f = 0;
  }
}


