#pragma once
#include <Arduino.h>
#include "eletronica/pinagem.hpp"
#include "locomocao/DRV8870.hpp"

#define CANAL_PWM_MOTOR_ESQUERDO_1 0
#define CANAL_PWM_MOTOR_ESQUERDO_2 1
#define CANAL_PWM_MOTOR_DIREITO_1  2
#define CANAL_PWM_MOTOR_DIREITO_2  3

DRV8870 motorEsquerdo(PINO_IN1_ME,
                      PINO_IN2_ME,
                      CANAL_PWM_MOTOR_ESQUERDO_1,
                      CANAL_PWM_MOTOR_ESQUERDO_2);

DRV8870 motorDireito(PINO_IN1_MD,
                     PINO_IN2_MD,
                     CANAL_PWM_MOTOR_DIREITO_1,
                     CANAL_PWM_MOTOR_DIREITO_2);

void parada(int tempo) {  
    motorEsquerdo.parar();
    motorDireito.parar();
}