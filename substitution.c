#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usou: ./substitution + chave");
        return 1;
    }

    string key = argv[1];

    if (strlen(key) != 26)
    {
        printf("A chave deve conter 26 caracteres.");
        return 1;
    }

    for (int i = 0; key[i] != '\0'; i++)
    {
        char c = key[i];

        if (!isalpha(c))
        {
            printf("A chave deve apenas contar caracteres alfabéticos.\n");
            return 1;
        }
    }
    bool seen[26] = {false};

    for (int i = 0; i < 26; i ++)
    {
        char c = toupper(key[i]);
        int pos = c - 'A';

        if (seen[pos])
        {
            printf("Erro: chave contém letras repetidas.\n");
            return 1;
        }
        seen[pos] = true;
    }

    for (int i = 0; i < 26; i++)
    {
        key[i] = toupper(key[i]);
    }

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0; plaintext[i] != '\0'; i ++)
    {
        char c = plaintext[i];

        if (isupper(c))
        {
            char cifrado = key[c - 'A'];
            printf("%c", cifrado);
        }
        else if (islower(c))
        {
            char cifrado = tolower(key[c - 'a']);
            printf("%c", cifrado);
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");

}
