#include <Servo.h>

// Define the IR sensor pin
int irSensorPin = 2;

// Define the servo motor pin
int servoPin = 9;

// Create a servo object
Servo myservo;

void setup() {
  // Initialize the servo object
  myservo.attach(servoPin);
  
  // Set the IR sensor pin as an input
  pinMode(irSensorPin, INPUT);
  
  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the IR sensor value
  int irValue = digitalRead(irSensorPin);
  
  // Print the IR sensor value to the serial monitor
  Serial.println(irValue);
  
  // Move the servo motor based on the IR sensor value
  if (irValue == HIGH) {
    myservo.write(180); // Move the servo to the middle position
  } else {
    myservo.write(90); 
    delay(5000);// Move the servo to the left position
  }
  
  // Wait for a short period of time
  delay(100);
}