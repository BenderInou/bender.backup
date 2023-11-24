#include <NewPing.h>

#define TRIGGER_PIN  8  // Pin de disparo para los tres sensores
#define ECHO_PIN1   9  // Pin de eco del primer sensor
#define ECHO_PIN2    10  // Pin de eco del segundo sensor
#define ECHO_PIN3    13  // Pin de eco del tercer sensor
#define MAX_DISTANCE 200 // Distancia máxima en centímetros para medir

NewPing sonar1(TRIGGER_PIN, ECHO_PIN1, MAX_DISTANCE);  // Objeto del primer sensor
NewPing sonar2(TRIGGER_PIN, ECHO_PIN2, MAX_DISTANCE);  // Objeto del segundo sensor
NewPing sonar3(TRIGGER_PIN, ECHO_PIN3, MAX_DISTANCE);  // Objeto del tercer sensor

void setup() {
  Serial.begin(9600);  // Iniciar comunicación serie para imprimir por pantalla
}

void loop() {
  delay(50);  // Pequeña pausa para estabilizar las lecturas
  
  // Leer distancia del primer sensor
  unsigned int distance1 = sonar1.ping_cm();
  Serial.print("Distancia 1: ");
  Serial.print(distance1);
  Serial.println(" cm");
  
  // Leer distancia del segundo sensor
  unsigned int distance2 = sonar2.ping_cm();
  Serial.print("Distancia 2: ");
  Serial.print(distance2);
  Serial.println(" cm");
  
  // Leer distancia del tercer sensor
  unsigned int distance3 = sonar3.ping_cm();
  Serial.print("Distancia 3: ");
  Serial.print(distance3);
  Serial.println(" cm");
  
  Serial.println();  // Línea en blanco para separar las lecturas
  
  delay(500);  // Pequeña pausa antes de realizar la siguiente lectura
}