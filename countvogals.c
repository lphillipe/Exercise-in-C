#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    string palavra = get_string("Digite uma palavra: ");
    int contador = 0;

    for(int i = 0; palavra[i] != '\0'; i ++)
    {
        char c = tolower(palavra[i]);

        if(c == 'a' || c == 'e' || c =='i' || c == 'o' || c =='u')
        {
            contador++;
        }

    }
    printf("Número de vogais: %d\n", contador);

}
