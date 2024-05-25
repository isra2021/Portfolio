#include "tablero.h"

#include <assert.h>
#include <stdlib.h>

struct tablero_t{
    counter equipoA;
    counter equipoB;
};

tablero inicial(){
    tablero tab = (tablero) malloc(sizeof(struct tablero_t));
    if(tab == NULL) return NULL;
    tab -> equipoA = init();
    tab -> equipoB = init();
    return tab;
}

tablero anotaA(tablero tab){
    assert(tab != NULL);
    inc(tab -> equipoA);
    return tab;
}

tablero anotaB(tablero tab){
    assert(tab != NULL);
    inc(tab -> equipoB);
    return tab;
}

bool es_inicial(tablero tab){
    assert(tab != NULL);
    return (is_init(tab -> equipoA) && is_init(tab -> equipoB));
}

bool hay_tantoA(tablero tab){
    assert(tab != NULL);
    return (!is_init(tab -> equipoA));
}

bool hay_tantoB(tablero tab){
    assert(tab != NULL);
    return (!is_init(tab -> equipoB));
}

bool ganaA(tablero tab){
    assert(tab != NULL);
    return (count(tab -> equipoA) > count(tab -> equipoB));
}

bool ganaB(tablero tab){
    assert(tab != NULL);
    return (count(tab -> equipoB) > count(tab -> equipoA));
}

bool empate(tablero tab){
     assert(tab != NULL);
     return (count(tab -> equipoB) == count(tab -> equipoA));
}

tablero n_tantosA(tablero tab, unsigned int n){
    for(unsigned int i = 0; i < n; i++){
        inc(tab -> equipoA);
    }
    return tab;
}

tablero n_tantosB(tablero tab, unsigned int n){
    for(unsigned int i = 0; i < n; i++){
        inc(tab -> equipoB);
    }
    return tab;
}

tablero castigarA(tablero tab, unsigned int n){
    for(unsigned int i = 0; i < n; i++){
        dec(tab -> equipoA);
    }
    return tab;
}

tablero castigarB(tablero tab, unsigned int n){
    if(count(tab -> equipoA) < n){
        for(unsigned int i = 0; i < count(tab -> equipoA); i++){
            dec(tab -> equipoA);
        }
    }
    else{
        for(unsigned int i = 0; i < n; i++){
            dec(tab -> equipoB);
        }
    }
    return tab;
}


