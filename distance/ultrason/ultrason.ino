/*
  Ultrasonic distance sensor test.
  - Mesure distance every approximately 100ms
  - If something is detected from less than 10 cm, light a LED, else light another
  - Use serial communication port to give distance mesured in real time 
*/

// Distance sensor out
#define trigPin 13
// Distance sensor in
#define echoPin 12

// > 10 cm led
#define led 11
// <= 10 cm led
#define led2 10

void setup() 
{
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() 
{
  long duration, distance;  

  // Force a short LOW pulse to clean
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a HIGH pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  // Stop the pulse
  digitalWrite(trigPin, LOW);
  
  // Wait for the echo pulse
  duration = pulseIn(echoPin, HIGH);

  // Speed of sound is 340 m/s <=> 29.1 microseconds per centimeter
  distance = (duration/2) / 29.1;
  if (distance <= 10) 
  {
    // Light short distance LED
    digitalWrite(led,HIGH);
    digitalWrite(led2,LOW);
  } 
  else
  {    
    // Light high distance LED
    digitalWrite(led,LOW);
    digitalWrite(led2,HIGH);  
  }
  
  // No distance measured (or too big to be trusted)
  if (distance >= 200 || distance <= 0)
  {
    Serial.println("No (or untrusted) signal");
  }
  else 
  {
    Serial.print(distance);  
    Serial.println(" cm");
  }
  delay(100);
}
