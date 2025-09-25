#include <stdio.h>

int main(void) {
    int altura;

    printf("Digite a altura do triângulo");
    scanf("%d", &altura);

    for(int i = 1; i <= altura; i++) {
        for(int j = 1; j <= altura - i; j++) {
            printf(" ");
        }
        for(int k = 1; k <= i; k ++) {
            printf("*");
        }
        printf("\n");
    }
}
