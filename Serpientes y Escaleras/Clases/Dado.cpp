//
// Created by LabP31012 on 23/12/2022.
//

#include "Dado.h"
#include <complex>

int Dado::lanzar() {
    int numero = rand()%6+1;
    return numero;
}
