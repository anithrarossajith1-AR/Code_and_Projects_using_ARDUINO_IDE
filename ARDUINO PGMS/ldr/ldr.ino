void setup() 
{
  Serial.begin(9600);
  pinMode(8,INPUT);

}

void loop() 
{
  int c;
  c=digitalRead(8);
  Serial.println(c);

}
