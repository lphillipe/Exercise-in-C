#include <stdio.h>

void ex1_1(void)
{
    int x = 100;
    int *p = &x;

    *p = 50;
    printf("Valor de x: %d\n", x);
}

void ex1_2(void)
{
    int a = 1;
    int b = 2;
    int *ptr = &b;

    ptr = &a;
    printf("Valor apontado por ptr: %d\n", *ptr);
}

void ex1_3(void)
{
    int num = 7;
    int *p1 =&num;
    int **p2 = &p1;

    // Predição 1.3: O que é impresso?
    printf("Valor de num via p2: %d\n", **p2);
}

int main(void)
{
    ex1_1();
    ex1_2();
    ex1_3();
    return 0;
}