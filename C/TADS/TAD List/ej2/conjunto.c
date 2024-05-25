#include "conjunto.h"
#include <stdlib.h>
#include <assert.h>

struct set_t{
    list set;
};


set empty_set(){
    set s = malloc(sizeof(struct set_t));
    s -> set = empty();
    return s;
}

set set_add(set s, type_elem elem){
    assert(s != NULL);
    set saux = empty_set();
    saux -> set = copy(s -> set);
    uint n = 0;
    bool is_member = false;
    type_elem d;    
    while(!is_empty(saux -> set) && !is_member){
        d = head(saux -> set);
        if(d == elem){
            is_member = true;
        }
        else if(d < elem){
            n += 1;
        }
        saux -> set = tail(saux -> set);
    }
    if(!is_member) s -> set = list_add_at(s -> set, n, elem);
    saux  = set_destroy(saux);
    return s;
}





set set_destroy(set s){
    s -> set = destroy(s -> set);
    free(s);
    return (s = NULL);
}


