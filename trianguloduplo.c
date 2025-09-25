#include <stdio.h>

int main(void) {
    int altura;
    printf("Digite a altura: ");
    scanf("%d", &altura);

    for(int i = 1; i <= altura; i++) {
        for(int j = 0; j < altura - i; j++) {
            printf(" ");
        }
        for(int k = 0; k < i; k++) {
            printf("#");
        }
        printf("  ");

        for(int k = 0; k < i; k++) {
            printf("#");
        }
        printf("\n");
    }
}
