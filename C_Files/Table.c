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
Table table;

void inicializarTablero(int n, int m)
{
    table.row_count = n;

    table.col_count = m;

    table.tablero = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        (table.tablero)[i] = malloc(m * sizeof(int));
    }

    for (int i = 0; i < table.row_count; i++)
    {
        for (int j = 0; j < table.col_count; j++)
        {
            table.tablero[i][j] = 0;
        }
    }
    
    randomizarNumeros();
}

void randomizarNumeros()
{
    srand(time(NULL));
    int numRand = 0, contador = 0;

    for (int i = 0; i < table.row_count; i++)
    {
        for (int j = 0; j < table.col_count; j++)
        {
            numRand = 1 + rand() % 15;

            while (checkRepetidos(numRand) == 0)
            {
                numRand = 1 + rand() % 15;
            }

            table.tablero[i][j] = numRand;
            contador++;

            if (contador == 15)
            {
                break;
            }
        }
    }
}

/*
Retorna la posicion i de la casilla con el 0 (Vacio);
Retorna -1 si no encuentra ninguna casiila con el 0.
*/
int retornarIDeVacio()
{
    for (int i = 0; i < table.row_count; i++)
    {
        for (int j = 0; j < table.col_count; j++)
        {
            if (table.tablero[i][j] == 0)
            {
                return i;
            }
        }
    }

    return -1;
}

/*
Retorna la posicion j de la casilla con el 0 (Vacio);
Retorna -1 si no encuentra ninguna casiila con el 0.
*/
int retornarJDeVacio()
{
    for (int i = 0; i < table.row_count; i++)
    {
        for (int j = 0; j < table.col_count; j++)
        {
            if (table.tablero[i][j] == 0)
            {
                return j;
            }
        }
    }

    return -1;
}

//Retorna 1 si esta repetido, 0 si no
int checkRepetidos(int numRand)
{
    for (int i = 0; i < table.row_count; i++)
    {
        for (int j = 0; j < table.col_count; j++)
        {
            if (table.tablero[i][j] == numRand)
            {
                return 0;
            }
        }
    }

    return 1;
}

/*
Retorna 1 si el movimiento es valido;
Retorna -1 si el movimiento no es valido;
Retorna 0 si es indefinido;
Retorna -100 si se desea salir del juego.
*/
int checkIfValidMove(Move move)
{
    int i = retornarIDeVacio(), j = retornarJDeVacio();

    switch (move)
    {
    case MOVE_UP:
        i--;
        if (i < 0)
        {
            return -1;
        }
        else
        {
            return 1;
        }
        break;
    case MOVE_DOWN:
        i++;
        if (i >= table.row_count)
        {
            return -1;
        }
        else
        {
            return 1;
        }
        break;
    case MOVE_LEFT:
        j--;
        if (j < 0)
        {
            return -1;
        }
        else
        {
            return 1;
        }
        break;
    case MOVE_RIGHT:
        j++;
        if (j >= table.col_count)
        {
            return -1;
        }
        else
        {
            return 1;
        }
        break;
    case END_GAME:
        return -100;
    default:
        return 0;
        break;
    }

    return -1;
}

/*
Retorna 1 si el tablero esta ordenado;
Retorna -1 si el tablero no esta ordenado.
*/
int checkIfWon()
{
    int contador = 1;
    for (int i = 0; i < table.row_count; i++)
    {
        for (int j = 0; j < table.col_count; j++)
        {
            if (table.tablero[i][j] == contador)
            {
                contador++;
                if (contador == 15)
                {
                    return 1;
                }
            }
        }
    }

    return -1;
}

void doTheMove(Move move)
{
    switch (move)
    {

    case MOVE_UP:
    {
        int i = retornarIDeVacio(), j = retornarJDeVacio();
        int tmp = 0;
        tmp = table.tablero[i - 1][j];
        table.tablero[i - 1][j] = table.tablero[i][j];
        table.tablero[i][j] = tmp;
        break;
    }
    case MOVE_DOWN:
    {
        int i = retornarIDeVacio(), j = retornarJDeVacio();
        int tmp = 0;
        tmp = table.tablero[i + 1][j];
        table.tablero[i + 1][j] = table.tablero[i][j];
        table.tablero[i][j] = tmp;
        break;
    }
    case MOVE_LEFT:
    {
        int i = retornarIDeVacio(), j = retornarJDeVacio();
        int tmp = 0;
        tmp = table.tablero[i][j - 1];
        table.tablero[i][j - 1] = table.tablero[i][j];
        table.tablero[i][j] = tmp;
    }
    break;

    case MOVE_RIGHT:
    {
        int i = retornarIDeVacio(), j = retornarJDeVacio();
        int tmp = 0;
        tmp = table.tablero[i][j + 1];
        table.tablero[i][j + 1] = table.tablero[i][j];
        table.tablero[i][j] = tmp;
        break;
    }
    case END_GAME:

        break;
    default:

        break;
    }
}

void liberarMemoriaTablero()
{
    for (int i = 0; i < table.row_count; i++)
    {
        free(table.tablero[i]);
    }

    //free(table.tablero);
}

void probarGanexd()
{
    table.tablero[0][0] = 1;
    table.tablero[0][1] = 2;
    table.tablero[0][2] = 3;
    table.tablero[0][3] = 4;
    table.tablero[1][0] = 5;
    table.tablero[1][1] = 6;
    table.tablero[1][2] = 7;
    table.tablero[1][3] = 8;
    table.tablero[2][0] = 9;
    table.tablero[2][1] = 10;
    table.tablero[2][2] = 11;
    table.tablero[2][3] = 12;
    table.tablero[3][0] = 13;
    table.tablero[3][1] = 14;
    table.tablero[3][2] = 0;
    table.tablero[3][3] = 15;
}