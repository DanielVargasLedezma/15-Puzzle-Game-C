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

typedef struct Table {
    int **tablero;
    int row_count; //n
    int col_count; //m

} Table;

extern Table* table;
extern void inicializarTablero(int n, int m);
extern void randomizarNumeros();

//Retorna 1 si esta repetido, 0 si no
extern int checkRepetidos(int numRand);

extern void liberarMemoriaTablero();

#endif /* TABLE_H */
