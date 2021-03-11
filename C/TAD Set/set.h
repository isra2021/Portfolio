#ifndef _SET_H_
#define _SET_H_

#include <stdbool.h>   /* Definition of bool      */
#include "type_elem.h" /* Definition of type_elem */
#include "list.h"

typedef struct s_set * set;

/* CONSTRUCTORS */

set set_empty(void);
/*
 * DESC: Creates a new empty set
 * USAGE: s = set_empty();
 * POS  : {set_is_empty(s)}
 */

set set_add(set s, type_elem e);
/*
 * DESC: Add a non-repeating element 'e', keeping the set 's' ordered
 * PRE  : {set_length(s) == N}
 * USAGE: s = set_add(s, e);
 * POS  : {set_cardinal(s) == N + 1 /\ set 's' ordered}
 */


/* OPERATIONS   */

unsigned int set_cardinal(set s);
/*
 * DESC: Returns the size of set 's'
 * USAGE: n = set_cardinal(s);
 */

bool set_is_empty(set s);
/*
 * DESC: Indicates if there are no elements in set 's'
 * USAGE: is_empty = set_is_empty(s);
 * POS  : {is_empty == (set_cardinal(s) == 0)}
 */

bool set_member(type_elem e, set s);
/*
 * DESC: Indicates if an element 'e' belongs to the set 's'
 * PRE  : {!set_is_empty(s) /\ set_cardinal(s) == N}
 * USAGE: is_member = set_member(e,s);
 * POS  : {is_member \/ !is_member} 
 */

set set_elim(set s, type_elem e);
/*
 * DESC: Remove an item 'e' from the set 's'
 * PRE  : {!set_is_empty(s) /\ set_cardinal(s) == N}
 * USAGE: s = set_elim(s,e);
 * POS  : {set_cardinal(s) == N - 1 /\ set 's' ordered}
 */

set set_union(set s, set s0);
/*
 * DESC: Union of set 's' and 's0'
 * PRE  : {set 's' ordered/\ set 's0' ordered}
 * USAGE: s = set_union(s,s0);
 * POS  : {set_cardinal(s) == set_cardinal(s) + set_cardinal(s0) /\ set 's' ordered}
 */

set set_inters(set s, set s0);
/*
 * DESC: Intersection of set 's' and 's0'
 * PRE  : {set 's' ordered/\ set 's0' ordered}
 * USAGE: s = set_inters(s,s0);
 * POS  : {set_cardinal(s) == Number of elements that belong to the set s0 /\ set 's' ordered}
 */

set set_dif(set s, set s0);
/*
 * DESC: Remove from all elements belonging to s0
 * PRE  : {set 's' ordered/\ set 's0' ordered}
 * USAGE: s = set_dif(s,s0);
 * POS  : {set_cardinal(s) == Number of elements that do not belong to s0/\ set 's' ordered}
 */

type_elem set_get(set s);
/*
 * DESC: Gets any element from set 's'
 * PRE  : {!set_is_empty(s) /\ set_cardinal(s) == N}
 * USAGE: e = set_get(l);
 * POS  : {e == list_index(s -> sorted_list, 0)}
 */

set set_copy(set s);
/*
 * DESC: Returns a copy of the set 's' with new memory.
 * USAGE: s0 = set_copy(s);
 * POS  : {set_cardinal(s) == set_cardinal(s0) /\ (s != s0 \/ set_is_empty(s)}
 */

set set_destroy(set s);
/*
 * DESC: Destroy set 's' by freeing all the allocated resources.
 * USAGE: s = set_destroy(s);
 * POS  : {s == NULL}
 */

#endif
