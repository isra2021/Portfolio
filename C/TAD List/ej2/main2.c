#include "list.h"





int main(){
    /*
    list l = empty();

    Probando is_empty
    printf("Esta vacia la lista? %d\n", is_empty(l));
    
    Probando addr y addl
    l = addr(l, 1);
    l = addr(l, 2);
    l = addr(l, 3);
    l = addr(l, 4);
    l = addr(l, 5);
   
    print_list(l);
    printf("Esta vacia la lista? %d\n", is_empty(l));

    Probando tail
    printf("Probando tail\n");
    l = tail(l);
    print_list(l);

    Probando head
    printf("Probando head\n");
    printf("El primer elemento es: %d\n", head(l));
    

    Probando index
    printf("Elemento en la posicion n-esima es: %d\n", index(l, 3));
    

    Probando concat
    printf("Probando concat\n");
    list l1 = empty();
    l1 = addr(l1, 1);
    l1 = addr(l1, 2);
    l1 = addr(l1, 3);

    list l2 = empty();
    l2 = addr(l2, 4);
    l2 = addr(l2, 5);
    l2 = addr(l2, 6);

    l1 = concat(l1, l2);
    print_list(l1);
    
    
    
    Probando take
    printf("Probando take\n");
    list l4 = empty();
    l4 = addr(l4, 1);
    l4 = addr(l4, 2);
    l4 = addr(l4, 3);
    l4 = addr(l4, 4);
    l4 = addr(l4, 5);
    l4 = take(l4, 1);
    print_list(l4);
    
    
    
    Probando drop
    printf("Probando drop\n");
    list l3 = empty();
    l3 = addr(l3, 1);
    l3 = addr(l3, 2);
    l3 = addr(l3, 3);
    l3 = addr(l3, 4);
    l3 = addr(l3, 5);

    l3 = drop(l3, 3);
    print_list(l3);
    */
    

    /*Probando el conjnto*/
    list l10 = empty();
    //l10 = addr(l10, 1);
    //l10 = addr(l10, 2);
    l10 = list_add_at(l10,0, 0);
    l10 = list_add_at(l10,1, 1);
    l10 = list_add_at(l10,2, 2);
    l10 = list_add_at(l10,3, 3);
    l10 = list_add_at(l10,4, 4);
    l10 = list_add_at(l10,5, 5);
    l10 = list_add_at(l10,4,10);
    
    



    
    /*
    l10 = list_add_at(l10, 0, 2);
    l10 = list_add_at(l10, 1, 4);
    l10 = list_add_at(l10, 2, 6);

    l10 = list_add_at(l10, 0, 0);
    l10 = list_add_at(l10, 1, 1);

    l10 = list_add_at(l10, 3, 3);
    l10 = list_add_at(l10, 5, 5);
    l10 = list_add_at(l10, 7, 7);
*/

    
   
  
    print_list(l10);

    
    /*Liberando memoria*/
    //l = destroy(l);
    //l4 = destroy(l4);
    //l3 = destroy(l3);
    //l1 = destroy(l1);
    l10 = destroy(l10);

    

   

    
    

    return 0;
}