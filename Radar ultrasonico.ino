#include <Servo.h>. 

const int trigPin = 7;
const int echoPin = 8;
const int buzzer = 6;

long duration;
int distance;
Servo myServo; 

void setup() {
  
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
  Serial.begin(9600);
  myServo.attach(9); 
}

void loop() {
  
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();

  if(distance < 20){
    digitalWrite(buzzer, HIGH);
  }
  else (digitalWrite(buzzer, LOW));
  
  Serial.print(i); 
  Serial.print(","); 
  Serial.print(distance); 
  Serial.print("."); 
  }
  
  for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(30);
  
  distance = calculateDistance();

  if(distance < 20){
    digitalWrite(buzzer, HIGH);
  }
  else (digitalWrite(buzzer, LOW));
  
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
}

int calculateDistance() { 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2;
  return distance;
}