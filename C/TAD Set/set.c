#include "set.h"

#include <stdlib.h>
#include <assert.h>

struct s_set {
    list sorted_list;
};

set
set_empty(void) {
    set s = (set) malloc(sizeof(struct s_set));
    if(s == NULL) return NULL;
    s -> sorted_list = list_empty();
    return s;
}

set
set_add(set s, type_elem e) {
    assert(s != NULL);
    unsigned int n = 0;
    set saux = set_copy(s);
    bool is_member = false;
    type_elem d;

    while(!set_is_empty(saux) && !is_member){
        d = set_get(saux);
        if(d == e){
            is_member = true;
        }
        else if(d < e){
            n = n+1;
        }
        saux -> sorted_list = list_tail(saux -> sorted_list);
    }
    if(!is_member) s -> sorted_list = list_add_at(s -> sorted_list, n, e);
    saux = set_destroy(saux);
    return s;
}

unsigned int
set_cardinal(set s) {
    assert(s != NULL);
    return list_length(s -> sorted_list);
}

bool
set_is_empty(set s) {
    assert(s != NULL);
    return list_is_empty(s -> sorted_list);
}

bool
set_member(type_elem e, set s) {
    assert(s != NULL && !set_is_empty(s));
    set saux = set_copy(s);
    type_elem d;
    bool is_member = false;
    while(!set_is_empty(saux) && !is_member){
        d = set_get(saux);
        is_member = e == d;
        saux -> sorted_list = list_tail(saux -> sorted_list);
    }
    saux = set_destroy(saux);
    return is_member;
}

set
set_elim(set s, type_elem e) {
    assert(s != NULL && !set_is_empty(s) && set_member(e, s));
    unsigned int n = 0;
    unsigned int length = set_cardinal(s);
    while(n < length && list_index(s -> sorted_list, n) != e){
        n += 1;
    }
    s -> sorted_list = list_elim_at(s -> sorted_list, n);
    return s;
}

set
set_union(set s, set s0) {
    assert(s != NULL && s0!= NULL);
    set saux = set_copy(s0);
    type_elem e;
    while(!set_is_empty(saux)){
        e = set_get(saux);
        s = set_add(s, e);
        saux -> sorted_list = list_tail(saux -> sorted_list);
    }
    saux = set_destroy(saux);
    return s;
}

set
set_inters(set s, set s0) {
    assert(s != NULL && s0!= NULL);
    set saux = set_copy(s);
    type_elem e;
    while(!set_is_empty(saux)){
        e = set_get(saux);
        if(!set_member(e, s0)) s = set_elim(s, e);
        saux -> sorted_list = list_tail(saux -> sorted_list);
    }
    saux = set_destroy(saux);
    return s;
}

set
set_dif(set s, set s0) {
    assert(s != NULL && s0!= NULL);
    set saux = set_copy(s0);
    type_elem e;
    while(!set_is_empty(saux)){
        e = set_get(saux);
        if(set_member(e, s)) s = set_elim(s, e);
        saux -> sorted_list = list_tail(saux -> sorted_list);
    }
    saux = set_destroy(saux);
    return s;
}

type_elem
set_get(set s) {
    assert(s != NULL && !set_is_empty(s));
    return list_head(s -> sorted_list);
}

set
set_copy(set s) {
    assert(s != NULL);
    set copy = set_empty();
    copy -> sorted_list = list_copy(s -> sorted_list);
    return copy;
}

set
set_destroy(set s) {
    assert(s != NULL);
    s -> sorted_list = list_destroy(s -> sorted_list);
    free(s);
    return (s = NULL);
}