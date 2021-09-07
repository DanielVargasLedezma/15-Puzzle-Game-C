/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista_Registros.c
 * Author: Dani
 * 
 * Created on September 2, 2021, 5:57 PM
 */

#include "../Headers_Files/Lista_Registros.h"

ListaRegistro *lista;

void initList()
{
    if (!lista)
    {
        lista = (ListaRegistro *)malloc(sizeof(ListaRegistro));
        lista->head = NULL;
        lista->cantidadNodos = 0;
    }
}

void push(Registro *data)
{
    if (!data)
    {
        return;
    }

    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->data = data;
    nuevo->sig = NULL;

    if (!(lista->head))
    {
        lista->head = nuevo;
    }
    else
    {
        Nodo *tmp = lista->head;

        while (tmp->sig)
        {
            tmp = tmp->sig;
        }

        tmp->sig = nuevo;
    }
    lista->cantidadNodos++;
}

void freeList()
{
    if (!lista || !(lista->head))
    {
        return;
    }

    if (lista->cantidadNodos == 0)
    {
        Nodo *tmp = lista->head;

        while (tmp)
        {
            if (tmp->data)
            {
                free(tmp->data);
            }

            lista->head = lista->head->sig;
            free(tmp);
            tmp = lista->head;
        }

        free(lista);
    }
}
