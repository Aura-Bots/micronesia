#pragma once
#include <Arduino.h>
#include "eletronica/configuracoes.hpp"

enum Estados {
    DESARMADO,
    ARMADO,
    ESTRATEGIA_INICIAL_PRIMARIA,
    ESTRATEGIA_INICIAL_SECUNDARIA,
    ESTRATEGIA_INICIAL_TERCIARIA,
    ESTRATEGIA_BUSCA,
    ESTRATEGIA_PERSEGUICAO,
    ESTRATEGIA_BUSCA_POS_PERSEGUICAO
};

bool delayEstrategia(int tempo) {
    tempo *= 1000;
    unsigned long tempoInicial = micros();

    while (micros() - tempoInicial < tempo) {
        if (leituraModStart == LOW) {
            return true;
        }
    }

    return false;
}

// Full Frente
float velocidadeFullFrente = 0.5f;
int tempoFullFrente        = 400;