/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Interfaz.c
 * Author: Dani
 * 
 * Created on September 2, 2021, 6:09 PM
 */

#include "../Headers_Files/Interfaz.h"

void empezarJuego()
{
    inicializarTablero(4, 4);
    initList();

    //Cargar registros a la lista
    /*
    cargarLista(lista);
    
    */
    imprimirTablero();
    vistaMenu();

    //Guardar registros de la lista
    /*
    guardarLista(lista);
    */

    freeList();
    liberarMemoriaTablero();
}

void imprimirTablero()
{
    for (int i = 0; i < table->row_count; i++)
    {
        for (int j = 0; j < table->col_count; j++)
        {
            if (table->tablero[i][j] != 0)
            {
                printf(j != table->col_count - 1 ? " [%2d] " : " [%2d] \n", table->tablero[i][j]);
            }
            else
            {
                printf(" [  ]");
            }
        }
        printf("\n");
    }
    printf("\n");
}

Jugador definirJugador(char nombreJugador[10])
{
    int numeroPartidas = 0;

    //Buscar en registros si ya hay algun jugador registrado con ese nombre y si lo hay encontrar el numero de juego en los que esta registrado
    /* 
    if (doSomething(nombreJugador) == 0) {
        numeroPartidas = doSomething2(nombreJugador);
    }
    */

    Jugador nuevo;
    memcpy(nuevo.nombreJugador, nombreJugador, sizeof nuevo.nombreJugador);
    nuevo.partidasJugadas = numeroPartidas;

    return nuevo;
}

Registro *crearRegistro(Jugador *jugador)
{
    Registro *nuevoRegistro = (Registro *)malloc(sizeof(Registro));
    memcpy(nuevoRegistro->nombreJugador, jugador->nombreJugador, sizeof nuevoRegistro->nombreJugador);

    nuevoRegistro->fecha_jugada[0] = generateDay();
    nuevoRegistro->fecha_jugada[1] = generateMonth();
    nuevoRegistro->fecha_jugada[2] = generateYear();

    return nuevoRegistro;
}

void vistaMenu()
{
    char nombreJugador[10];
    int numeroMovimientos = 0;

    printf("Digite su nombre de jugador -> ");
    scanf("%s", nombreJugador);

    Jugador nuevo = definirJugador(nombreJugador);

    Registro *nuevoRegistro = crearRegistro(&nuevo);

    if (menuJuego(&numeroMovimientos) == 1)
    {
        printf("Usted gano el juego");
    }
    else
    {
        printf("Usted decidio retirarse, que pena...");
    }

    //Cuando se finaliza el juego o cuando el jugador se retira
    nuevoRegistro->numeroMovimientos = numeroMovimientos;
    push(nuevoRegistro);
}

/*
Retorna 1 si gano el juego;
Retorna -1 si se retiro del juego
*/
int menuJuego(int *numeroMovimientos)
{
    int response = 0;
    Move move;

    probarGanexd();
    imprimirTablero();

    do
    {
        printf("\e[1;1H\e[2J");
        imprimirTablero();

        move = pedirMovimiento();
        response = checkIfValidMove(move);

        switch (response)
        {
        case 1:
            doTheMove(move);
            (*numeroMovimientos)++;
            if (checkIfWon() == 1)
            {
                return 1;
            }
            break;
        case -1:
            printf("El movimiento que intenta realizar es invalido.\n");
            break;
        case 0:
            printf("El movimiento que intenta realizar no esta definido.\n");
            break;
        case -100:
            return -1;
            break;
        }

    } while (response != -100);
}

Move pedirMovimiento()
{
    char move;

    printf("%s", "Movimientos: \n");
    printf("%s", "1: Arriba     |    2: Abajo\n");
    printf("%s", "3: Izquierda  |    4: Derecha\n");
    printf("%s", "          5: Salir           \n");
    printf("%s", "Ingrese un movimiento -> ");
    scanf(" %c", &move);

    switch (move)
    {
    case '1':
        return MOVE_UP;
        break;

    case '2':
        return MOVE_DOWN;
        break;

    case '3':
        return MOVE_LEFT;
        break;

    case '4':
        return MOVE_RIGHT;
        break;
    case '5':
        return END_GAME;
        break;
    default:
        return UNDEFINED;
        break;
    }
}