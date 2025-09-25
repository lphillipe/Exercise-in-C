#include <stdio.h>

int main(void) {
    int numero;

    printf("Digite um número: ");
    scanf("%d", &numero);


    for(int i = 1; i <= 10; i++) {
        for(int j = 1; j <= 10; j ++) {
            printf("%d x %d = %d\n", i, j, i * j);
        }
        printf("\n");
    }
    return 0;
}
