/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Interfaz.h
 * Author: Dani
 *
 * Created on September 2, 2021, 6:09 PM
 */

#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <stdio.h>
#include <string.h>
#include "Lista_Registros.h"
#include "Table.h"
#include "Jugador.h"
#include "DateGenerator.h"

extern void empezarJuego();
extern void imprimirTablero();

extern Jugador definirJugador(char nombreJugador[10]);
extern Registro* crearRegistro(Jugador *jugador);

extern void vistaMenu();

/*
Retorna 1 si gano el juego;
Retorna -1 si se retiro del juego
*/
extern int menuJuego(int* numeroMovimientos);

extern Move pedirMovimiento();

#endif /* INTERFAZ_H */
