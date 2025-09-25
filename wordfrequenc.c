#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

int main(void)
{
    int freq[26] = {0};
    string texto = get_string("Digite um texto: ");

    for (int i = 0; texto[i] != '\0'; i++)
    {
        char c = tolower(texto[i]);
    }
}