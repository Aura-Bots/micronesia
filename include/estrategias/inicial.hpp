#pragma once
#include <Arduino.h>
#include "locomocao/configuracoes.hpp"
#include "configuracoes.hpp"

class EstrategiaInicial {
    private:
        DRV8870 &motorEsquerdo;
        DRV8870 &motorDireito;

    public:
        EstrategiaInicial(DRV8870 &me, DRV8870 &md) : motorEsquerdo(me), motorDireito(md) {}

        void fullFrente() {
            motorEsquerdo.setVelocidade(velocidadeFullFrente * motorEsquerdo.getPotenciaMaxima());
            motorDireito.setVelocidade(velocidadeFullFrente * motorDireito.getPotenciaMaxima());

            if (delayEstrategia(tempoFullFrente)) {
                return;
            }
        }
};