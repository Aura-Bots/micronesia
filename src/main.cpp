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
    switch (lerModStart()) {
        case HIGH:
            digitalWrite(PINO_LED, HIGH);

        case LOW:
            digitalWrite(PINO_LED, LOW);
            motorDireito.parar();
            motorEsquerdo.parar();
            break;
    }
}