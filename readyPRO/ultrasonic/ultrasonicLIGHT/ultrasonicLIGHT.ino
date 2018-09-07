const int trigPin = 9;
const int echoPin = 10;
#define led1 13
#define led2 12
#define led3 11
#define led4 8
#define led5 7
// defines variables
long duration;
int distance;
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);
pinMode(led5, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;

if (distance > 40 && distance <=50) {
    digitalWrite(led1, HIGH);
}
  else {
    digitalWrite(led1,LOW);
  }
 if (distance > 30 && distance <=40) {
    digitalWrite(led2, HIGH);
}
  else {
    digitalWrite(led2,LOW);
  }
 if (distance > 20 && distance <=30) {
    digitalWrite(led3, HIGH);
}
  else {
    digitalWrite(led3,LOW);
  }
  if (distance > 10 && distance <=20) {
    digitalWrite(led4, HIGH);
}
  else {
    digitalWrite(led4,LOW);
  }
  if (distance < 10) {
    digitalWrite(led5, HIGH);
}
  else {
    digitalWrite(led5,LOW);
  }
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}
