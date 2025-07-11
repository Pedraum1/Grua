#ifndef MOTOR_H
#define MOTOR_H

#define LIMITE_INFERIOR_PWM 48
#define LIMITE_SUPERIOR_PWM 255

#include <Arduino.h>

class Motor {
    public:
        Motor();
        void atribuir(int pino1, int pino2, int pino3);
        void ligar();
        void desligar();
        void ajustarVelocidade(int velocidade);
        void ajustarSentido(bool sentido);
        void trocarSentido();
        int velocidadeAtual();
        bool sentidoAtual();

        bool estaLigado();
    
    private:
        bool ligado;
        int velocidade;
        bool sentido;
        int pino_positivo;
        int pino_negativo;
        int pino_pwm;

        // Função auxiliar para verificar se os pinos estão configurados corretamente
        bool verificarPinos();
};

#endif