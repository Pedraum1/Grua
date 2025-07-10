#include "Motor.h"

//=========================PÚBLICAS===============================


// FUNÇÕES DE SETUP DO MOTOR

Motor::Motor(){
    // Construtor da classe Motor

    // Inicializa os atributos do motor
    this->ligado = false;
    this->velocidade = 0;
    this->sentido = true;
    // true = sentido horario
    // false = sentido anti-horario

    this->pino_positivo = -1;
    this->pino_negativo = -1;
    this->pino_pwm = -1;

}

void Motor::atribuir(int pino1, int pino2, int pino3){
    // Atribui os pinos de controle do motor
    this->pino_positivo = pino1;
    this->pino_negativo = pino2;
    this->pino_pwm = pino3;

    if(!this->verificarPinos()){
        this->pino_positivo = pino1;
        this->pino_negativo = pino2;
        this->pino_pwm = pino3;

        return;
    }

    // Configura os pinos como saída
    pinMode(this->pino_pwm, OUTPUT);
    pinMode(this->pino_positivo, OUTPUT);
    pinMode(this->pino_negativo, OUTPUT);
}

// FUNÇÕES DE CONTROLE DO MOTOR

void Motor::ligar(){
    if(!this->verificarPinos()) return;

    if(this->ligado) return;

    // Ligando o motor
    this->ligado = true;

    this->ajustarSentido(this->sentido);
    this->ajustarVelocidade(this->velocidade);
}

void Motor::desligar(){
    if(!this->verificarPinos()) return;
    
    if(!this->ligado) return;

    // Desligando o motor
    this->ligado = false;
    digitalWrite(this->pino_positivo, LOW);
    digitalWrite(this->pino_negativo, LOW);
    analogWrite(this->pino_pwm, 0); // Desliga o PWM
}

void Motor::ajustarVelocidade(int velocidade){
    if(!this->verificarPinos()) return;

    if(velocidade < LIMITE_INFERIOR_PWM || velocidade > LIMITE_SUPERIOR_PWM){
        return; // Velocidade inválida
    }
    this->velocidade = velocidade;

    if(this->ligado){
        // Se o motor estiver ligado, ajusta a velocidade
        analogWrite(this->pino_pwm, this->velocidade);
    }
}

void Motor::ajustarSentido(bool sentido){
    
    if(!this->verificarPinos()) return;

    this->sentido = sentido;

    if(this->ligado){
        // Se o motor estiver ligado, troca o sentido
        if(this->sentido){
            // Se o sentido for horario, ativa o pino positivo
            digitalWrite(pino_negativo, LOW);
            digitalWrite(pino_positivo, HIGH);
        } else {
            // Se o sentido for anti-horario, ativa o pino negativo
            digitalWrite(this->pino_positivo, LOW);
            digitalWrite(this->pino_negativo, HIGH);
        }
    }
}

void Motor::trocarSentido(){
    if(!this->verificarPinos()) return;
    
    // Troca o sentido do motor
    this->sentido = !this->sentido; // Inverte o sentido
    this->ajustarSentido(this->sentido); // Ajusta o sentido
}

int Motor::velocidadeAtual(){
    // Retorna a velocidade atual do motor
    if(!this->verificarPinos()) return -1;
    return this->velocidade;
}

bool Motor::estaLigado(){
    // Retorna se o motor está ligado ou não
    if(!this->verificarPinos()) return false;
    return this->ligado;
}

//=========================PRIVADAS===============================

bool Motor::verificarPinos(){
    // Verifica se os pinos foram atribuídos corretamente

    if(this->pino_positivo == -1 || this->pino_negativo == -1 || this->pino_pwm == -1){
        return false; // Pinos não atribuídos
    }

    if(this->pino_positivo == this->pino_negativo ||
       this->pino_positivo == this->pino_pwm ||
       this->pino_negativo == this->pino_pwm){
        return false; // Pinos iguais
    }

    return true; // Pinos válidos
}