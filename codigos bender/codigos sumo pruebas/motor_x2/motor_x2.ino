int IN1 = 2;      // IN1 de L298N a pin digital 2
int IN2 = 3;      // IN2 de L298N a pin digital 3
int ENA = 5;      // ENA de L298N a pin digital 5
int VELOCIDAD;      // variable para almacenar valor de velocidad

void setup(){
  pinMode(IN1, OUTPUT);   // pin 2 como salida
  pinMode(IN2, OUTPUT);   // pin 3 como salida  
  pinMode(ENA, OUTPUT);   // pin 5 como salida
}

void loop(){

  for (VELOCIDAD = 0; VELOCIDAD < 256; VELOCIDAD++){  // bucle que incrementa de a uno
  analogWrite(ENA, VELOCIDAD);        // el valor de velocidad y aplica a ENA
  digitalWrite(IN1, LOW);       // IN1 en 0
  digitalWrite(IN2, HIGH);        // IN2 en 1
  delay(50);            // demora de 50 mseg. por cada iteracion
  }

  digitalWrite(ENA, LOW); // ENA en 0 para deshabilitar motor
  delay(2000);      // demora de 2 seg.

  for (VELOCIDAD = 0; VELOCIDAD < 256; VELOCIDAD++){  // bucle que incrementa de a uno
  analogWrite(ENA, VELOCIDAD);        // el valor de velocidad y aplica a ENA
  digitalWrite(IN1, HIGH);        // IN1 en 1
  digitalWrite(IN2, LOW);       // IN2 en 0
  delay(50);            // demora de 50 mseg. por cada iteracion
  }

  digitalWrite(ENA, LOW); // ENA en 0 para deshabilitar motor
  delay(2000);      // demora de 2 seg.
}
