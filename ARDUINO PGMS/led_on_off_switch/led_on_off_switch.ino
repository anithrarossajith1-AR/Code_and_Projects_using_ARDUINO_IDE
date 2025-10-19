void setup() {
  Serial.begin(9600);
  pinMode(8,OUTPUT);//led
  pinMode(10,INPUT);//switch

}

void loop() {
  int c;
  c=digitalRead(10);
  Serial.println(c);
  if(c==1)
  {
    digitalWrite(8,HIGH);
  }
  else if(c==0)
  {
    digitalWrite(8,LOW);
  }

}
