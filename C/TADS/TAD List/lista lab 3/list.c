#include "list.h"
#include <assert.h>
#include <stdlib.h>

struct node_t{
    list next;
    type_elem elem;
};

list empty(){
    list l = NULL;
    return l;
}

bool is_empty(list l){
    return l == NULL;
}


list addl(list l, type_elem elem){
    list node = (list) malloc(sizeof(struct node_t));
    if(node == NULL) return NULL;
    node -> elem = elem;
    node -> next = NULL;
    if(l == NULL){
        l = node;
    }
    else{
        node -> next = l;
        l = node;
    }
    return l;
}

type_elem head(list l){
    assert(!is_empty(l));
    return l -> elem;
}

list tail(list l){
    assert(l != NULL && !is_empty(l));
    list tmp = l;
    l = l -> next;
    free(tmp);
    tmp = NULL;
    return l;
}

list addr(list l, type_elem elem){
    list new_node = (list)malloc(sizeof(struct node_t));
    new_node -> elem = elem;
    new_node -> next = NULL;
    if(l == NULL){
        l = new_node;
        return l;
    }
    list tmp = l;
    while(tmp -> next != NULL){
        tmp = tmp -> next;
    }
    tmp -> next = new_node;
    return l;
}

uint length(list l){
    uint length = 0;
    if(l == NULL) return length;
    list tmp = l;
    while(tmp != NULL){
        length += 1;
        tmp = tmp -> next;
    }
    return length;
}

list concat(list l1, list l2){
    if(l1 == NULL && l2 != NULL) return l2;
    if(l1 != NULL && l2 == NULL) return l1;
    if(l1 == NULL && l2 == NULL) return NULL;
    list tmp = l1;
    while(tmp -> next != NULL){
        tmp = tmp -> next;
    }
    tmp -> next = l2;
    l2 = NULL;
    return l1;
}

void print_list(list l){
    assert(!is_empty(l));
    list tmp = l;
    while(tmp != NULL){
        printf("%d ",tmp -> elem);
        tmp = tmp -> next;
    }
    printf("\n");
}

list destroy(list l){
    list tmp = l;
    while(tmp != NULL){
        l = l -> next;
        free(tmp);
        tmp = l;
    }
    free(l);
    return (l = NULL);
}



