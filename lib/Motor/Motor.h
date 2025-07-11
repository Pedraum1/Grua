#ifndef MOTOR_H
#define MOTOR_H

#define LIMITE_INFERIOR_PWM 48
#define LIMITE_SUPERIOR_PWM 255

#include <Arduino.h>

typedef enum {
    ANTI_HORARIO = -1,
    PARADO = 0,
    HORARIO = 1
} Direcao;

class Motor {
    public:
        Motor();
        void atribuir(int pino1, int pino2, int pino3);
        void ligar();
        void desligar();
        void ajustarVelocidade(int velocidade);
        void ajustarSentido(Direcao sentido);
        void trocarSentido();
        int velocidadeAtual();
        Direcao sentidoAtual();

        bool estaLigado();
    
    private:
        bool ligado;
        int velocidade;
        Direcao sentido;

        int pino_positivo;
        int pino_negativo;
        int pino_pwm;

        // Função auxiliar para verificar se os pinos estão configurados corretamente
        bool verificarPinos();
};

#endif