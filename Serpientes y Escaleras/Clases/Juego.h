//
// Created by LabP31012 on 23/12/2022.
//

#ifndef ESCALERAS_JUEGO_H
#define ESCALERAS_JUEGO_H

#include "Dado.h"
#include "Ficha.h"


class Juego {
public:
    Dado* dado;
    Ficha* ficha;
    bool finalizado=false;
    int FINAL = 100;
    int POSICION_INICIAL=99;
    Juego();
    Juego(Dado* dado1, Ficha* ficha1, int pos_inicial);
    ~Juego();
    void iniciar();
    bool terminoElJuego();
    int lanzarDado();
    int mover(int pasos);
    int getPosicionFicha();
};


#endif //ESCALERAS_JUEGO_H
