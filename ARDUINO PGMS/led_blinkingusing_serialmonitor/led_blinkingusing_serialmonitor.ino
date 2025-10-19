void setup() {
  Serial.begin(9600);
  pinMode(8,OUTPUT);

}

void loop() {
  char c;
  if(Serial.available())
  {
    c=Serial.read();
    if(c=='a')
    {
      digitalWrite(8,HIGH);
    }
    else if(c=='b')
    {
      digitalWrite(8,LOW);
    }
    else if(c=='d')
    {
      digitalWrite(8,HIGH);
      delay(1000);
      digitalWrite(8,LOW);
      delay(1000);
    }
  }
}
