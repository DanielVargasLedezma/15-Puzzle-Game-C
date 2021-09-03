/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Interfaz.c
 * Author: Dani
 * 
 * Created on September 2, 2021, 6:09 PM
 */

#include "../Headers_Files/Interfaz.h"

void empezarJuego() {
    inicializarTablero(4, 4);
    initList();
    //Cargar registros a la lista
    /*
    cargarLista(lista);
    */
    vistaMenu();
    //Guardar registros de la lista
    /*
    guardarLista(lista);
    */
    freeList();
    liberarMemoriaTablero();
}

void imprimirTablero() {
    for (int i = 0; i < table->row_count; i++) {
        for (int j = 0; j < table->col_count; j++) {
            if (table->tablero[i][j] != 0) {
                printf("[%i]", table->tablero[i][j]);
            }
            else {
                printf("[ ]");
            }
        }
        printf("\n");
    }

}

void vistaMenu() {
    char nombreJugador[10];
    int numeroPartidas = 0, numeroMovimientos = 0;
    
    printf("Digite su nombre de jugador -> ");
    scanf("%s", nombreJugador);

    //Buscar en registros si ya hay algun jugador registrado con ese nombre y si lo hay encontrar el numero de juego en los que esta registrado
    /* 
    if (doSomething(nombreJugador) == 0) {
        numeroPartidas = doSomething2(nombreJugador);
    }
    */

    Jugador nuevo;
    memcpy(nuevo.nombreJugador, nombreJugador, sizeof nuevo.nombreJugador);
    nuevo.partidasJugadas = numeroPartidas;

    Registro* nuevoRegistro = (Registro*)malloc(sizeof(Registro));
    memcpy(nuevoRegistro.nombreJugador, nombreJugador, sizeof nuevoRegistro.nombreJugador);

    nuevoRegistro->fecha_jugada[0] = generateDay();
    nuevoRegistro->fecha_jugada[1] = generateMonth();
    nuevoRegistro->fecha_jugada[2] = generateYear();

    

    //Cuando se finaliza el juego o cuando el jugador se retira
    nuevoRegistro->numeroMovimientos = numeroMovimientos;
    push(nuevoRegistro);
}