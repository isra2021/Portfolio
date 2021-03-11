#ifndef _ENQUEUE_H_
#define _ENQUEUE_H_
#define ERROR 2147483647
#include <stdbool.h>
#include <stdio.h>

typedef unsigned int size_t_;
typedef int elem_t;
typedef struct node_t* node;
typedef struct queue_t* queue;

/* CONSTRUCTORS */

queue queue_empty(void);
/*
 * DESC: Creates a new empty queue
 * USAGE: q = queue_empty();
 * POS  : {queue_is_empty(q)}
 */

queue queue_enqueue(queue q, elem_t elem);
/*
 * DESC: Add an element to the end of a queue 'q'
 * PRE  : {queue_size(q) == N}
 * USAGE: q = queue_enqueue(q, elem);
 * POS  : {queue_size(q) == N + 1}
 */


/* OPERATIONS */

size_t_ queue_size(queue q);
/*
 * DESC: Returns the size of queue 'q'
 * USAGE: n = queue_size(q);
 */

bool queue_is_empty(queue q);
/*
 * DESC: Indicates if there are no elements in the queue 'q'
 * USAGE: is_empty = queue_is_empty(q);
 * POS  : {is_empty == (queue_size(q) == 0)}
 */

elem_t queue_first(queue q);
/*
 * DESC: Returns the first item in a queue 'q'
 * PRE  : {!queue_is_empty(q) /\ queue_size(q) == N}
 * USAGE: elem = queue_first(q);
 * POS  : {e == q -> first -> elem}
 */

queue queue_dequeue(queue q);
/*
 * DESC: Remove the first item from a queue 'q'
 * PRE  : {!queue_is_empty(q) /\ queue_size(q) == N}
 * USAGE: q = queue_dequeue(q);
 * POS  : {queue_size(q) == N - 1}
 */

queue queue_free(queue q);
/*
 * DESC: Destroy queue 'q' by releasing all allocated resources.
 * USAGE: q = queue_free(q);
 * POS  : {q == NULL}
 */


/* Funcion extra */
void queue_print(queue q);
/*
 * DESC: Print a queue on the screen 'q'
 * PRE  : {!queue_is_empty(q)}
 * USAGE: queue_print(q);
 */

#endif
