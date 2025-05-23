#pragma once

#include <Arduino.h>

class DRV8870 {
    private:
        int _pino1;
        int _pino2;

        int _canalPino1;
        int _canalPino2;

        int _valorMaximoDePotencia;

        int _valorDePotencia = 0;

    public:

        bool motorInvertido = false;
        

    DRV8870(int pino1, int pino2, int canalPino1, int canalPino2, int frequenciaPWM, int resolucaoPWM):
        _pino1(pino1),
        _pino2(pino2),
        _canalPino1(canalPino1),
        _canalPino2(canalPino2),

        _valorMaximoDePotencia(pow(2, resolucaoPWM) - 1)
    {
        ledcSetup(_canalPino1, frequenciaPWM, resolucaoPWM);
        ledcSetup(_canalPino2, frequenciaPWM, resolucaoPWM);

        ledcAttachPin(_pino1, _canalPino1);
        ledcAttachPin(_pino2, _canalPino2);
    }

    void parar() {
        ledcWrite(_canalPino1, _valorMaximoDePotencia);
        ledcWrite(_canalPino2, _valorMaximoDePotencia);

        _valorDePotencia = 0;
    }

    void setPotencia(int potencia) {
        if (motorInvertido) {
            potencia = -potencia;
        }

        if (potencia > 0) {
            ledcWrite(_canalPino1, _valorMaximoDePotencia);
            ledcWrite(_canalPino2, _valorMaximoDePotencia - potencia);
        } 
        
        else if (potencia < 0) {
            ledcWrite(_canalPino1, _valorMaximoDePotencia - abs(potencia));
            ledcWrite(_canalPino2, _valorMaximoDePotencia);
        } 
        
        else {
            parar();
        }

        _valorDePotencia = potencia;
    }

    int getPotencia() {
        return _valorDePotencia;
    }

};