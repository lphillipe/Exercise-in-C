#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
    char *s = "HI!"; // String constante (endereço de memoria)

    int n = strlen(s) + 1; // calcular o tamanho da string

    char *t = malloc(n * sizeof(char)); // alocar memoria dinamicamente

    if (t == NULL) // verificar se a alocação foi bem sucedida
    {
        return 1;
    }

    strcpy(t, s); 

    if (n > 0) 
    {
        t[0] = 'L'; // 'L'I!
    }

    printf("String original (s): %s\n", s); // HI!
    printf("String clonada (t): %s\n", t); // LI! 

    free(t); // liberar a memoria alocada

    return 0;
}