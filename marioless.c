#include <stdio.h>
int main(void) {
    int altura;
    printf("Digite a altura da pirâmide ?");
    scanf("%d", &altura);

    for( int i = 1; i <= altura; i++) {
        for(int s = 1; s <= altura - i; s++) {
            printf(" ");
        }
        for(int k = 1; k <= i; k++) {
            printf("#");
        }
        printf("\n");
    }
}