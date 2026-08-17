#include <stdio.h>

int main() {
    float base;
    float altura;

    printf("Digite a base do retângulo: ");
    scanf("%f", &base);

    printf("\nDigite a altura do retângulo: ");
    scanf("%f", &altura);

    float area = base * altura;
    printf("\n> Área do retângulo: %.2f", area);

    return 0;
}