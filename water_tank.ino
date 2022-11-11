int trigPin = 11;    // TRIG pin
int echoPin = 12;    // ECHO pin
const int v1bPin =  9;
const int v1fPin =  8;

const int v2bPin =  7;
const int v2fPin =  6;

const int v3bPin =  5;
const int v3fPin =  4;

const int v4bPin =  3;
const int v4fPin =  2;
 
const int okPin =  10;
const int waterPin = 13;
const int motorPin = A0;


int flaga=1;
int flagb=1;
int flagc=1;
int flagd=1;
int flage=1;
int flagf=1;
int flagg=1;
int flagh=1;

float duration_us, distance_cm;

void v1open() {
  digitalWrite(9, LOW);
  delay(6900);
  digitalWrite (9, HIGH);
  delay(500);
flaga=0;
}
void v1close() {
  digitalWrite(8, LOW);
  delay(7300);
  digitalWrite(8, HIGH);
  delay(500);
flagb=0;
}
void v2open() {
  digitalWrite(7, LOW);
  delay(6900);
  digitalWrite(7, HIGH);
  delay(500);
  flagc=0;
}
void v2close() {
  digitalWrite(6, LOW);
  delay(6900);
  digitalWrite(6, HIGH);
  delay(500);
  flagd=0;
}
void v3open() {
  digitalWrite(5, LOW);
  delay(13000);
  digitalWrite(5, HIGH);
  delay(500);
  flage=0;

}
void v3close() {
  digitalWrite(4, LOW);
  delay(13000);
  digitalWrite(4, HIGH);
  delay(500);
  flagf=0;
}
void v4open() {
  digitalWrite(3, LOW);
  delay(13000);
  digitalWrite(3, HIGH);
  delay(500);
  flagg=0;
}
void v4close() {
  digitalWrite(2, LOW);
  delay(13500);
  digitalWrite(2, HIGH);
  delay(500);
  flagh=0;
}
int waterState = 0;

void setup() {

  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(2, HIGH);
 
  digitalWrite(10, LOW);
  // begin serial port
  Serial.begin (9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
     pinMode(9, OUTPUT);
     pinMode(10, OUTPUT);
     pinMode(13, INPUT);
      pinMode(A0, OUTPUT);
     digitalWrite(A0, HIGH);

  // configure the trigger pin to output mode
  pinMode(trigPin, OUTPUT);
  // configure the echo pin to input mode
  pinMode(echoPin, INPUT);
}

 

void loop() {
  delay(500);
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  waterState = digitalRead(waterPin);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(echoPin, HIGH);

  // calculate the distance
  distance_cm = 0.017 * duration_us;

  // print the value to Serial Monitor
  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");
  delay(300);
  if (distance_cm <7) {
  digitalWrite(10, HIGH);
  digitalWrite(A0, LOW);
  }

 if (waterState == HIGH) {
  if (flaga==1&&distance_cm >7) {
  v1open();
  flaga=0;
 

  }
  if (flagb==1&&flagc==1&&distance_cm >10){
  v1close();
  v2open();
  flagb=0;
  flagc=0;
  }

  if (flagd==1&&flage==1&&distance_cm >13) {
  v2close();
  v3open();
  flagd=0;
  flage=0;
  }

  if (flagf==1&&flagg==1&&distance_cm >16) {
  v3close();
  v4open();
  flagf=0;
  flagg=0;
  }
  if (flagh==1&&distance_cm >19) {
  v4close();
  flagh=0;
  }
}
}
