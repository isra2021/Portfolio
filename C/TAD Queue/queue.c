#include "queue.h"
#include <stdlib.h>

struct node_t {
    node next;
    elem_t elem;
};

struct queue_t {
    node first;
    node end;
    size_t_ size;
};

queue queue_empty(void) {
    queue q = malloc(sizeof(struct queue_t));
    if(!q) return NULL;
    q -> first = NULL;
    q -> end = NULL;
    q -> size = 0;
    return q;
}

static node create_node(elem_t elem) {
    node new = malloc(sizeof(struct node_t));
    if(!new) return NULL;
    new -> next = NULL;
    new -> elem = elem;
    return new;
}

queue queue_enqueue(queue q, elem_t elem) {
    if(elem == ERROR) return NULL;
    node new = create_node(elem);
    if(queue_is_empty(q)){
        q -> first = new;
        q -> end = new;
    }
    else{
        q -> end -> next = new;
        q -> end = new;
    }
    q -> size += 1;
    return q;
}

size_t_ queue_size(queue q) {
    if(!q) return 0;
    return q -> size;
}

bool queue_is_empty(queue q) {
    return queue_size(q) == 0;
}

elem_t queue_first(queue q) {
    if(!q) return ERROR;
    return q -> first -> elem;
}

queue queue_dequeue(queue q) {
    if(!q) return NULL;
    if(queue_is_empty(q)) return q;
    node curr = q -> first;
    q -> first = q -> first -> next;
    q -> size -= 1;
    free(curr);
    curr = NULL;
    return q;
}

void queue_print(queue q) {
    if(q){
        node curr = q -> first;
        while(curr != NULL){
            printf("%d ", curr -> elem);
            curr = curr -> next;
        }
        printf("\n");
    }
}

queue queue_free(queue q) {
    if(!q) return NULL;
    while(!queue_is_empty(q)){
        q = queue_dequeue(q);
    }
    q -> first = NULL;
    q -> end = NULL;
    free(q);
    return (q = NULL);
}