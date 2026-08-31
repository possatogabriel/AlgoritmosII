#include <stdio.h>

int main() {
    int numero;

    printf("Digite um número: ");
    scanf("%d", &numero);

    if (numero % 5 == 0) {
        printf("\n> O número é um múltiplo de 5!");
    } else {
        printf("\n> O número NÃO é um múltiplo de 5!");
    }

    return 0;
}