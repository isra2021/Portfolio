#include "assert.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

#define ARRAY_SIZE 10

struct max_min_result {
    int max_value;
    int min_value;
    unsigned int max_position;
    unsigned int min_position;
};
/*OTRA FORMA
struct max_min_result compute_max_min(int array[], unsigned int length)
{
    assert(length > 0);
    struct max_min_result result = { 0, 0, 0, 0 };
    int minimo = array[0];
    int maximo = array[0];
    for (unsigned int i = 0; i < length; i++)
    {
        if (minimo>array[i])
        {
            result.min_position = i;
            minimo = array[i];   
        }
        if(maximo<array[i])
        {
            maximo = array[i];
            result.max_position = i;
        }
    }
    result.max_value = maximo;
    result.min_value = minimo;

    return result;
}
*/
struct max_min_result compute_max_min(int array[], unsigned int length){
    assert(length > 0);
    struct max_min_result result = {0,0,0,0};
    unsigned int min_pos = 0;
    unsigned int max_pos = 0;
    for(unsigned int i = 1; i < length; ++i){
        if(array[min_pos] > array[i]){
            min_pos = i;
        }
        if(array[max_pos] < array[i]){
            max_pos = i;
        }
    }
    result.max_position = max_pos;
    result.min_position = min_pos;
    result.max_value = array[max_pos];
    result.min_value = array[min_pos];
    return result;
}

int main()
{
    int array[ARRAY_SIZE] = { 4, -1, 5, 8, 9, 0, 3, 6, 0, 0 };
    printf("Ingrese los valores del arreglo \n");
    for (unsigned int i = 0; i < ARRAY_SIZE; i++)
    {
        scanf("%d", &array[i]);
    }

    struct max_min_result result = compute_max_min(array, ARRAY_SIZE);
    printf("Máximo: %d\n", result.max_value);
    printf("Posición del máximo: %u\n", result.max_position);
    printf("Mínimo: %d\n", result.min_value);
    printf("Posición del mínimo: %u\n", result.min_position);
    return 0;
}
