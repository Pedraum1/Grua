#include <Arduino.h>
#include <Motor.h>
#include <Botao.h>

Botao botao_aumenta(2);
Botao botao_diminui(3);
Botao botao_mestre(4);

Motor motor;

void setup() {

  Serial.begin(9600);
  while(!Serial){}

  Serial.println("Iniciando o controle do motor...");
  
  motor.atribuir(6, 7, 10);
  motor.ajustarVelocidade(48);
  motor.ajustarSentido(HORARIO);

}

void loop() {

  if(botao_aumenta.clicado()){
    if(motor.sentidoAtual() == PARADO){
      motor.ajustarSentido(HORARIO);
      Serial.println("Girando motor no sentido horário.");
    }
    if(motor.sentidoAtual() == ANTI_HORARIO){
      motor.ajustarSentido(PARADO);
      Serial.println("Parando motor.");
    }
  }

  if(botao_diminui.clicado()){
    if(motor.sentidoAtual() == PARADO){
      motor.ajustarSentido(ANTI_HORARIO);
      Serial.println("Girando motor no sentido anti-horário.");
    }
    if(motor.sentidoAtual() == HORARIO){
      motor.ajustarSentido(PARADO);
      Serial.println("Parando motor.");
    }
  }

  if(botao_mestre.clicado()){
    if(motor.estaLigado()){
      motor.desligar();
      Serial.println("Desligando motor.");
    } else {
      motor.ligar();
      Serial.println("Ligando motor.");
    }
  }

}