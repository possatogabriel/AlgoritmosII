#include <stdio.h>

float retorna_s(int n) {
    float valor = n;
    float s = 1 + (1.0 / 2.0) + (1.0 / 3.0) + (1.0 / 4.0) + (1.0 / 5.0) + (1.0 / valor);

    return s;
}

int main() {
    int n = 0;

    while (n <= 0) {
        printf("\nDigite um número: ");
        scanf("%d", &n);

        if (n <= 0) {
            printf("\nInsira um valor inteiro e positivo.");
        }
    }

    float s = retorna_s(n);
    printf("\n> S = %.2f", s);

    return 0;
}