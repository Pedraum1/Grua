#include "Botao.h"

//=========================PÚBLICAS===============================

// Construtor da classe Botao
Botao::Botao(int pino) {
    this->pino = pino;
    pinMode(this->pino, INPUT_PULLUP); // Configura o pino como entrada com pull-up interno

    // Inicializa os estados do botão
    this->estado = false;
    this->ultimoEstado = false;
}

bool Botao::ler() {
    // Retorna verdadeiro se o botão estiver pressionado
    return digitalRead(this->pino) == LOW;
}

bool Botao::clicado() {

    //Se o botão foi pressionado e o último estado era liberado
    if(this->ler() && !this->ultimoEstado) {
        this->estado = true;        // Botão pressionado
        this->ultimoEstado = true;  // Atualiza o último estado para pressionado
    }

    //Se o botão foi solto e o último estado era travado
    if (!this->ler() && this->ultimoEstado ){
        this->ultimoEstado = false; // Botão liberado
        return true;                // Retorna verdadeiro se o ciclo (clique) foi feito
    }

    return false; // Retorna falso se o botão não foi clicado
}

