//
// Created by LabP31012 on 23/12/2022.
//

#include "Ficha.h"

void Ficha::mover(int nuevaPosicion) {
    pos_actual=pos_actual+nuevaPosicion;
}

int Ficha::posicion() {
    return pos_actual;
}
