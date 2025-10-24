#include <stdio.h>

void swapfloat(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    float x = 1.5f;
    float y = 2.5f;

    printf("Antes da troca: x = %.2f, y = %.2f\n", x, y);
    swapfloat(&x, &y);
    printf("Depois da troca: x = %.2f, y = %.2f\n", x, y);

    return 0;
}