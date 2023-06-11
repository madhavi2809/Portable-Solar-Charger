#include <SPI.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN pins
const uint64_t address = 0xF0F0F0F0E1LL; // Address to listen to

int motor1Pin1 = 4; // Motor 1 control pin 1
int motor1Pin2 = 5; // Motor 1 control pin 2
int motor2Pin1 = 6; // Motor 2 control pin 1
int motor2Pin2 = 7; // Motor 2 control pin 2

int motor1SpeedPin = A0; // MotorspeedPin 1 control pin 1
int motor2SpeedPin = A1; // MotorspeedPin 2 control pin 2

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.startListening();

  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  
  pinMode(motor1SpeedPin, OUTPUT);
  pinMode(motor2SpeedPin, OUTPUT);
}

void loop() {
  if (radio.available()) {
    int speeds[2] = {0}; // Array to store the received speed values for motor 1 and motor 2
    radio.read(&speeds, sizeof(speeds));

    int speed1 = speeds[0];
    int speed2 = speeds[1];

    // Set direction and speed for Motor 1
    if (speed1 > 110) {
      digitalWrite(motor1Pin1, HIGH);
      digitalWrite(motor1Pin2, LOW);
      analogWrite(motor1SpeedPin, speed1);
    if (speed2 > 50) {
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
      analogWrite(motor2SpeedPin, speed2);
    }}
    else if (speed1 < 40) {
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, HIGH);
      analogWrite(motor1SpeedPin, -speed1);
      if (speed2 < 30) {
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);
      analogWrite(motor2SpeedPin, -speed2);
    } } else {
      digitalWrite(motor1Pin1, LOW);
      digitalWrite(motor1Pin2, LOW);
      analogWrite(motor1SpeedPin, 0);
      
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, LOW);
      analogWrite(motor2SpeedPin, 0);
    
    }
    if (speed2 > 50) {
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
      analogWrite(motor2SpeedPin, speed2);
    }

     else if (speed2 < 30) {
      digitalWrite(motor2Pin1, LOW);
      digitalWrite(motor2Pin2, HIGH);
      analogWrite(motor2SpeedPin, -speed2);
    }

    
    Serial.print("Speed1: ");
    Serial.print(speed1);
    Serial.print(", Speed2: ");
    Serial.println(speed2);
  }
}
