#pragma once
#include <Arduino.h>
#include "pinagem.hpp"

int leituraModStart = digitalRead(PINO_MOD_START);

enum Sensores {
    SENSOR_LATERAL_DIR,
    SENSOR_FRONTAL,
    SENSOR_LATERAL_ESQ,
    SENSOR_BORDA
};

int pinosSensores[] = {
    PINO_SENSOR_LATERAL_DIR,
    PINO_SENSOR_FRONTAL,
    PINO_SENSOR_LATERAL_ESQ,
    PINO_SENSOR_BORDA
};

int leituraSensores[] = {0, 0, 0, 0};

void initSensores() {
    for (int i = 0; i < sizeof(pinosSensores) / sizeof(pinosSensores[0]); i++) {
        pinMode(pinosSensores[i], INPUT);
    }
}

void lerSensores() {
    for (int i = 0; i < sizeof(pinosSensores) / sizeof(pinosSensores[0]); i++) {
        leituraSensores[i] = digitalRead(pinosSensores[i]);
    }
}