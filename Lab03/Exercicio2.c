#include <stdio.h>
#include <stdbool.h>

bool verifica_valor(int valor) {
    if (valor % 2 == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int valor;

    printf("Digite um número: ");
    scanf("%d", &valor);

    bool resultado = verifica_valor(valor);

    if (resultado) {
        printf("\n> Você digitou um NÚMERO PAR!");
    } else {
        printf("\n> Você digitou um NÚMERO ÍMPAR");
    }

    return 0;
}