#ifndef BOTAO_H

#define BOTAO_H

#include <Arduino.h>

class Botao {

    public:
        Botao(int pino);
        // Construtor da classe Botao

        bool ler();
        bool clicado();

    private:
        int pino; // Pino do botão
        bool estado; // Estado atual do botão
        bool ultimoEstado; // Último estado do botão (liberado ou travado)
        int debounce; // Tempo de debounce em milissegundos
        unsigned long ultimoDebounce; // Tempo do último debounce
};


#endif