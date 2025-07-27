#include <Arduino.h>
#include <Motor.h>
#include <Botao.h>
#include <Potenciometro.h>

Botao botao_1_cabo(2);
Botao botao_2_cabo(3);
Botao botao_1_trolley(4);
Botao botao_2_trolley(5);

Potenciometro potenciometro_cabo(A0); // Pino do potenciômetro do cabo
Potenciometro potenciometro_trolley(A1); // Pino do potenciômetro do carrinho

Motor motor_trolley;
Motor motor_cabo;

float colherVelocidade() {
  return potenciometro_cabo.mapear(48, 230);
  return potenciometro_trolley.mapear(48, 230);
}

void setup() {

  Serial.begin(9600);
  Serial.print("Iniciando o controle dos motores");
  
  while(!Serial){ Serial.print(" ."); }
  Serial.println(" Conexão estabelecida!");
  
  motor_cabo.atribuir(6, 7, 10);
  motor_trolley.atribuir(8, 9, 11);

  motor_cabo.ajustarVelocidade(colherVelocidade());
  motor_trolley.ajustarVelocidade(colherVelocidade());

  motor_cabo.ajustarSentido(HORARIO);
  motor_trolley.ajustarSentido(HORARIO);

  motor_trolley.ligar();
  motor_cabo.ligar();
}

void loop() {

  //================VELOCIDADE================

  if(motor_cabo.estaLigado()){
    motor_cabo.ajustarVelocidade(colherVelocidade());
  }
  if(motor_trolley.estaLigado()){
    motor_trolley.ajustarVelocidade(colherVelocidade());
  }

  //================CABO================

  if(botao_1_cabo.clicado()){
    if(!motor_cabo.estaLigado()){
      return;
    }

    if(motor_cabo.sentidoAtual() == PARADO){
      motor_cabo.ajustarSentido(HORARIO);
      Serial.print("Girando motor do cabo no sentido horário.");
      Serial.print(" Velocidade atual: ");
      Serial.println(motor_cabo.velocidadeAtual());
    }
    if(motor_cabo.sentidoAtual() == ANTI_HORARIO){
      motor_cabo.ajustarSentido(PARADO);
      Serial.println("Parando motor do cabo.");
    }
  }

  if(botao_2_cabo.clicado()){
    if(!motor_cabo.estaLigado()){
      return;
    }
    
    if(motor_cabo.sentidoAtual() == PARADO){
      motor_cabo.ajustarSentido(ANTI_HORARIO);
      Serial.print("Girando motor do cabo no sentido anti-horário.");
      Serial.print(" Velocidade atual: ");
      Serial.println(motor_cabo.velocidadeAtual());
    }
    if(motor_cabo.sentidoAtual() == HORARIO){
      motor_cabo.ajustarSentido(PARADO);
      Serial.println("Parando motor do cabo.");
    }
  }

  //================CARRO TROLLEY================

  if(botao_1_trolley.clicado()){
    if(!motor_trolley.estaLigado()){
      return;
    }

    if(motor_trolley.sentidoAtual() == PARADO){
      motor_trolley.ajustarSentido(HORARIO);
      Serial.print("Girando motor do carro no sentido horário.");
      Serial.print(" Velocidade atual: ");
      Serial.println(motor_trolley.velocidadeAtual());
    }
    if(motor_trolley.sentidoAtual() == ANTI_HORARIO){
      motor_trolley.ajustarSentido(PARADO);
      Serial.println("Parando motor do carro.");
    }
  }

  if(botao_2_trolley.clicado()){
    if(!motor_trolley.estaLigado()){
      return;
    }
    
    if(motor_trolley.sentidoAtual() == PARADO){
      motor_trolley.ajustarSentido(ANTI_HORARIO);
      Serial.print("Girando motor do carro no sentido anti-horário.");
      Serial.print(" Velocidade atual: ");
      Serial.println(motor_trolley.velocidadeAtual());
    }
    if(motor_trolley.sentidoAtual() == HORARIO){
      motor_trolley.ajustarSentido(PARADO);
      Serial.println("Parando motor do carro.");
    }
  }

}