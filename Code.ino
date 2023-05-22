// C++ code
//
int pirsensor = 0;

int ultrasonic = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(4, INPUT);
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  pirsensor = digitalRead(4);
  ultrasonic = 0.01723 * readUltrasonicDistance(7, 6);
  Serial.println(pirsensor);
  delay(300); // Wait for 300 millisecond(s)
  Serial.println(ultrasonic);
  delay(300); // Wait for 300 millisecond(s)
  if (pirsensor == 1) {
    digitalWrite(12, HIGH);
  } else {
    digitalWrite(12, LOW);
  }
  if (ultrasonic <= 100) {
    digitalWrite(9, HIGH);
  } else {
    digitalWrite(9, LOW);
  }
}