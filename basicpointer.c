#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;

    printf("Value of x: %i\n", n);
    printf("Address of x: %p\n", &n);
    printf("Value of px (address of x): %p\n", p);
    printf("Address keep in px: %i\n", *p);
}