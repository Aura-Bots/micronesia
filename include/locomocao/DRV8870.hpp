// Classe do driver de motor DRV8870

#pragma once
#include <Arduino.h>

class DRV8870 {
    private:
        uint8_t pinoIN1;
        uint8_t pinoIN2;
        uint8_t canalIN1;
        uint8_t canalIN2;

        static constexpr int FREQUENCIA_PWM = 20000;
        static constexpr int RESOLUCAO_PWM = 12;
        static constexpr int POTENCIA_MAXIMA = (1 << RESOLUCAO_PWM) - 1;
        static constexpr int POTENCIA_MINIMA = -POTENCIA_MAXIMA;
        static constexpr uint8_t POTENCIA_NEUTRA = 0;
        int _potencia;

    public:
        DRV8870(uint8_t _pinoIN1, uint8_t _pinoIN2, uint8_t _canalIN1, uint8_t _canalIN2) 
                : pinoIN1(_pinoIN1), pinoIN2(_pinoIN2), canalIN1(_canalIN1), canalIN2(_canalIN2) {
            ledcAttachPin(pinoIN1, canalIN1);
            ledcAttachPin(pinoIN2, canalIN2);

            ledcSetup(canalIN1, FREQUENCIA_PWM, RESOLUCAO_PWM);
            ledcSetup(canalIN2, FREQUENCIA_PWM, RESOLUCAO_PWM);

            parar(false);
        }

        void setVelocidade(int potencia) {
            potencia = constrain(potencia, POTENCIA_MINIMA, POTENCIA_MAXIMA);

            if (potencia > POTENCIA_NEUTRA) {
                ledcWrite(canalIN1, potencia);
                ledcWrite(canalIN2, POTENCIA_NEUTRA);
            } 
            
            else if (potencia < POTENCIA_NEUTRA) {
                ledcWrite(canalIN1, POTENCIA_NEUTRA);
                ledcWrite(canalIN2, abs(potencia));
            } 
            
            else {
                parar(false);
            }

            _potencia = potencia;
        }

        void parar(bool freio = true) {
            if (freio) {
                ledcWrite(canalIN1, POTENCIA_MAXIMA);
                ledcWrite(canalIN2, POTENCIA_MAXIMA);
            }

            else {
                ledcWrite(canalIN1, POTENCIA_NEUTRA);
                ledcWrite(canalIN2, POTENCIA_NEUTRA);
            }

            _potencia = POTENCIA_NEUTRA;
        }

        int getPotencia() const {
            return _potencia;
        }

        static constexpr int getPotenciaMaxima() {
            return POTENCIA_MAXIMA;
        }
};