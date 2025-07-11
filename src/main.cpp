#include <Arduino.h>
#include <Motor.h>
#include <Botao.h>

Botao botao_aumenta(2);
Botao botao_diminui(3);
Botao botao_reset(4);

Motor motor;

void setup() {
  motor.atribuir(6, 7, 10);
  motor.ajustarVelocidade(48);
}

void loop() {

    if(botao_aumenta.clicado()){
      if(!motor.sentidoAtual()){  //se o motor estiver girando no sentido anti-horário

        if(motor.estaLigado()) motor.desligar(); //desliga o motor        
        motor.trocarSentido();    //troca o sentido do motor para horário
        //aguarda que o operador clique novamente no botão para ligar o motor
      } else {
        if(!motor.estaLigado()) motor.ligar(); //liga o motor
      }
    }

    if(botao_diminui.clicado()){
      if(motor.sentidoAtual()){  //se o motor estiver girando no sentido horário

        if(motor.estaLigado()) motor.desligar(); //desliga o motor        
        motor.trocarSentido();    //troca o sentido do motor para anti-horário
        //aguarda que o operador clique novamente no botão para ligar o motor
      } else {
        if(!motor.estaLigado()) motor.ligar(); //liga o motor
      }
    }

    if(botao_reset.clicado()){
      motor.desligar();
    }

}