//
// Created by LabP31012 on 23/12/2022.
//

#include "Juego.h"

Juego::Juego(Dado *dado1, Ficha *ficha1, int pos_inicial) {
    this->dado=dado1;
    this->ficha=ficha1;
    this->POSICION_INICIAL=pos_inicial;
    this->ficha->pos_actual = pos_inicial;
}

Juego::~Juego() {

}

void Juego::iniciar() {
    this->finalizado=false;
}

Juego::Juego() {}



bool Juego::terminoElJuego() {
    return this->finalizado;
}

int Juego::lanzarDado() {
    return this->dado->lanzar();
}

int Juego::mover(int pasos) {
    if (ficha->posicion()+pasos>FINAL){
        return ficha->posicion();
    }
    if (ficha->posicion()+pasos==FINAL){
        this->finalizado= true;
    }
    ficha->mover(pasos);
    return ficha->posicion();
}

int Juego::getPosicionFicha() {
    return this->ficha->posicion();
}
