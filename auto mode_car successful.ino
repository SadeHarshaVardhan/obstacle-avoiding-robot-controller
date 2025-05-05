#include <SoftwareSerial.h>

// Motor pins
const int motor1PWM = 4;         // PWM pin for motor 1
const int motor1Direction1 = 5;  // Direction pin 1 for motor 1
const int motor1Direction2 = 6;  // Direction pin 2 for motor 1
const int motor2PWM = 7;         // PWM pin for motor 2
const int motor2Direction1 = 8;  // Direction pin 1 for motor 2
const int motor2Direction2 = 9;  // Direction pin 2 for motor 2

// Ultrasonic sensor pins
const int trigPin = 10;  // Trigger pin of the ultrasonic sensor
const int echoPin = 11;  // Echo pin of the ultrasonic sensor

// Bluetooth module pins
const int bluetoothTx = 2;
const int bluetoothRx = 3;

SoftwareSerial bluetoothSerial(bluetoothTx, bluetoothRx);

void setup() {
  // Initialize motor pins as outputs
  pinMode(motor1PWM, OUTPUT);
  pinMode(motor1Direction1, OUTPUT);
  pinMode(motor1Direction2, OUTPUT);
  pinMode(motor2PWM, OUTPUT);
  pinMode(motor2Direction1, OUTPUT);
  pinMode(motor2Direction2, OUTPUT);

  // Initialize ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Initialize Bluetooth serial communication
  bluetoothSerial.begin(9600);
}

void loop() {
  // Measure distance using ultrasonic sensor
  long distance = measureDistance();

  // If obstacle detected, stop both motors and rotate right motor for 5 seconds
  if (distance < 20) {
    Serial.println("Obstacle detected. Stopping motors and rotating right motor for 5 seconds.");

    stopMotors();  // Stop both motors

    // Rotate right motor
    rotateRightMotor();
    delay(3000);         // Rotate for 5 seconds
    rotateRightMotor();  // Stop rotating right motor

    // Recheck distance
    distance = measureDistance();

    if (distance < 20) {
      Serial.println("Obstacle still detected after rotating right motor. Stopping right motor.");
    } else {
      Serial.println("Obstacle cleared after rotating right motor. Continuing forward.");
      moveForward();  // Move both motors forward
    }
  } else {
    // If no obstacle, move both motors forward
    moveForward();
  }

  delay(100);  // Delay for stability
}

// Function to measure distance using ultrasonic sensor
long measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2;

  return distance;
}

// Function to rotate right motor
void rotateRightMotor() {
  digitalWrite(motor2Direction1, HIGH);
  digitalWrite(motor2Direction2, LOW);
  analogWrite(motor2PWM, 255);  // Adjust the PWM value for speed control
}

// Function to stop right motor
/*void stopRightMotor() {
  digitalWrite(motor2Direction1, LOW);
  digitalWrite(motor2Direction2, LOW);
  analogWrite(motor2PWM, 0);
}*/

// Function to stop both motors
void stopMotors() {
  digitalWrite(motor1Direction1, LOW);
  digitalWrite(motor1Direction2, LOW);
  analogWrite(motor1PWM, 0);

  digitalWrite(motor2Direction1, LOW);
  digitalWrite(motor2Direction2, LOW);
  analogWrite(motor2PWM, 0);
}

// Function to move both motors forward
void moveForward() {
  digitalWrite(motor1Direction1, HIGH);
  digitalWrite(motor1Direction2, LOW);
  analogWrite(motor1PWM, 255);  // Adjust the PWM value for speed control

  digitalWrite(motor2Direction1, HIGH);
  digitalWrite(motor2Direction2, LOW);
  analogWrite(motor2PWM, 255);  // Adjust the PWM value for speed control
}
void sendDistanceOverBluetooth(long distance) {
  bluetoothSerial.print("Distance (in cm): ");
  bluetoothSerial.print(distance);

  if (distance <= 20) {
    bluetoothSerial.println(" - Obstacle detected");
  } else {
    bluetoothSerial.println();
  }
}
