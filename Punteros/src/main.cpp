#include <Arduino.h>

int numero = 10;

void duplicar(int *puntero){
  *puntero = *puntero*2;
  Serial.println("{duplicar} numero ="+String(*puntero)); 
}

void setup() {
    Serial.begin(115200);
}

void loop() {
  Serial.println("numero = "+String(numero));
  duplicar(&numero);
  delay(1000);
}


