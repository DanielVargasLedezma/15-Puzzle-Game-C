/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista_Registros.h
 * Author: Dani
 *
 * Created on September 2, 2021, 5:57 PM
 */

#ifndef LISTA_REGISTROS_H
#define LISTA_REGISTROS_H
#include <stdlib.h>
#include "Nodo.h"

typedef struct ListaRegistro
{
    Nodo *head;
    int cantidadNodos;
} ListaRegistro;

extern ListaRegistro *lista;

extern void initList();

extern void push(Registro *data);

extern void freeList();

#endif /* LISTA_REGISTROS_H */
