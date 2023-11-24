



//    ___________________ UN SOLO TRIGGER ____________

// Definimos los pines a utilizar
const int Trigger = 25;
const int Echo1 = 13;
const int Echo2 = 27;
const int Echo3 = 26;
const int LedPin = 2;

// Función para obtener la distancia en cm
float getDistance(int triggerPin, int echoPin) {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration / 59.0;
  return distance;
}

// Función para actualizar los valores de las distancias y mostrarlos por Serial
void updateAndPrintDistances() {
  float distance1 = getDistance(Trigger, Echo1);
  float distance2 = getDistance(Trigger, Echo2);
  float distance3 = getDistance(Trigger, Echo3);
  Serial.print("Distancia 1: ");
  Serial.print(distance1);
  Serial.print(" cm, Distancia 2: ");
  Serial.print(distance2);
  Serial.print(" cm, Distancia 3: ");
  Serial.print(distance3);
  Serial.println(" cm");
}

// Función para encender o apagar un LED según la distancia
void controlLed(float distance) {
  if (distance <= 10) {
    digitalWrite(LedPin, HIGH);
  } else {
    digitalWrite(LedPin, LOW);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo1, INPUT);
  pinMode(Echo2, INPUT);
  pinMode(Echo3, INPUT);
  pinMode(LedPin, OUTPUT);
}

void loop() {
  updateAndPrintDistances();
  float distance1 = getDistance(Trigger, Echo1);
  float distance2 = getDistance(Trigger, Echo2);
  float distance3 = getDistance(Trigger, Echo3);
  controlLed(distance1);
   delayMicroseconds(10);
}
