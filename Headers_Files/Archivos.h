/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Archivo.h
 * Author: Dani
 *
 * Created on September 2, 2021, 5:52 PM
 */

#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <stdlib.h>
#include <stdio.h>
#include "Lista_Registros.h"

/*
Retorna -1 si el archivo esta vacio o si hubo un error al abrir el archivo;
Retorna 1 si la carga se realizo con exito
*/
extern int cargarLista();

extern void cargarNodo(Registro *data, FILE *reservaciones);

extern void guardarLista(ListaRegistro* lista);

extern void escribirNodo(Registro *data, FILE *reservaciones);

#endif /* ARCHIVO_H */
