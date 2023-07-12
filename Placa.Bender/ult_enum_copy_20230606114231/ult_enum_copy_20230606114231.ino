const int Trigger = 25;
const int Echo1 = 13;
const int Echo2 = 27;
const int Echo3 = 26;
const int LedPin = 2;

// Declaramos la enumeración que nos indica el estado del robot
enum EstadoROBOT {
	busqueda_,
	ataque_,
	evadir_,
	izquierda_,
  derecha_,
};
 
// Declaramos una variable que almacenará el estado del robot
EstadoROBOT ESTADO;







// Función para obtener la distancia en cm
float getDistance(int triggerPin, int echoPin) {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  long duracion = pulseIn(echoPin, HIGH);
  float distancia = duracion / 59.0;
  return distancia;
}

// Función para actualizar los valores de las distancias y mostrarlos por Serial
void updateAndPrintDistances() {
  float distancia_ult_1 = getDistance(Trigger, Echo1);
  float distancia_ult_2 = getDistance(Trigger, Echo2);
  float distancia_ult_3 = getDistance(Trigger, Echo3);
  Serial.print("Distancia 1: ");
  Serial.print(distancia_ult_1);
  Serial.print(" cm, Distancia 2: ");
  Serial.print(distancia_ult_2);
  Serial.print(" cm, Distancia 3: ");
  Serial.print(distancia_ult_3);
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
  Serial.begin(115200);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo1, INPUT);
  pinMode(Echo2, INPUT);
  pinMode(Echo3, INPUT);
  pinMode(LedPin, OUTPUT);
}

void loop() {
  updateAndPrintDistances();
  float distancia_ult_1 = getDistance(Trigger, Echo1);
  float distancia_ult_2 = getDistance(Trigger, Echo2);
  float distancia_ult_3 = getDistance(Trigger, Echo3);
  controlLed(distancia_ult_1);

}
