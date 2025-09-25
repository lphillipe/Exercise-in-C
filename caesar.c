#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if(argc !=2)
    {
        printf("Usou: ./caesar key\n");
        return 1;
    }

    for(int i = 0; argv[1][i] != '\0'; i++)
    {
        if(!isdigit(argv[1][i]))
        {
            printf("Chave deve ser um número.\n");
            return 1;
        }
    }
    int key = atoi(argv[1]);
    key = key % 26;

    string plaintext = get_string("Digite o texto: ");

    for(int i = 0; plaintext[i] != '\0'; i ++)
    {
        char c = plaintext[i];

        if(isupper(c))
        {
            char cifrado = ((c - 'A' + key) % 26) + 'A';
            printf("%c", cifrado);
        }
        else if(islower(c))
        {
            char cifrado = ((c - 'a' + key) % 26) + 'a';
            printf("%c", cifrado);
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
}
