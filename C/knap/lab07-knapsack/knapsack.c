#include "knapsack.h"
#include <stdlib.h>
#include <limits.h>
#include <math.h>



value_t knapsack_backtracking(item_t *items,
                              unsigned int array_length,
                              weight_t max_weight) {
    if (max_weight == 0 || array_length == 0)
        return 0;
    else if (item_weight(items[array_length-1]) > max_weight)
        return (knapsack_backtracking(items, array_length-1, max_weight));
    else
        return (fmax(knapsack_backtracking(items, array_length-1, max_weight),
                item_value(items[array_length-1]) +
                knapsack_backtracking(items, array_length-1,
                                      max_weight - item_weight(items[array_length-1])))
               );
}

static value_t **knap_destroy(value_t **knap, unsigned int array_length) {
    if (!knap) return NULL;

    for (unsigned int i = 0; i <= array_length; i++) {
        if (knap[i]) {
            free(knap[i]);
            knap[i] = NULL;
        }
    }
    free(knap);
    return (knap = NULL);
}

static value_t **knap_init(item_t *items, unsigned int array_length, weight_t max_weight) {
    value_t **knap = calloc(array_length + 1, sizeof(value_t *));
    if (!knap) goto error;

    for (unsigned int i = 0; i <= array_length; i++) {
        knap[i] = calloc(max_weight + 1, sizeof(value_t));
        if (!knap[i]) goto error;
    }

    for (unsigned int i = 1; i <= array_length; i++) {
        for (unsigned int w = 1; w <= max_weight; w++) {
            if (item_weight(items[i-1]) > w)
                knap[i][w] = knap[i-1][w];
            else
                knap[i][w] = fmax(knap[i-1][w],
                                 item_value(items[i-1]) +
                                 knap[i-1][w-item_weight(items[i-1])]);
        }
    }

    return knap;

error:
    knap_destroy(knap, array_length);
    perror("knap_init");
    return NULL;
}

value_t knapsack_dynamic(item_t *items, unsigned int array_length, weight_t max_weight) {
    value_t result, **knap = NULL;;

    knap = knap_init(items, array_length, max_weight);
    if (!knap) goto error;

    result = knap[array_length][max_weight];
    knap = knap_destroy(knap, array_length);
    return result;

error:
    knap_destroy(knap, array_length);
    perror("knapsack_dynamic");
    return UINT_MAX;
}

value_t knapsack_dynamic_selection(item_t *items,
                                   bool *selected,
                                   unsigned int array_length,
                                   weight_t max_weight) {
    value_t result, r, **knap = NULL;;
    weight_t s;

    knap = knap_init(items, array_length, max_weight);
    if (!knap) goto error;

    r = array_length;
    s = max_weight;
    while (knap[r][s] > 0) {
        if (knap[r][s] != knap[r-1][s]) {
            selected[r-1] = true;
            s = s - item_weight(items[r-1]);
        }
        r--;
    }

    result = knap[array_length][max_weight];
    knap = knap_destroy(knap, array_length);
    return result;

error:
    knap_destroy(knap, array_length);
    perror("knapsack_dynamic_selection");
    return UINT_MAX;
}

