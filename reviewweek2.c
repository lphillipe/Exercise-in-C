#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    string texto = get_string("Digite um texto: ");

    int letras = 0;
    int digitos = 0;
    int espacos = 0;
    int outros = 0;

    for (int i = 0; texto[i] != '\0'; i++)
    {
        char c = texto[i];

        if (isalpha(c))
        {
            letras++;
        }
        else if (isdigit(c))
        {
            digitos++;
        }
        else if (isspace(c))
        {
            espacos++;
        }
        else
        {
            outros++;
        }
    }
    printf("Letras: %i\n", letras);
    printf("Digitos: %i\n", digitos);
    printf("Espaços: %i\n", espacos);
    printf("Outros: %i\n", outros);

}