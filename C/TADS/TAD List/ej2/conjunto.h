#ifndef _CONJUNTO_H
#define _CONJUNTO_H

#include "list.h"

typedef struct set_t* set;


/*Inicializa un conjunto*/
set empty_set();


set set_add(set s, type_elem elem);


/*Destruye un conjunto*/
set set_destroy(set s);








#endif