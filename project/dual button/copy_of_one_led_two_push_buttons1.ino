int led=9;
int button=8;
int button2=10;
void setup()
{
  pinMode(button,INPUT);
  pinMode(button2,INPUT);
  digitalWrite(button,HIGH);
  digitalWrite(button2,HIGH);
  pinMode(led, OUTPUT);
  
}
int brightness=128;
void loop()
{
  if(digitalRead(button)== LOW){
   brightness=brightness+10 ; 
  }
  else if(digitalRead(button2)== LOW){
   brightness=brightness-10 ; 
  }
  brightness= constrain(brightness,0,255);
  analogWrite(led,brightness);
  delay(20);
}