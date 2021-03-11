#include <stdio.h> /* printf()...           */
#include "set.h"   /* Interfaz del TAD set  */

static void
print_set(set s) {
    /* Muestra por pantalla el contenido de un conjunto de enteros */
    /*
     * Es crucial que las funciones:
     *   - set_copy()
     *   - set_get()
     *   - set_elim()
     *   - set_is_empty()
     *
     * estén bien programadas para que se muestre correctamente.
     */
    set saux = set_copy(s);
    printf("{");
    while (!set_is_empty(saux)) {
        type_elem e;
        e = set_get(saux);
        printf("%i", e);
        saux = set_elim(saux, e);
        if (!set_is_empty(saux))
            printf(", ");
     }
    printf("}");
    saux = set_destroy(saux);
}

static void
show_status(set s, const char *name) {
    /*
     * Muestra por pantalla: - La etiquena 'name'
     *                       - El contendio del conjunto
     *                       - Su longitud
     *                       - Si es o no vacío
     */
    /* Se muestra la etiqueta */
    printf("{ %s == ", name);
    /* Se muestra el contenido del conjunto */
    print_set(s);
    printf(" /\\ ");
    /* Se muestra el cardinal */
    printf("|%s| = %i /\\ ", name, set_cardinal(s));
    /* Se indica si es vacío o no */
    if (set_is_empty(s)) printf("empty"); else printf("not empty");
    printf(" }");
    printf("\n\n");
}

int
main() {

    /*Creamos un conjunto y verificamos si esta vacio*/
    set s = set_empty();

    show_status(s, "s");
  

    /*Agregamos elementos al conjunto*/
    printf("Agregamos elementos\n");
    s = set_add(s, 1);
    s = set_add(s, 2);
    s = set_add(s, 3);
    s = set_add(s, 4);
    s = set_add(s, 5);
    show_status(s, "s");

    /*Eliminamos un elemento*/
    printf("Eliminamos un elemento\n");
    s = set_elim(s,1);
    show_status(s, "s");
    

    /*Union de dos conjuntos*/
    printf("Union\n");
    set s1 = set_empty();
    s1 = set_add(s1, 6);
    s1 = set_add(s1, 8);
    s1 = set_add(s1, 8);

    s = set_union(s, s1);
    show_status(s, "s");

    /*Probando diferencia de dos conjuntos*/
    printf("Diferencia\n");
    s = set_dif(s, s1);
    show_status(s, "s");

    /*Probando interseccion*/
    printf("Interseccion\n");
    set s2 = set_empty();
     set s3 = set_empty();

    s2 = set_inters(s2, s3);
    show_status(s2, "s2");
 //s2 = set_destroy(s2);
    /*Liberamos la memoria pedida*/
    s = set_destroy(s);
    s1 = set_destroy(s1);
    s2 = set_destroy(s2);
    s3 = set_destroy(s3);
    return 0;
}

