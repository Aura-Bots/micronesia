#include <Arduino.h>
#include <DRV8870.hpp>

DRV8870 motorEsquerdo(PINO_MOTOR_ESQUERDO_1,
                     PINO_MOTOR_ESQUERDO_2,
                     CANAL_PWM_MOTOR_ESQUERDO_1,
                     CANAL_PWM_MOTOR_ESQUERDO_2,
                     FREQUENCIA_PWM_MOTOR_ESQUERDO,
                     RESOLUCAO_PWM_MOTOR_ESQUERDO);

DRV8870 motorDireito(PINO_MOTOR_DIREITO_1,
                      PINO_MOTOR_DIREITO_2,
                      CANAL_PWM_MOTOR_DIREITO_1,
                      CANAL_PWM_MOTOR_DIREITO_2,
                      FREQUENCIA_PWM_MOTOR_DIREITO,
                      RESOLUCAO_PWM_MOTOR_DIREITO);

leituraModStart = digitalRead(PINO_MOD_START);

enum Estados {
    ESTRATEGIA_INICIAL_PRIMARIA,
    ESTRATEGIA_INICIAL_SECUNDARIA,
    ESTRATEGIA_INICIAL_TERCIARIA,
    ESTRATEGIA_BUSCA,
    ESTRATEGIA_PERSEGUICAO,
    ESTRATEGIA_BUSCA_POS_PERSEGUICAO
}

void setup() {
    pinMode(PINO_LED, OUTPUT);
    pinMode(PINO_MOD_START, INPUT);
}

void loop() {

    if leituraModStart == HIGH {
        digitalWrite(PINO_LED, HIGH);
        
        
    }

    else {
        digitalWrite(PINO_LED, LOW);
        parar.motorEsquerdo();
        parar.motorDireito();
    }


}
