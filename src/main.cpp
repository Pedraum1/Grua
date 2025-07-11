#include <Arduino.h>
#include <Motor.h>
#include <Botao.h>

Botao botao_aumenta(2);
Botao botao_diminui(3);
Botao botao_mestre(4);

Motor motor;

void setup() {
  motor.atribuir(6, 7, 10);
  motor.ajustarVelocidade(48);
  motor.ajustarSentido(HORARIO);
}

void loop() {

  if(botao_aumenta.clicado()){
    if(motor.sentidoAtual() == PARADO){
      motor.ajustarSentido(HORARIO);
    }
    if(motor.sentidoAtual() == ANTI_HORARIO){
      motor.ajustarSentido(PARADO);
    }
  }

  if(botao_diminui.clicado()){
    if(motor.sentidoAtual() == PARADO){
      motor.ajustarSentido(ANTI_HORARIO);
    }
    if(motor.sentidoAtual() == HORARIO){
      motor.ajustarSentido(PARADO);
    }
  }

  if(botao_mestre.clicado()){
    if(motor.estaLigado()){
      motor.desligar();
    } else {
      motor.ligar();
    }
  }

}