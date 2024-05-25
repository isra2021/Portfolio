#ifndef _TABLERO_H
#define _TABLERO_H

#include "counter.h"

#include <stdbool.h>

typedef struct tablero_t* tablero;

/*Inicializa el tablero*/
tablero inicial();

/*Anotacion del equipo A*/
tablero anotaA(tablero tab);

/*Anotacion del equipo B*/
tablero anotaB(tablero tab);

/*Verifica si hubo tantos*/
bool es_inicial(tablero tab);

/*Verifica si hay tantos en el equipo A*/
bool hay_tantoA(tablero tab);

/*Verifica si hay tantos en el equipo B*/
bool hay_tantoB(tablero tab);

/*Verifica si gana el equipo A*/
bool ganaA(tablero tab);

/*Verifica si gana el equipo B*/
bool ganaB(tablero tab);

/*Verifica si hay un empate*/
bool empate(tablero tab);

/*Anotar a equipo A n tantos*/
tablero n_tantosA(tablero tab, unsigned int n);

/*Anotar a equipo B n tantos*/
tablero n_tantosA(tablero tab, unsigned int n);

/*Castigar a A*/
tablero castigarA(tablero tab);

/*Castigar a B*/
tablero castigarB(tablero tab);

#endif