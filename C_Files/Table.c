/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Table.c
 * Author: Dani
 * 
 * Created on September 2, 2021, 5:49 PM
 */

#include "../Headers_Files/Table.h"
#include <time.h>
Table* table;

void inicializarTablero(int n, int m) {
    table = (Table*) malloc(sizeof (Table));

    table->row_count = n;

    table->col_count = m;

    table->tablero = malloc(n * sizeof (int));

    for (int i = 0; i < n; i++) {
        (table->tablero)[i] = malloc(m * sizeof (int));
    }

    for (int i = 0; i < table->row_count; i++) {
        for (int j = 0; j < table->col_count; j++) {
            table->tablero[i][j] = 0;
        }
    }
}

void randomizarNumeros() {
    srand(time(NULL));
    int numRand = 0, contador = 0;
//    int bandera = 0, i = 0, j = 0;

    //    while (bandera == 0) {
    //        numRand = rand() % 15 + 1;
    //        if (checkRepetidos(numRand) == 0) {
    //            table->tablero[i][j] = numRand;
    //            if (i < table->row_count) {
    //                if (j < table->col_count) {
    //                    j++;
    //                }
    //                else {
    //                    i++;
    //                    j = 0;
    //                }
    //            }
    //            else {
    //                bandera = 1;
    //            }
    //        }
    //    }

    for (int i = 0; i < table->row_count; i++) {
        for (int j = 0; j < table->col_count; j++) {
            numRand = rand() % 15 + 1;
            
            while (checkRepetidos(numRand) == 0) {
                numRand = rand() % 15 + 1;
                contador++;
            }
            
            if(contador == 15){
                break;
            }
            
            table->tablero[i][j] = numRand;
        }
    }
}

//Retorna 1 si esta repetido, 0 si no

int checkRepetidos(int numRand) {
    for (int i = 0; i < table->row_count; i++) {
        for (int j = 0; j < table->col_count; j++) {
            if (table->tablero[i][j] == numRand) {
                return 1;
            }
        }
    }

    return 0;
}

void liberarMemoriaTablero() {
    for (int i = 0; i < table->row_count; i++) {
        free(table->tablero[i]);
    }

    free(table->tablero);

    free(table);
}