/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Archivo.c
 * Author: Dani
 * 
 * Created on September 2, 2021, 5:52 PM
 */

#include "../Headers_Files/Archivos.h"

/*
Retorna -1 si el archivo esta vacio o si hubo un error al abrir el archivo;
Retorna 1 si la carga se realizo con exito
*/
int cargarLista(ListaRegistro *lista)
{
    FILE *reservaciones = fopen("Archivos/Reservaciones.txt", "r");

    int cantidadNodos = 0;

    if (!reservaciones)
    {
        return -1;
    }

    fseek(reservaciones, 0, SEEK_END);

    if (ftell(reservaciones) == 0)
    {
        fclose(reservaciones);
        return -1;
    }

    rewind(reservaciones);

    fscanf(reservaciones, "%d", &cantidadNodos);

    Registro *data;

    while (cantidadNodos != 0)
    {
        data = (Registro *)malloc(sizeof(Registro));
        cargarNodo(data, reservaciones);
        push(data);
        cantidadNodos--;
    }

    fclose(reservaciones);

    return 1;
}

void cargarNodo(Registro *data, FILE *reservaciones)
{
    fscanf(reservaciones, "%d", &data->numeroMovimientos);
    fgets(data->nombreJugador, 10, reservaciones);
    data->nombreJugador[10] = '\0';
    fscanf(reservaciones, "%d", &data->fecha_jugada[0]);
    fscanf(reservaciones, "%d", &data->fecha_jugada[1]);
    fscanf(reservaciones, "%d", &data->fecha_jugada[2]);
    fgets(data->resultado, 10, reservaciones);
    data->resultado[10] = '\0';
}

void guardarLista(ListaRegistro *lista)
{
    FILE *reservaciones = fopen("Archivos/Registros.txt", "a");

    if (!reservaciones)
    {
        return;
    }

    if (lista->cantidadNodos > 0)
    {
        // fprintf(reservaciones, "%d\n", lista->cantidadNodos);

        Nodo *tmp = lista->head;

        while (tmp)
        {
            escribirNodo(tmp->data, reservaciones);
            tmp = tmp->sig;
        }
    }

    fclose(reservaciones);
}

void escribirNodo(Registro *data, FILE *reservaciones)
{
    fprintf(reservaciones, "El jugador necesito %d movimientos\n", data->numeroMovimientos);
    fprintf(reservaciones, "El nombre del jugador es %s\n", data->nombreJugador);
    fprintf(reservaciones, "Se jugo el dia %d", data->fecha_jugada[0]);
    fprintf(reservaciones, " del mes %d", data->fecha_jugada[1]);
    fprintf(reservaciones, " del %d\n", data->fecha_jugada[2]);
    fprintf(reservaciones, "El jugador %s\n", data->resultado);
}
