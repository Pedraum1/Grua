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

    if(botao_aumenta.ler()){
      aumentarVelocidade();
    }

    if(botao_diminui.ler()){
      reduzirVelocidade();
    }
}

void aumentarVelocidade() {
  int velocidadeAtual = motor.velocidadeAtual();

  velocidadeAtual++;
  if (velocidadeAtual > LIMITE_SUPERIOR_PWM) {
    velocidadeAtual = LIMITE_SUPERIOR_PWM; // Limite superior
  }
  motor.ajustarVelocidade(velocidadeAtual);
}

void reduzirVelocidade() {
  int velocidadeAtual = motor.velocidadeAtual();

  velocidadeAtual--;
  if (velocidadeAtual < LIMITE_INFERIOR_PWM) {
    velocidadeAtual = LIMITE_INFERIOR_PWM; // Limite inferior
  }
  motor.ajustarVelocidade(velocidadeAtual);
}