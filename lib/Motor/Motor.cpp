#include "Motor.h"

//=========================PÚBLICAS===============================


// FUNÇÕES DE SETUP DO MOTOR

Motor::Motor(){
    // Construtor da classe Motor

    // Inicializa os atributos do motor
    ligado = false;
    velocidade = 0;
    sentido = true;
    // true = sentido horario
    // false = sentido anti-horario

    pino_positivo = -1;
    pino_negativo = -1;

}

void Motor::atribuir(int pino1, int pino2, int pino3){
    // Atribui os pinos de controle do motor
    pino_positivo = pino1;
    pino_negativo = pino2;
    pino_pwm = pino3;

    // Configura os pinos como saída
    pinMode(pino_pwm, OUTPUT);
    pinMode(pino_positivo, OUTPUT);
    pinMode(pino_negativo, OUTPUT);
}

// FUNÇÕES DE CONTROLE DO MOTOR

void Motor::ligar(){
    if(this->ligado){
        return;
    }

    if(!this->verificarPinos()){
        return;
    }

    // Ligando o motor
    this->ligado = true;

    this->ajustarSentido(this->sentido);
    this->ajustarVelocidade(this->velocidade);
}

void Motor::desligar(){
    
    if(!this->ligado){
        return;
    }

    if(!this->verificarPinos()){
        return;
    }

    // Desligando o motor
    this->ligado = false;
    digitalWrite(pino_positivo, LOW);
    digitalWrite(pino_negativo, LOW);
}

void Motor::ajustarVelocidade(int velocidade){
    if(velocidade < 0 || velocidade > 255){
        return; // Velocidade inválida
    }
    this->velocidade = velocidade;

    if(this->ligado){
        // Se o motor estiver ligado, ajusta a velocidade
        analogWrite(pino_pwm, this->velocidade);
    }
}

void Motor::ajustarSentido(bool sentido){
    
    if(!this->verificarPinos()){
        return; // Pinos inválidos
    }

    this->sentido = sentido;

    if(this->ligado){
        // Se o motor estiver ligado, troca o sentido
        if(this->sentido){
            // Se o sentido for horario, ativa o pino positivo
            digitalWrite(pino_positivo, HIGH);
            digitalWrite(pino_negativo, LOW);
        } else {
            // Se o sentido for anti-horario, ativa o pino negativo
            digitalWrite(pino_positivo, LOW);
            digitalWrite(pino_negativo, HIGH);
        }
    }
}

void Motor::trocarSentido(){
    if(!this->verificarPinos()){
        return; // Pinos inválidos
    }
    // Troca o sentido do motor
    this->sentido = !this->sentido; // Inverte o sentido
    this->ajustarSentido(this->sentido); // Ajusta o sentido
}

//=========================PRIVADAS===============================

bool Motor::verificarPinos(){
    // Verifica se os pinos foram atribuídos corretamente

    if(pino_positivo == -1 || pino_negativo == -1){
        return false; // Pinos não atribuídos
    }

    if(pino_positivo == pino_negativo){
        return false; // Pinos iguais
    }

    return true; // Pinos válidos
}