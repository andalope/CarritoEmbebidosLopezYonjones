#include <SoftwareSerial.h>
#include <Servo.h>
char t;

// Se definen los pines
SoftwareSerial myApp(7, 8); // 7RX 8TX
// RXD BLUETOOTH PIN 8
// TXD BLUETOOTH PIN 7
const int LEDPin = 9;
//int ang = 90;

Servo ServoAndroid;

char myChar;

void setup() {
  Serial.begin(9600);
  myApp.begin(9600);
  pinMode(13, OUTPUT);  //left motors  forward
  pinMode(12, OUTPUT);  //left motors reverse
  pinMode(11, OUTPUT);  //right  motors forward
  pinMode(10, OUTPUT);  //right motors reverse
  pinMode(9, OUTPUT);  //Led
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);  // Configura el pin del LED como salida
  Serial.println("Serial PC listo");
  myApp.println("App Lista#");

  //ServoAndroid.attach(10, 500, 2500); //PIN 10 SERVOMOTOR
}

void loop() {

  while (myApp.available()) {
    myChar = myApp.read();
    Serial.print(myChar);
    myApp.print(myChar);
    myApp.print("#");
    if (myChar == 'O') {
      digitalWrite(12, HIGH);
      digitalWrite(10, HIGH);
    }
    if (myChar == 'X') {
      digitalWrite(13, HIGH);
      digitalWrite(11, HIGH);
    }
    if (myChar == 'A') {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    }
    if (myChar == 'L') {
      analogWrite(11,170);
      //digitalWrite(11, HIGH);
      
    }
    if (myChar == 'R') {
      analogWrite(13, 170);
      //digitalWrite(13, HIGH);
    }

   // ang = constrain(ang, 0, 180);
  //  ServoAndroid.write(ang);
    delay(100);
  } // Fin del while de lectura

  while (Serial.available()) {
    myChar = Serial.read();
    myApp.print(myChar);
    myApp.print("#");
  }
}
