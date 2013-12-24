/* Analogic motor rotation */

#define motorPin 3

void setup() 
{
  pinMode(motorPin, OUTPUT);     
}

void loop() 
{
  // Increase rotation speed from (100/255)th of max speed to max 
  for (int i = 100; i <= 255; i++)
  {
    analogWrite(motorPin, i);
    delay(50);
  }

  // Decrease rotation speed
  for (int i = 255; i >= 100; i--)
  {
    analogWrite(motorPin, i);
    delay(50);
  }
}
