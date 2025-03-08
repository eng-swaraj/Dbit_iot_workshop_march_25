
int Weight_signal=A0;
int Weight_value;
int LED=6;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(Weight_signal,INPUT);
}

void loop()
{
  Weight_value=analogRead(Weight_signal);
  Weight_value=map( Weight_value,0, 1023, 0, 255);
  analogWrite(LED, Weight_value);
  
}