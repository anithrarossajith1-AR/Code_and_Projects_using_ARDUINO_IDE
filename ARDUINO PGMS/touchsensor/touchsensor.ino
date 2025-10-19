int f=0;
void setup()
{
  Serial.begin(115200);
  pinMode(8, INPUT);
}

void loop()
{
  int c;
  c=digitalRead(8);
  Serial.println(c);
  

}