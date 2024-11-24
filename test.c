#include "stdio.h"
#include "stdlib.h"

int main()
{
    int a =5;
    int* p = &a;
    int** pp =&p;
    printf("a : %d\n", a);
    printf("&a : %d\n", &a);
    printf("p : %d\n", p);
    printf("*p : %d\n", *p);
    printf("&p : %d\n", &p);
    printf("pp : %d\n", pp);
    printf("*pp : %d\n", *pp);
    printf("&pp : %d\n", &pp);
}