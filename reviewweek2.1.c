#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int main(void)
{
    int freq[26] = {0};
    string texto = get_string("Digite um texto: ");

    for (int i = 0; texto[i] != '\0'; i++)
    {
        char c = tolower(texto[i]);
        
        if (c >= 'a' && c <= 'z')
        {
            int pos = c - 'a';
            freq[pos]++;
        }
    }

    for (int i = 0; i < 26; i++)

    {
       if (freq[i] > 0)
       {
            printf("%c: %d\n", 'a' + i, freq[i]);
       }
    }
}