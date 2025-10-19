int f=0;
void setup() 
{
  Serial.begin(9600);
  pinMode(A5,INPUT);
  
}

void loop() 
{
  int c;
  c=analogRead(A5);
  
  if(c>100 && f==0)
  {
    Serial.println("gas detected");
    f=1;
  }
  else if(c<100 && f==1)
  {
    Serial.println("gas not detected");
    f=0;
  }

}
