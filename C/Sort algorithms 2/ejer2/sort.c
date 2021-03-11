#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "helpers.h"
#include "sort.h"

static bool goes_before(player_t x, player_t y) {
    return (x.rank <= y.rank);
}

bool array_is_sorted(player_t atp[], uint length) {
    unsigned int i = 1;
    while (i < length && goes_before(atp[i - 1], atp[i])) {
        i++;
    }
    return (i == length);
}

void swap(player_t a[], uint i, uint j) {
    player_t aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}

static uint min_pos_from(player_t a[], uint i, uint length){
    uint min = i;
    for(uint j = i+1; j < length; j++){
        if(goes_before(a[j], a[min])){
            min = j;
        }
    }
    return min;
}

static void selection_sort(player_t a[], uint length){
    for(uint i = 0; i < length; i++){
        uint min = min_pos_from(a, i, length);
        swap(a, i, min);
    }
}

void sort(player_t a[], uint length){
	selection_sort(a, length);	
}
