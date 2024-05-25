#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>
#include <stdio.h>

typedef int type_elem;
typedef unsigned int uint;

typedef struct node_t* list;

/*Inicializamos la lsita*/
list empty();

/*Consulta si la lista es vacia*/
bool is_empty(list l);


/*Agrega el elemento al comienzo de la lista*/
list addl(list l, type_elem elem);

/*Devuelve el primer elemento de la lista*/
type_elem head(list l);

/*Elimina el primer elemento de la lista*/
list tail(list l);

/*Agrega el elemento al final de la lista*/
list addr(list l, type_elem elem);

/*Devuelve la cantidad de elementos de una lista*/
uint length(list l);

/*Concatena dos listas*/
list concat(list l1, list l2);

/*Devuelve el n-esimo elemento de la lista*/
type_elem index(list l, uint n);

/*Elimina todos los elementos mayores a la posicion n*/
list take(list l, uint n);

/*Elimina todos los elementos menores a la posicion n*/
list drop(list l, uint n);

/*Copia los elementos de la lista l1 en otra lista*/
list copy(list l1);

void print_list(list l);

/*Libera la memoria*/
list destroy(list l);

#endif

