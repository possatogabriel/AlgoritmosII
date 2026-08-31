#include <stdio.h>

int main() {
    int n1, n2;

    printf("Escreva o número 1: ");
    scanf("%d", &n1);

    printf("\nEscreva o número 2: ");
    scanf("%d", &n2);

    int soma = n1 + n2;
    int sub = n1 - n2;
    int mult = n1 * n2;
    int div = n1 / n2;

    printf("\n> Soma: %d", soma);
    printf("\n> Subtração: %d", sub);
    printf("\n> Multiplicação: %d", mult);
    printf("\n> Divisão: %d", div);

    return 0;
}