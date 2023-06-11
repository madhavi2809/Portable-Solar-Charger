#include <SPI.h>
#include <RF24.h>

RF24 radio(9, 8); // CE, CSN pins
const uint64_t address = 0xF0F0F0F0E1LL; // Address to send to
const int motor1Speed = A0; // Analog input pin for motor 1 speed
const int motor2Speed = A1; // Analog input pin for motor 2 speed

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_HIGH);
}

void loop() {
  int speed1 = map(analogRead(motor1Speed), 0, 1023, -255, 255); // Read potentiometer value and map it to speed range
  int speed2 = map(analogRead(motor2Speed), 0, 1023, -255, 255); // Read potentiometer value and map it to speed range

  int speeds[2] = {speed1, speed2}; // Array to store the speed values for motor 1 and motor 2
  radio.write(&speeds, sizeof(speeds));

  Serial.print("Speed1: ");
  Serial.print(speed1);
  Serial.print(", Speed2: ");
  Serial.println(speed2);

  delay(1);
}
