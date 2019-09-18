#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX

#include <Servo.h>

Servo servoLeft;          // Define servo izquierdo
Servo servoRight;         // Define servo derecho
 
void setup()
{
 //Para Motores
 servoRight.attach(9);  // Asigna servo derecho al digital pin 9
 servoLeft.attach(10);  // Asigna servo izquierdo al digital pin 10
 stopRobot();
 
 //Para Serial
 Serial.begin(9600);
 Serial.println("Bienvenido al vehiculo \n");
 mySerial.begin(9600);
 delay(1000);
 }
 
void loop(){
 String IncomingString=""; //string que viene de la ESP8266
 boolean StringReady = false; //para ver si esta listo el string
 
 while (mySerial.available()){ //mientras el serie este disponible
   IncomingString=mySerial.readString(); //leo un string
   StringReady= true; //aviso que ya esta listo el string
  }
 
  if (StringReady){ //si el string esta listo
    Serial.println("Comando recibido: " + IncomingString); //lo imprimo
  }
  
  if (IncomingString == "Adelante"){ //si el string esta listo
    Serial.println("Moviendo hacia adelante \n");
    forward();
    //delay(2000);
  }
  
   if (IncomingString == "Atras"){ //si el string esta listo
    Serial.println("Moviendo hacia atras \n");
    reverse();
    //delay(2000);
  }
  
   if (IncomingString == "Izquierda"){ //si el string esta listo
    Serial.println("Doblare a la izquierda \n");
    turnLeft();
    //delay(2000);
  }
  
   if (IncomingString == "Derecha"){ //si el string esta listo
    Serial.println("Doblare a la derecha \n");
    turnRight();
    //delay(2000);
  }
  
   if (IncomingString == "Parar"){ //si el string esta listo
    Serial.println("Para el auto \n");
    stopRobot();
    //delay(2000);
  }
 }



 // Rutinas para adelante, atras, izquierda, derecha y parar.  
void forward() {
  servoLeft.write(180);
  servoRight.write(0);
}

void reverse() {
  servoLeft.write(0);
  servoRight.write(180);
}

void turnRight() {
  servoLeft.write(180);
  servoRight.write(75);
  delay(2000);
  forward();
}
void turnLeft() {
  servoLeft.write(105);
  servoRight.write(0);
  delay(1000);
  forward();
}

void stopRobot() {
  servoLeft.write(90);
  servoRight.write(90);
}
