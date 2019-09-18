#include <ESP8266WebServer.h>

/* Set these to your desired credentials. */ 
const char *ssid = "Autito";

ESP8266WebServer server(80);

void setup(){
  Serial.begin(9600); //inicio la comunicacion en serie
  delay(1000); 
  WiFi.softAP(ssid); 
  server.on("/", handleRoot); 
  server.on("/1", adelante);
  server.on("/2", atras);
  server.on("/3", izquierda);
  server.on("/4", derecha);
  server.on("/5", parar);
  server.begin();
}

void loop(){ 

  server.handleClient();
}

void handleRoot(){

  char temp[400];

  snprintf(temp, 400,
    "<html>\
  <head>\
  </head>\
    <body>\
    <h1>Bienvenido al autito, ingrese el comando que desea:</h1>\
    <a href =\"/1\"> <button> Adelante</button> </a>\
    <a href =\"/2\"> <button> Atras</button> </a>\
    <a href =\"/3\"> <button> Izquierda</button> </a>\
    <a href =\"/4\"> <button> Derecha</button> </a>\
    <a href =\"/5\"> <button> Parar</button> </a>\
  </body>\
</html>");
  server.send(200, "text/html", temp);
}

void adelante() {
  Serial.write("Adelante"); 
  //PARA REDIRECCIONAR A LA PAGINA PRINCIPAL LUEGO DE APRETAR CADA BOTON
  server.sendHeader("Location", String("/"), true);
  server.send ( 302, "text/plain", "");
}

void atras() {
  Serial.write("Atras"); 
  //PARA REDIRECCIONAR A LA PAGINA PRINCIPAL LUEGO DE APRETAR CADA BOTON
  server.sendHeader("Location", String("/"), true);
  server.send ( 302, "text/plain", "");
}

void izquierda() {
  Serial.write("Izquierda");
   //PARA REDIRECCIONAR A LA PAGINA PRINCIPAL LUEGO DE APRETAR CADA BOTON
  server.sendHeader("Location", String("/"), true);
  server.send ( 302, "text/plain", "");
}

void derecha() {
  Serial.write("Derecha");
   //PARA REDIRECCIONAR A LA PAGINA PRINCIPAL LUEGO DE APRETAR CADA BOTON
  server.sendHeader("Location", String("/"), true);
  server.send ( 302, "text/plain", "");
}

void parar() {
  Serial.write("Parar");
   //PARA REDIRECCIONAR A LA PAGINA PRINCIPAL LUEGO DE APRETAR CADA BOTON
  server.sendHeader("Location", String("/"), true);
  server.send ( 302, "text/plain", "");
}
