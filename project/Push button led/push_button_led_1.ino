const int Switch = 2, led = 3;
int state = 0, LEDstate=0;

void setup()
{
  pinMode(Switch, INPUT);//Push Button as input
  pinMode(led, OUTPUT);//Led as output
  Serial.begin(9600);
}
void loop()
{
  if (state == 0 && digitalRead(Switch) == HIGH) {
    state = 1;
    LEDstate=1;
  }
  if (state == 1 && digitalRead(Switch) == LOW) {   
    state = 0;
    LEDstate = 0;
  }
   digitalWrite(led, state);
}