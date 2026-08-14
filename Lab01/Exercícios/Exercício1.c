#include <stdio.h>

int main() {
	float salarioMinimo;
    float salarioBruto;

    printf("Escreva o salário mínimo: ");
    scanf("%f", &salarioMinimo);

    printf("Escreva o seu salário bruto: ");
    scanf("%f", &salarioBruto);

    float resultado = salarioBruto / salarioMinimo;
    printf("\n> SALÁRIOS MÍNIMOS QUE VOCÊ RECEBE: %.2f\n", resultado);

    return 0;
}