/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: Dani
 *
 * Created on September 6, 2021, 5:12 PM
 */

#ifndef NODO_H
#define NODO_H
#include "Registro.h"

typedef struct Nodo {
    Registro* data;
    struct Nodo* sig;

} Nodo;

#endif /* NODO_H */
