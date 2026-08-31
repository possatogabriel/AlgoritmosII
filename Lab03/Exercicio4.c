#include <stdio.h>

float retorna_peso(float alt, int sexo) {
    if (sexo == 0) {
        return 62.1 * alt - 44.7;
    } else if (sexo == 1) {
        return 72.7 * alt - 58.0;
    }
}

int main() {
    float alt = 0.0;
    int sexo = -1;

    while (alt <= 0 || (sexo != 0 && sexo != 1)) {
        printf("\nDigite sua altura: ");
        scanf("%f", &alt);

        printf("\nInsira seu sexo ('0' para mulher e '1' para homem): ");
        scanf("%i", &sexo);

        if (alt <= 0 || (sexo != 0 && sexo != 1)) {
            printf("\n> Insira altura e sexo válidos.");
        }
    }

    float peso_ideal = retorna_peso(alt, sexo);
    printf("\n> PESO IDEAL: %.2f", peso_ideal);

    return 0;
}