#define PIN_CNY_IZQ 39
#define PIN_CNY_CENTRO 35
#define PIN_CNY_DER 34

// Para activar el DEBUG colocar en estado 1. En 0 esta desactivado
#define DEBUG 1

int Lectura_CNY_IZQ;
int Lectura_CNY_CENTRO;
int Lectura_CNY_DER;

void setup() {

 pinMode(PIN_CNY_IZQ, INPUT);
 pinMode(PIN_CNY_CENTRO, INPUT);
 pinMode(PIN_CNY_DER, INPUT);

if(DEBUG){Serial.begin(9600); }//Configuracion de la velocidad serial
}


void loop() {

Lectura_CNY_IZQ = analogRead(PIN_CNY_IZQ);
Lectura_CNY_CENTRO = analogRead(PIN_CNY_IZQ);
Lectura_CNY_DER = analogRead(PIN_CNY_IZQ);

if(DEBUG){  Serial.print("Lectura: ");
             Serial.print(Lectura_CNY_IZQ);} 
if(DEBUG){  Serial.print("      Lectura: ");
             Serial.print(Lectura_CNY_CENTRO);} 
if(DEBUG){  Serial.print("      Lectura: ");
             Serial.println(Lectura_CNY_DER);} 
             
           
             //Imprime el valor de la lectura del canal A0
  delay(500); //retardo de 2 segundos entre lectura
}