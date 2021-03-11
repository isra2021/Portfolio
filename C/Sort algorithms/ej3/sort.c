#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    unsigned int piv = izq;
    unsigned int i, j;
    i = izq + 1;
    j = der;
    while(i <= j){
        if(goes_before(a[i], a[piv])){
            ++i;
        }
        else if(goes_before(a[piv], a[j])){
            --j;
        }
        else{
            swap(a, i, j);
            ++i;
            --j;
        }
    }
        swap(a, piv, j);
        piv = j;
        return piv;

    }

    /* Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' (according to function goes_before) a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]
    */


static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    izq += 1; 
    if(izq < der){
        unsigned int pivote = partition(a, izq, der);
        quick_sort_rec(a, izq , pivote-1);
        quick_sort_rec(a, pivote + 1, der);
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

