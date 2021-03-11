#include<stdio.h>
#include<stdlib.h>


int main()
{
    int x = 5;
    int y = -4;
    int *p = &x; 
    int *q = &y;
    int *r = p;
    x = -4;
    r = q;
    y = 5;
    
    /* PLEASE COMPLETE - PART A */
    
    printf("El valor de *p=%d, *q=%d y *r=%d\n", *p, *q, *r);
    
    x = 5;
    y = -4;
    p = &x;
    q = &y;
    r = p;
    p = q;
    q = r;

    /* PLEASE COMPLETE - PART B */
    
    printf("El valor de *p=%d, *q=%d y *r=%d\n", *p, *q, *r);
    
    return (EXIT_SUCCESS);
}
