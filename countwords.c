#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    string palavra = get_string("Digite uma palavras: ");
    int grande = 0;
    int pequeno = 0;
    int digitos = 0;
    int outros = 0;

    for(int i = 0; palavra[i] != '\0'; i ++)
    {
        char c = palavra[i];

        if(isupper(c))
        {
            grande++;
        }
        else if(islower(c))
        {
            pequeno++;
        }
        else if(isdigit(c))
        {
            digitos++;
        }
        else
        {
            outros++;
        }
    }
    printf("Letras maiúsculas: %d\n", grande);
    printf("Letras minúsculas: %d\n", pequeno);
    printf("Digitos: %d\n", digitos);
    printf("Outros: %d\n", outros);
}
