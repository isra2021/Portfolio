#include<stdio.h>
#include<stdlib.h>

int main()
{

    int x = 20;
    int *p = &x;
    *p = 60;
    
    printf("x = %d\n", x);

    return (EXIT_SUCCESS);
}
