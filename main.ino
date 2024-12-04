// Pin definitions for HC-SR04
const int trigPin = 9;  // Trigger pin
const int echoPin = 10; // Echo pin

// Motor control pins for motor driver
const int motorLeftPin1 = 3; // Left motor IN1
const int motorLeftPin2 = 4; // Left motor IN2
const int motorRightPin1 = 5; // Right motor IN1
const int motorRightPin2 = 6; // Right motor IN2
const int enablePin = 11;     // Enable pin for both motors

// Control pins for manual movement
const int forwardPin = 2;  // Forward
const int leftPin = 7;     // Left
const int rightPin = 12;   // Right
const int backwardPin = 13; // Backward

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set motor control pins
  pinMode(motorLeftPin1, OUTPUT);
  pinMode(motorLeftPin2, OUTPUT);
  pinMode(motorRightPin1, OUTPUT);
  pinMode(motorRightPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);

  // Set control pins for manual movement
  pinMode(forwardPin, INPUT_PULLUP);
  pinMode(leftPin, INPUT_PULLUP);
  pinMode(rightPin, INPUT_PULLUP);
  pinMode(backwardPin, INPUT_PULLUP);

  
  
}

void loop() {
  // Manual control using input pins
  if (digitalRead(forwardPin) == LOW) {
    goForward();
  } else if (digitalRead(leftPin) == LOW) {
    turnLeft();
  } else if (digitalRead(rightPin) == LOW) {
    turnRight();
  } else if (digitalRead(backwardPin) == LOW) {
    goBackward();
  } else {
    stopMotors(); // Stop the motors when no button is pressed
  }

  delay(100); // Small delay for stability
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
