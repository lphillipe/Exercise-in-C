#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *copia_e_modifica(char *s)
{
    // 1. Obtain the size (strlen + 1)
    // Example: If s is "ABC", strlen(s) is 3, we require of 4 bytes in total.
    int n = strlen(s) + 1; // Why + 1? Because of the null terminator '\0'

    // 2. Aloccate the new space in heap to a new array of chars
    // (n * sizeof(char)) is the same as (n * 1 byte), that is, n bytes.
    char *t = malloc(n * sizeof(char));

    // 3. Verification of NULL (If the malloc failed)
    if (t == NULL)
    {
        printf("Alocation of memory failed to copy.\n");
        return NULL;
    }

    // 4. Loop the copy character by character
    // Using n ( the total size, including the \0) to garantee that the \0 be copied.
    for (int i = 0; i < n; i ++)
    {
        t[i] = s[i];

        // Why that works ?
        // t[i] is syntactically identifcal a *(t + i) - Pointer arithmetic!.
    }
    // 5. Modify only the copy 't'

    if (n > 0)
    {
        // if the string is not empty, change the first character (indice 0)
        t[0] = 'Z';
    }

    // 6. Return the pointer to the new string.
    return t;
}

int main(void)
{
    char s[] = "ABC";

    printf("Original string before copy: %s\n", s);

    char *copia = copia_e_modifica(s);

    if (copia != NULL)
    {
        printf("Original (s) after modification: %s\n", s); // Should be "ABC" (Not change)
        printf("Copy (t) after modification: %s\n", copia); // Should be "ZBC" (Changed)

        // The crucial action: Free the allocated memory.
        free(copia);
    }
    return 0;
}