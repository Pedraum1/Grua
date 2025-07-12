#include "Potenciometro.h"

Potenciometro::Potenciometro(int pino){
    this->pino = pino;
    pinMode(pino, INPUT);
}

int Potenciometro::ler() {
    return analogRead(pino);
}

float Potenciometro::mapear(int novoMinimo, int novoMaximo) {
    int valorLido = ler();
    return map(valorLido, 0, 1023, novoMinimo, novoMaximo);
}