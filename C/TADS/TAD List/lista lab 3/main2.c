#include "list.h"





int main(){

    list l = empty();
    /*Probamos is_empty*/
    //printf("La lista esta vacia? %d\n", is_empty(l));

    /*Probando addl
    printf("Probando addl\n");
    l = addl(l, 1);
    l = addl(l, 2);
    print_list(l);
    printf("La lista esta vacia? %d\n", is_empty(l));

    */
    /*Probando addr
    printf("Probando addr\n");
    l = addr(l, 3);
    l = addr(l, 4);
    print_list(l);
    printf("La lista esta vacia? %d\n", is_empty(l));
    */

    /*Probando head
    printf("Probando head\n");
    printf("la cabeza es: %d\n", head(l));

    */

    /*Probando tail
    printf("Probando tail\n");
    l = tail(l);
    l = tail(l);
    printf("La lista esta vacia? %d\n", is_empty(l));
    l = tail(l);
    l = tail(l);
    printf("La lista esta vacia? %d\n", is_empty(l));
    l = addr(l, 1);
    print_list(l);
    printf("\n");
    /*


    /*Probando concat*/
    printf("Probando concat\n");
    list l1 = empty();
    l1 = addr(l1, 1);
    l1 = addr(l1, 2);
    l1 = addr(l1, 3);

    list l2 = empty();
    l2 = addr(l2, 1);
    l2 = addr(l2, 1);
    l2 = addr(l2, 1);

    l1 = concat(l1, l2);
    print_list(l1);

    l = destroy(l);
    l1 = destroy(l1);

    





    return 0;
}