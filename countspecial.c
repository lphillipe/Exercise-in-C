#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

int main(void)
{
    int letras = 0;
    int digitos = 0;
    int espacos = 0;
    int outros = 0;

    string user = get_string("Digite um texto: ");

    for (int i = 0; user[i] != '\0'; i++)
    {
        char c = user[i];

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
