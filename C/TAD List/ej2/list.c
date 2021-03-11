#include "list.h"
#include <assert.h>
#include <stdlib.h>

struct node_t{
    node next;
    type_elem elem;
};

struct list_t{
    node first;
    node end;
    uint length;
};

list empty(){
    list l = (list) malloc(sizeof(struct list_t));
    if(l == NULL) return NULL;
    l -> first = l -> end = NULL;
    l -> length = 0;
    return l;
}

bool is_empty(list l){
    assert(l != NULL);
    return (l -> length == 0);
}

list addl(list l, type_elem elem){
    assert(l != NULL);
    node new_node = (node) malloc(sizeof(struct node_t));
    if(new_node == NULL) return NULL;
    new_node -> elem = elem;
    new_node -> next = NULL;
    if(is_empty(l)){
        l -> first = new_node;
        l -> end = new_node;
    }
    else{
        new_node -> next = l -> first;
        l -> first = new_node;
    }
    l -> length += 1;
    return l;
}

list addr(list l, type_elem elem){
    assert(l != NULL);
    node new_node = (node) malloc(sizeof(struct node_t));
    if(new_node == NULL) return NULL;
    new_node -> elem = elem;
    new_node -> next = NULL;
    if(is_empty(l)){
        l -> first = new_node;
    }   
    else{
        l -> end -> next = new_node;
    }
    l -> end = new_node;
    l -> length += 1;
    return l;
}

list tail(list l){
    assert(l != NULL && !is_empty(l));
    node curr = l -> first;
    l -> first = l -> first -> next;
    free(curr);
    curr = NULL;
    l -> length -= 1;
    return l;
}

type_elem head(list l){
    assert(!is_empty(l));
    return l -> first -> elem;
}

uint length(list l){
    assert(l != NULL);
    return l -> length;
}

list concat(list l1, list l2){
    assert(l1 != NULL && l2 != NULL);
    if(is_empty(l1) && is_empty(l2)) return NULL;
    if(is_empty(l1) && !is_empty(l2)) return l2;
    if(!is_empty(l1) && is_empty(l2)) return l1;
    l1 -> length = l1 -> length + l2 -> length;
    l1 -> end -> next = l2 -> first;
    l1 -> end = l2 -> end;
    free(l2);
    l2 = NULL;
    return l1;
}

type_elem index(list l, uint n){
    assert(l != NULL && !is_empty(l) && n < length(l));
    node curr = l -> first;
    for(uint i = 0; i < length(l) && i != n; i++){
        curr = curr -> next;
    }
    return curr -> elem;
}

list take(list l, uint n){
    assert(l != NULL && !is_empty(l));
    node tmp1 = l -> first;
    node tmp2 = tmp1;
    for(uint i = 0; i+1 < n; i++){
        tmp1 = tmp1 -> next;
    }
    l -> end = tmp1;
    l -> length = n;
    tmp2 = l -> end -> next;
    l -> end -> next = NULL;
    list l1 = empty();
    l1 -> first = tmp2;
    l1 = destroy(l1);
    free(tmp2);
    tmp2 = NULL;
    return l;
}

list drop(list l, uint n){
    assert(l != NULL && n <= length(l));
    node tmp2 = NULL;
    node tmp1 = l -> first;
    tmp2 = tmp1;
    for(uint i = 0; i < n; i++){
        tmp2 = tmp2 -> next;
        free(tmp1);
        tmp1 = tmp2;
    }
    l -> first = tmp1;
    l -> length -= n;
    return l;
}

list copy(list l1){
    assert(l1 != NULL);
    list copy = empty();
    copy -> first = l1 -> first;
    copy -> end = l1 -> end;
    copy -> length = l1 -> length;
    return copy;
}

list destroy(list l){
    assert(l != NULL);
    node curr = l -> first;
    for(uint i = 0; i < length(l); i++){
        l -> first = l -> first -> next;
        free(curr);
        curr = l -> first;
    }
    free(l);
    return (l = NULL);
}

void print_list(list l){
    assert(l != NULL && !is_empty(l));
    node curr = l -> first;
    for(uint i = 0; i < length(l); i++){
        printf("%d ", curr -> elem);
        curr = curr -> next;
    }
    printf("\n");
}


list list_add_at(list l, uint n, type_elem elem){
    assert(l != NULL);
    node curr = l -> first;
    node prev = NULL;
    uint i = 0;
    while(i < n && curr != NULL){
        prev = curr;
        curr = curr -> next;
    }
    node new = (node) malloc(sizeof(struct node_t));
    if(new == NULL) return NULL;
    new -> elem = elem;

    if(i == n && curr != NULL){
        if(prev != NULL){
            prev -> next = new;
            new -> next = curr;
            l -> length += 1;
        }
        else{
            l -> first = new;
            l -> end = new;
            l -> end -> next = NULL;
            l -> length += 1;        
        }
    }
    else if(curr == NULL && i < n){
        if(prev != NULL){
            prev -> next = new;
            l -> end = new;
            l -> end -> next = NULL;
            l -> length += 1;
        }
        else{
            l -> first = new;
            l -> end = new;
            l -> end -> next = NULL;
            l -> length += 1;
        }
    }
        else{
            l = addl(l, elem);
        }
    return l;
}

/*
bool pertenece(list l, type_elem elem){
    assert(!is_empty(l) && l != NULL);
    list copy = copy(l);
    type_elem d;
    bool b = false;
    while(!is_empty(copy) && !b){
        d = head(copy);
        b = d == elem;
        copy = tail(copy);
    }
    copy = destroy(copy);
    return b;
}
*/






/*
list list_add_at(list l, type_elem elem){
    node new_node = malloc(sizeof(struct node_t));
    new_node -> elem = elem;
    new_node -> next = NULL;
    node curr = l -> first;
    node prev = NULL;
    while(curr != NULL && curr -> elem < elem){
        prev = curr;
        curr = curr -> next;
    }
    if(l == NULL){
            
    }
    if(curr && curr -> elem == elem){
        return l;
    }
    if(prev-> elem > elem){
        l -> first = new_node;
        new_node -> next = prev;
        l -> length += 1;
    }
    else if(prev-> elem < elem){
        prev -> next = new_node;
        new_node -> next = curr;
        prev = prev -> next;
        l -> length += 1;
    }
    return l;
}


list list_add_at(list l, uint n, type_elem elem){
    //assert(n < length(l));
    node curr = l -> first;
    node prev = NULL;
    for(uint i = 0; i < n && i < length(l); i++){
        prev = curr;
        curr = curr -> next;
    }
    
    if((is_empty(l)) || (n == 0 && !is_empty(l))){
        l = addl(l, elem);
    }
    else{
        node new = malloc(sizeof(struct node_t));
        if(new == NULL) return NULL;
        new -> elem = elem;
        prev -> next = new;
        new -> next = curr;
        l -> length += 1;
    }
    return l;
}



list list_add_at(list l, uint n, type_elem elem){
    assert(l != NULL);
    node curr = l -> first;
    node prev = NULL;
    for(uint i = 0; i < n && curr != NULL; i++){
        prev = curr;
        curr = curr -> next;
    }
    if(){

    }
    node new = (node) malloc(sizeof(struct node_t));
    new -> elem = elem;
    aux -> next = new;



    return l;
}
*/






