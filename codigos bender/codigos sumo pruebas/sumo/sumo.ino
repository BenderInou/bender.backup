#define Trigger 2
#define Trigger2 33
#define Trigger3 5//Pin digital 2 para el Trigger del sensor3
#define Echo  4
#define Echo2  24  //Pin digital 3 para el echo del sensor
#define Echo3 12  //Pin digital 3 para el echo del sensor
#define led 26
long t2;
float d2;
long t;
float d;
long t3;
float d3;


void setup() {
  Serial.begin(115200);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT);
  pinMode(Trigger2, OUTPUT);
  pinMode(Trigger3, OUTPUT);//pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  pinMode(Echo2, INPUT);  //pin como entrada
  pinMode(Echo3, INPUT);  //pin como entrada
  pinMode(led, OUTPUT);
}
void loop () {

  digitalWrite(Trigger, LOW);//Inicializamos el pin
  delayMicroseconds(2);          //Enviamos un pulso de 2us
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  digitalWrite(Trigger2, LOW);//Inicializamos el pin
  delayMicroseconds(2);          //Enviamos un pulso de 2us
  digitalWrite(Trigger2, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger2, LOW);
  digitalWrite(Trigger3, LOW);//Inicializamos el pin
  delayMicroseconds(2);          //Enviamos un pulso de 2us
  digitalWrite(Trigger3, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger3, LOW);

  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t / 59;            //escalamos el tiempo a una distancia en cm
  t2 = pulseIn(Echo2, HIGH); //obtenemos el ancho del pulso
  d2 = t2 / 59;            //escalamos el tiempo a una distancia en cm
  t3 = pulseIn(Echo3, HIGH); //obtenemos el ancho del pulso
  d3 = t3 / 59;            //escalamos el tiempo a una distancia en cm

  Serial.print("Distancia: ");
  Serial.print( d ) ;      //Enviamos serialmente el valor de la distancia
  Serial.print("cm ");
  Serial.print("Distancia2: ");
  Serial.print( d2 ) ;      //Enviamos serialmente el valor de la distancia
  Serial.print("cm ");
  Serial.print("Distancia3: ");
  Serial.print( d3 ) ;      //Enviamos serialmente el valor de la distancia
  Serial.print("cm ");
  Serial.println();
  delay(100);          //Hacemos una pausa de 1000ms

// if (d > 3 && d2 > 3 && d3 > 3) {
  //  digitalWrite(led, HIGH);
  }
