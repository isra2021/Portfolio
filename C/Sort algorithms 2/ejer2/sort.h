#ifndef _SORT_H
#define _SORT_H

#include <stdbool.h>

typedef unsigned int uint;

bool array_is_sorted(player_t atp[], uint length);

void swap(player_t a[], uint i, uint j);

void sort(player_t a[], uint length);

//void sort2(player_t a[], uint length);

#endif
