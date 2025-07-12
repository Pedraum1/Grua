#include "Botao.h"

//=========================PÚBLICAS===============================

// Construtor da classe Botao
Botao::Botao(int pino) {
    this->pino = pino;
    pinMode(this->pino, INPUT_PULLUP); // Configura o pino como entrada com pull-up interno

    // Inicializa os estados do botão
    this->estado = false;
    this->ultimoEstado = false;
    this->debounce = 50;
}

bool Botao::ler() {
    // Retorna verdadeiro se o botão estiver pressionado
    return digitalRead(this->pino) == LOW;
}

bool Botao::clicado() {
    unsigned long tempoAtual = millis();

    //Se o botão foi pressionado e o último estado era liberado
    if(this->ler() && !this->ultimoEstado) {
        if(tempoAtual - this->ultimoDebounce > this->debounce){
            this->estado = true;
            this->ultimoEstado = true;
            this->ultimoDebounce = tempoAtual;
        }
    }

    //Se o botão foi solto e o último estado era travado
    if (!this->ler() && this->ultimoEstado ){
        if(tempoAtual - this->ultimoDebounce > this->debounce){
            this->ultimoEstado = false; // Botão liberado
            this->ultimoDebounce = tempoAtual; // Atualiza o tempo do último debounce
            return true;    // Retorna verdadeiro se o ciclo (clique) foi feito
        }
    }

    return false; // Retorna falso se o botão não foi clicado
}

