#include <stdio.h>
#include <stdlib.h>

typedef struct _person {
    int age;
    char name_initial;
} person_t;


int main(void) {

    int x = 1;
    person_t m = {90, 'M'};
    int a[] = {0, 1, 2, 3};

    int* p = &x;
    *p = 9;
    person_t* p2 = &m;
    p2 -> age = 100;
    p2 -> name_initial = 'F';
    p = a;
    *(p+1) = 42;


    printf("x = %d\n", x);
    printf("m = (%d, %c)\n", m.age, m.name_initial);
    printf("a[1] = %d\n", a[1]);

    return (EXIT_SUCCESS);
}
