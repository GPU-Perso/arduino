/* Simple motor on/off rotation */

#define motorPin 2

void setup() 
{                
  pinMode(motorPin, OUTPUT);     
}

void loop() 
{
  // Turn the motor on
  digitalWrite(motorPin, HIGH);
  // wait for 3 seconds
  delay(3000);
  // Turn the motor off
  digitalWrite(motorPin, LOW);
  // wait for 3 seconds
  delay(3000);
}
