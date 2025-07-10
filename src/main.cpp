#include <Arduino.h>
#include <Motor.h>
#include <Botao.h>

Botao botao_aumenta(2);
Botao botao_diminui(3);
Botao botao_mestre(4);

Motor motor;

void aumentarVelocidade();
void reduzirVelocidade();

void setup() {
  motor.atribuir(6, 7, 10);
  motor.ajustarVelocidade(48);
}

void loop() {
    if(botao_mestre.clicado()){
      motor.estaLigado() ? motor.desligar() : motor.ligar();
      // Alterna o estado do motor entre ligado e desligado
    }

    if(botao_aumenta.clicado()){
      motor.ajustarSentido(true);
    }

    if(botao_diminui.clicado()){
      motor.ajustarSentido(false);
    }
}