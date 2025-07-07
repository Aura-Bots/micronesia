#include <Arduino.h>
#include "eletronica/configuracoes.hpp"
#include "locomocao/configuracoes.hpp"
#include "comunicacao/ble.hpp"

void setup() {
    initBLE();

    pinMode(PINO_LED, OUTPUT);
    pinMode(PINO_MOD_START, INPUT);
}

void loop() {
    BLE.pool()

    if (leituraModStart == HIGH) {
        digitalWrite(PINO_LED, HIGH);

        if (estadoAtual == ESTRATEGIA_INICIAL_PRIMARIA) {
            executarEstragiaInicial();
            
        }
        
        
    }

    else {
        digitalWrite(PINO_LED, LOW);
        motorDireito.parar();
        motorEsquerdo.parar();
    }
}