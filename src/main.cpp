#include <Arduino.h>
#include "Motor.h"

Motor motor;

void setup() {
  motor.atribuir(6, 7, 10);   // Pinos do motor do cabo
}

void loop() {
  motor.ligar();

  motor.ajustarVelocidade(128); // Ajusta a velocidade do motor
  delay(2000); // Mantém o motor ligado por 2 segundos

  motor.desligar(); // Desliga o motor
  delay(2000); // Espera 2 segundos antes de repetir
  
  motor.trocarSentido(); // Troca o sentido do motor
}