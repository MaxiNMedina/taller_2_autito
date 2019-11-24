#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX

#include <Servo.h>

Servo servoLeft;          // Define servo izquierdo
Servo servoRight;         // Define servo derecho
 
void setup()
{
 //Para Motores
 servoRight.attach(11);  // Asigna servo derecho al digital pin 9
 servoLeft.attach(12);  // Asigna servo izquierdo al digital pin 10
 stopRobot();
 
 //Para Serial
 Serial.begin(9600);
 Serial.println("Bienvenido al vehiculo \n");
 mySerial.begin(9600);
 delay(1000);
 }
 
void loop(){
 int orden=""; //int que viene de la ESP8266
 boolean Ready = false; //para ver si esta listo para recibir otra orden
 
 while (mySerial.available()){ //mientras el serie este disponible
   orden=mySerial.read(); //leo una orden
   Ready= true; //aviso que ya esta lista la orden
  }
 
  if (Ready){ //si la orden esta lista
    Serial.println("Comando recibido: " + orden); //lo imprimo
  }

  switch (orden){ //depende la orden hago una cosa u otra
    case 1:
      forward();
    break;

    case 2:
      reverse();
    break;

    case 3:
       turnLeft();
    break;

    case 4:
     turnRight();
    break;

    case 5:
      stopRobot();
    break;

    case 6:
      lento();
    break;

    case 7:
      rapido();
    break;
  }
}



 // Rutinas para adelante, atras, izquierda, derecha y parar.  
void forward() {
  servoLeft.write(110);
  servoRight.write(66);
}

void reverse() {
  servoLeft.write(66);
  servoRight.write(110);
}

void turnRight() {
  servoLeft.write(180);
  servoRight.write(85);
  delay(1500);
  forward();
}
void turnLeft() {
  servoLeft.write(95);
  servoRight.write(0);
  delay(1500);
  forward();
}

void stopRobot() {
  servoLeft.write(90);
  servoRight.write(86);
}

void lento() {
  servoLeft.write(100);
  servoRight.write(73);
}

void rapido() {
  servoLeft.write(180);
  servoRight.write(0);
}