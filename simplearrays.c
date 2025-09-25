#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numeros[5];
    int soma = 0;

    for(int i = 0; i < 5; i ++)
    {
        printf("Digite um número: ");
        scanf("%d", &numeros[i]);
        soma += numeros[i];
    }
    for(int i = 0; i < 5; i ++)
    {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    for (int i = 4; i >= 0; i --)
    {
        printf("%d ", numeros[i]);
    }
    printf("\n");
    printf("Soma: %d\n", soma);
}
