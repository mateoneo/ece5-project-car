// Pin definitions for HC-SR04
const int trigPin = 9;  // Trigger pin
const int echoPin = 10; // Echo pin

// Motor control pins for motor driver
const int motorLeftPin1 = 3; // Left motor IN1
const int motorLeftPin2 = 4; // Left motor IN2
const int motorRightPin1 = 5; // Right motor IN1
const int motorRightPin2 = 6; // Right motor IN2
const int enablePin = 11;     // Enable pin for both motors

// Threshold distance (in centimeters)
const int thresholdDistance = 10;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Set motor control pins
  pinMode(motorLeftPin1, OUTPUT);
  pinMode(motorLeftPin2, OUTPUT);
  pinMode(motorRightPin1, OUTPUT);
  pinMode(motorRightPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);

  // Enable motors
  analogWrite(enablePin, 255); // Full speed
}

void loop() {
  // Measure distance
  long duration = getDistance();
  int distance = duration * 0.034 / 2; // Convert to centimeters

  // Print distance for debugging
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Control motor based on distance
  if (distance <= thresholdDistance) {
    stopMotors();
    delay(1000); // Pause before moving backward
    goBackward();
    delay(1000); // Move backward for 1 second
    turnRight(); // Turn right to avoid obstacle
    delay(500);
  } else {
    goForward();
  }

  delay(100); // Small delay for stability
}

long getDistance() {
  // Send a 10-microsecond pulse to trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the time for the echo to return
  return pulseIn(echoPin, HIGH);
}

// Motor control functions
void stopMotors() {
  digitalWrite(motorLeftPin1, LOW);
  digitalWrite(motorLeftPin2, LOW);
  digitalWrite(motorRightPin1, LOW);
  digitalWrite(motorRightPin2, LOW);
}

void goForward() {
  digitalWrite(motorLeftPin1, HIGH);
  digitalWrite(motorLeftPin2, LOW);
  digitalWrite(motorRightPin1, HIGH);
  digitalWrite(motorRightPin2, LOW);
}

void goBackward() {
  digitalWrite(motorLeftPin1, LOW);
  digitalWrite(motorLeftPin2, HIGH);
  digitalWrite(motorRightPin1, LOW);
  digitalWrite(motorRightPin2, HIGH);
}

void turnLeft() {
  digitalWrite(motorLeftPin1, LOW);
  digitalWrite(motorLeftPin2, HIGH); // Reverse left motor
  digitalWrite(motorRightPin1, HIGH);
  digitalWrite(motorRightPin2, LOW); // Forward right motor
}

void turnRight() {
  digitalWrite(motorLeftPin1, HIGH);
  digitalWrite(motorLeftPin2, LOW); // Forward left motor
  digitalWrite(motorRightPin1, LOW);
  digitalWrite(motorRightPin2, HIGH); // Reverse right motor
}
