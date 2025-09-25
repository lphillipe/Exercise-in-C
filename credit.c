#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(void) {
    
    long long int numero;
    printf("Digite o número do cartão: ");
    scanf("%lld", &numero);
    
    long long int copia = numero;
    int digitos = 0;
    while(copia > 0) {
        copia /= 10;
        digitos++;
    }
    printf("Número de dígitos: %d\n", digitos);

    long long int divisor = 1;
    for (int i = 0; i < digitos - 2; i++) {
        divisor *= 10;
    }
    long long int doisPrimeiros = numero / divisor;
    long long int primeiro = doisPrimeiros / 10;
    printf("Dois primeiros: %lld, Primeiro %lld\n", doisPrimeiros, primeiro);
    
    long long int temp = numero;
    int soma = 0;
    bool multiplicar = false;
    
    printf("\nProcessamento Luhn:\n");
    while(temp > 0) {
        int digito = temp % 10;
        temp /= 10;
        
        int resultado;
        if(multiplicar) {
            resultado = digito * 2;
            if(resultado >= 10) {
                resultado = (resultado / 10) + (resultado % 10);
            }
            printf("Dígito %d multiplicado por 2 = %d, soma parcial = %d\n", digito, resultado, soma + resultado);
        } else {
            resultado = digito;
            printf("Dígito %d sem multiplicação, soma parcial = %d\n", digito, soma + resultado);
        }
        soma += resultado;
        multiplicar = !multiplicar;
    }

    printf("\nSoma Final: %d\n", soma);

    if (soma % 10 == 0) {
        if(digitos == 15 && (doisPrimeiros == 34 || doisPrimeiros == 37)) {
            printf("AMEX\n");
        } else if(digitos == 16 && (doisPrimeiros >= 51 && doisPrimeiros <= 55)) {
            printf("MASTERCARD\n");
        } else if((digitos == 13 || digitos == 16) && primeiro == 4) {
            printf("VISA\n");
        } else {
            printf("INVALID\n");
        }
    } else {
        printf("INVALID\n");
    }
    
    return 0;
}