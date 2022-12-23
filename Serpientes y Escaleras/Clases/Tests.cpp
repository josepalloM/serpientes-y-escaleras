
#include <assert.h>
#include <iostream>
#include "Juego.h"
using namespace std;


//
// Tests para las historias de usuario
//

// HISTORIA DE USUARIO 1

void test1(){
    Dado* dado = new Dado();
    Ficha* ficha = new Ficha();
    Juego* juego =  new Juego(dado,ficha,1);
    juego->iniciar();
    assert(juego->getPosicionFicha()==1);
}

void test2(){
    Dado* dado = new Dado();
    Ficha* ficha = new Ficha();
    Juego* juego =  new Juego(dado,ficha,1);
    juego->mover(3);
    assert(juego->getPosicionFicha()==4);
}

void test3(){
    Dado* dado = new Dado();
    Ficha* ficha = new Ficha();
    Juego* juego =  new Juego(dado,ficha,1);
    juego->mover(3);
    juego->mover(4);
    assert(juego->getPosicionFicha()==8);
}

// HISTORIA DE USUARIO 2

void test4(){
    Dado* dado = new Dado();
    Ficha* ficha = new Ficha();
    Juego* juego =  new Juego(dado,ficha,97);
    juego->mover(3);
    assert(juego->getPosicionFicha()==100);
    assert(juego->terminoElJuego());
}

void test5(){
    Dado* dado = new Dado();
    Ficha* ficha = new Ficha();
    Juego* juego =  new Juego(dado,ficha,97);
    juego->mover(4);
    assert(juego->getPosicionFicha()==97);
    assert(juego->terminoElJuego()==false);
}

// HISTORIA DE USUARIO 3

void test6(){
    Dado* dado = new Dado();
    Ficha* ficha = new Ficha();
    Juego* juego =  new Juego(dado,ficha,1);
    juego->iniciar();
    int valor = juego->lanzarDado();
    assert(valor<7 && valor>0);
}

void test7(){
    Dado* dado = new Dado();
    Ficha* ficha = new Ficha();
    Juego* juego =  new Juego(dado,ficha,1);
    juego->iniciar();
    bool no_salio_cuatro=true;
    while(no_salio_cuatro){
        int valor = juego->lanzarDado();
        if (valor==4){
            no_salio_cuatro= false;
            juego->mover(valor);
        }
    }
    assert(juego->getPosicionFicha() == 5);
}

void jugar() {
    Dado* dado = new Dado();
    Ficha* ficha = new Ficha();
    Juego* juego = new Juego(dado, ficha, 1);
    juego->iniciar();
    bool salir = false;
    while (salir == false) {
        cout << "Presione 1 para lanzar el dado y cualquier otro dígito para salir del juego." << '\n';
        int accion;
        cin >> accion;
        if (accion==1)
        {
            int pasos = juego->lanzarDado();
            cout << "Al lanzar el dado obtuvo el valor de: " << pasos << '\n';
            juego->mover(pasos);
            cout << "El jugador se ha movido " << pasos << " pasos!" << '\n';
            cout << "Su posición actual es: " << juego->getPosicionFicha() << '\n';
            if (juego->terminoElJuego())
            {
                salir = true;
                cout << "Usted acaba de ganar la partida!" << '\n';
            }
        }
        else {
            salir = true;
        }
    }

}

void correrTests() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
}



int main() {
    cout << "Presione 1 para jugar, 2 para correr las pruebas y cualquier otro dígito para salir." << '\n';
    int opcion;
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        jugar();
    case 2:
        correrTests();
    default:
        break;
    }
    return 0;
}
