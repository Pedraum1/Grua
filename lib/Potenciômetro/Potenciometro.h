#ifndef POTENCIOMETRO_H
#define POTENCIOMETRO_H

#include <Arduino.h>

class Potenciometro {
    public:
        Potenciometro(int pino);
        int ler();
        float mapear(int novoMinimo, int novoMaximo);
        
    private:
        int pino;
};

#endif