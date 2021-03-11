#include "queue.h"

int main() {

    queue q = queue_empty();
    printf("El size es: %d\n", queue_size(q));
    
    printf("Agregamos elementos a la cola\n");
    q = queue_enqueue(q,1);
    q = queue_enqueue(q,2);
    q = queue_enqueue(q,3);
    q = queue_enqueue(q,4);
    queue_print(q);

    printf("Sacamos elementos a la cola\n");
    q = queue_dequeue(q);
    q = queue_dequeue(q);
    q = queue_dequeue(q);
    q = queue_dequeue(q);
    q = queue_dequeue(q);
    queue_print(q);

    printf("Es vacia la queue? %d\n",queue_is_empty(q));
    printf("El size es: %d\n", queue_size(q));





    q = queue_free(q);

    return 0;
}