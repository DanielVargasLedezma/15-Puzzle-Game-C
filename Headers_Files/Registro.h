/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Registro.h
 * Author: Dani
 *
 * Created on September 2, 2021, 6:00 PM
 */

#ifndef REGISTRO_H
#define REGISTRO_H

typedef struct Registro {
    int numeroMovimientos;
    char nombreJugador[10];

    //[0] day - [1] month - [2] year
    int fecha_jugada[3];

} Registro;

#endif /* REGISTRO_H */
