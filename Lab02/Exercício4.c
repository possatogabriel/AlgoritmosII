#include <stdio.h>

int triangulo(int a, int b, int c) {
    if (a < b + c && b < a + c && c < a + b) {
        return 1;
    } else {
        return 0;
    }
}

void resultado(valor) {
    if (valor == 1) {
        printf("\n> Existe um triângulo com esses lados.");
    } else if (valor == 0) {
        printf("\n> Não existe um triângulo com esses lados.");
    }
}

int main() {
    int a, b, c;

    printf("Escreva o tamanho do lado A: ");
    scanf("%d", &a);

    printf("Escreva o tamanho do lado B: ");
    scanf("%d", &b);

    printf("Escreva o tamanho do lado C: ");
    scanf("%d", &c);

    int valor = triangulo(a, b, c);
    resultado(valor);    

    return 0;
}