#include  "Arduino.h"
#include "BluetoothSerial.h"
#include  "analogWrite.h"

// Definición de pines

#define Motor1a  22
#define Motor1b  21
#define Motor2a  19
#define Motor2b  18
#define ENA_A  23
#define ENA_B  17

int Velocidad = 0;

BluetoothSerial BT;

void callback_function(esp_spp_cb_event_t event, esp_spp_cb_param_t *param) {
  if (event == ESP_SPP_START_EVT) {
    Serial.println("Inicializado SPP");
  }
  else if (event == ESP_SPP_SRV_OPEN_EVT ) {
    Serial.println("Cliente conectado");
  }
  else if (event == ESP_SPP_CLOSE_EVT  ) {
    Serial.println("Cliente desconectado");
  }
  else if (event == ESP_SPP_DATA_IND_EVT ) {
    Serial.println("Datos recibidos"); 
    while (BT.available()) { // Mientras haya datos por recibir
      int incoming = BT.read(); // Lee un byte de los datos recibidos
    }
  }
}


void setup() {
  BT.begin("ESP32_bender "); // Nombre de tu Dispositivo Bluetooth y en modo esclavo
  Serial.println("El dispositivo Bluetooth está listo para emparejar");
  BT.register_callback(callback_function); // Registramos la función "callback_function" como función callback.
   
  // Configuración de los pines del controlador LM289N
  pinMode(Motor1a, OUTPUT);
  pinMode(Motor1b, OUTPUT);
  pinMode(Motor2a, OUTPUT);
  pinMode(Motor2b, OUTPUT);
   Serial.begin(9600); // Inicializando la conexión serial para debug

}

void loop() {  
  if (BT.available()) // Compruebe si recibimos algo de Bluetooth
  {
    int incoming = BT.read(); // Lee lo que recibimos
    Serial.print("Recibido: ");
    Serial.println(incoming);
    
    switch(incoming){
      case 70: // F en ASCII
       { Adelante();
           Serial.print("Adelante");
          incoming=0;
       }break;

      case 66: // B en ASCII
       {Retroceder();
       Serial.print("Retroceder");
        incoming=0;
       }break;

      case 76: // L en ASCII
       {Izquierda();
       Serial.print("Izquierda"); 
        incoming=0;
       }break;

      case 82: // R en ASCII
       {Derecha();
       Serial.print("Derecha");
        incoming=0;
       }break;

             case 51: // R en ASCII
       {
        Velocidad=Velocidad+85;
        if(Velocidad>255){Velocidad=255;}
       Serial.println(Velocidad);
        incoming=0;
       }break;

             case 49: // R en ASCII
       {
         Velocidad=Velocidad-85;
         if(Velocidad<0){Velocidad=0;}
       Serial.println(Velocidad);
        incoming=0;
       }break;
     
      default:
        {Parar(); 
        Serial.print("Parado");
        }break; }
  }
}


void Adelante() {

  analogWrite(ENA_A, Velocidad);
  digitalWrite(Motor1a , HIGH);
  digitalWrite(Motor1b, LOW);
  digitalWrite(Motor2a,HIGH);
  digitalWrite(Motor2b, LOW);
   analogWrite(ENA_B, Velocidad);
}


void Retroceder() {
  analogWrite(ENA_A , Velocidad );
  digitalWrite(Motor1a , LOW);
  digitalWrite(Motor1b, HIGH);
  digitalWrite(Motor2a, LOW);
  digitalWrite(Motor2b, HIGH);
  analogWrite(ENA_B , Velocidad);
}
void Izquierda() {
  analogWrite(ENA_A , Velocidad);
  digitalWrite(Motor1a, LOW);
  digitalWrite(Motor1b, HIGH);
  digitalWrite(Motor2a, HIGH);
  digitalWrite(Motor2b, LOW);
  analogWrite(ENA_B , Velocidad);
}
void Derecha() {
  analogWrite(ENA_A , Velocidad);
  digitalWrite(Motor1a, HIGH);
  digitalWrite(Motor1b, LOW);
  digitalWrite(Motor2a, LOW);
  digitalWrite(Motor2b, HIGH);
  analogWrite(ENA_B , Velocidad);
}
void Parar() {
  analogWrite(ENA_A , Velocidad);
  digitalWrite(Motor1a, LOW);
  digitalWrite(Motor1b, LOW);
  digitalWrite(Motor2a, LOW);
  digitalWrite(Motor2b, LOW);
  analogWrite(ENA_B , Velocidad);
}

