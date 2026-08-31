#include <stdio.h>

int main() {
    float peso, altura;

    printf("Escreva o seu peso: ");
    scanf("%f", &peso);

    printf("\nEscreva a sua altura: ");
    scanf("%f", &altura);

    float imc = peso / (altura * altura);

    printf("\n> O IMC de uma pessoa com peso %f e altura %f é igual a %.2f", peso, altura, imc);

    return 0;
}