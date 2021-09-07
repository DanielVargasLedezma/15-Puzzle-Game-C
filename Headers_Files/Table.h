/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Table.h
 * Author: Dani
 *
 * Created on September 2, 2021, 5:49 PM
 */

#ifndef TABLE_H
#define TABLE_H
#include <stdlib.h>
#include <stdio.h>

typedef enum Move
{
    MOVE_UP = 1,
    MOVE_DOWN = 2,
    MOVE_LEFT = 3,
    MOVE_RIGHT = 4,
    END_GAME = 5,
    UNDEFINED = 0
} Move;

typedef struct Table
{
    int **tablero;
    int row_count; //n
    int col_count; //m

} Table;

extern Table table;

extern void inicializarTablero(int n, int m);
extern void randomizarNumeros();

/*
Retorna la posicion i de la casilla con el 0 (Vacio);
Retorna -1 si no encuentra ninguna casiila con el 0.
*/
extern int retornarIDeVacio();

/*
Retorna la posicion j de la casilla con el 0 (Vacio);
Retorna -1 si no encuentra ninguna casiila con el 0.
*/
extern int retornarJDeVacio();

//Retorna 1 si esta repetido, 0 si no
extern int checkRepetidos(int numRand);

/*
Retorna 1 si el movimiento es valido;
Retorna -1 si el movimiento no es valido;
Retorna 0 si es indefinido;
Retorna -100 si se desea salir del juego.
*/
extern int checkIfValidMove(Move move);

/*
Retorna 1 si el tablero esta ordenado;
Retorna -1 si el tablero no esta ordenado.
*/
extern int checkIfWon();

extern void doTheMove(Move move);
extern void probarGanexd();
extern void liberarMemoriaTablero();

#endif /* TABLE_H */
