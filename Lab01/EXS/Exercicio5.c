#include <stdio.h>

int main() {
    float salarioMinimo;
    float valorDolar;
    float valorCasa;
    float qntCasas;

    printf("Escreva o valor do salário mínimo: ");
    scanf("%f", &salarioMinimo);

    printf("\nEscreva o valor do dólar: ");
    scanf("%f", &valorDolar);

    valorCasa = (salarioMinimo * 150) / valorDolar;
    qntCasas = 10000000 / valorCasa;

    printf("\n> Total de casas possíveis de construir: %.0f", qntCasas);

    return 0;
}