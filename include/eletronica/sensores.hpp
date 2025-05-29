#pragma once
#include <Arduino.h>
#include "pinagem.hpp"

void initSensores() {
    pinMode(PINO_SENSOR_LATERAL_DIR, INPUT);
    pinMode(PINO_SENSOR_FRONTAL, INPUT);
    pinMode(PINO_SENSOR_LATERAL_ESQ, INPUT);
    pinMode(PINO_SENSOR_BORDA, INPUT);
}

void leituraSensores() {
    int sensorLateralDir = digitalRead(PINO_SENSOR_LATERAL_DIR);
    int sensorFrontal = digitalRead(PINO_SENSOR_FRONTAL);
    int sensorLateralEsq = digitalRead(PINO_SENSOR_LATERAL_ESQ);
    int sensorBorda = digitalRead(PINO_SENSOR_BORDA);
}