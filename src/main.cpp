#include <Arduino.h>
#include "eletronica/configuracoes.hpp"
#include "locomocao/configuracoes.hpp"

void setup() {
    pinMode(PINO_LED, OUTPUT);
    pinMode(PINO_MOD_START, INPUT);
}

void loop() {
    if (leituraModStart == HIGH) {
        digitalWrite(PINO_LED, HIGH);
        
        
    }

    else {
        digitalWrite(PINO_LED, LOW);
        motorDireito.parar();
        motorEsquerdo.parar();
    }
}