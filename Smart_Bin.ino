#include <Servo.h>

Servo lidServo;

const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 6;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lidServo.attach(servoPin);
  lidServo.write(0);
  Serial.begin(9600);
}

void loop() {
  long duration;
  long distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("distance");
  Serial.println(distance);

  if (distance < 10) {
    lidServo.write(90);    
    delay(2000);           
    lidServo.write(0);     
  } else {
    lidServo.write(0);
  }
 delay(5000);
}
