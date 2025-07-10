# Grua de Construção Civil - Arduino Uno

Este projeto consiste em um algoritmo desenvolvido para o Arduino Uno, no qual o microcontrolador atua como sistema de controle para o protótipo de uma grua de construção civil. O protótipo faz parte de um trabalho da disciplina de Mecânica das Máquinas do curso de Engenharia Mecatrônica do IFCE - Campus Fortaleza.

## Objetivo

Controlar, por meio do Arduino Uno, os movimentos de uma grua de construção civil em escala reduzida, utilizando entradas e saídas digitais e analógicas para o controle dos motores através de ponte H e comandos simples para o operador.

## Pinos do Microcontrolador

### Entradas Digitais

- 4 entradas para controle de motores
- 1 entrada para pino de reset externo

### Entradas Analógicas

- 2 entradas analógicas para controle de potência por trimpot

### Saídas Digitais

- 4 saídas digitais para controle de sentido de rotação dos motores
- 2 saídas digitais com PWM para controle de velocidade dos motores

## Como usar

1. Instale o [PlatformIO](https://platformio.org/) no VSCode.
2. Conecte o Arduino Uno ao computador.
3. Compile e faça o upload do código localizado em [`src/main.cpp`](src/main.cpp) para o Arduino.

## Requisitos

- Arduino Uno
- Protótipo da grua
- VSCode com PlatformIO

---

Projeto acadêmico - IFCE