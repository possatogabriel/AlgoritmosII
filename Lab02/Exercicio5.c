#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gerarNumero() {
    srand(time(NULL));

    int numeroGerado = 1 + rand() % 100;
    return numeroGerado;
}

void rodaJogo(int numeroGerado) {
    int palpite = 0;
    
    while (palpite < 1 || palpite > 100) {
        printf("\nDê o seu palpite (entre 1 a 100): ");
        scanf("%d", &palpite);

        if (palpite < 1 || palpite > 100) {
            printf("> Insira um número válido.\n");
        }
    }  

    if (palpite < numeroGerado) {
        printf("> Você inseriu um número MENOR! O valor era: %d", numeroGerado);
    } else if (palpite > numeroGerado) {
        printf("> Você inseriu um número MAIOR! O valor era: %d", numeroGerado);
    } else {
        printf("> PARABÉNS! Você acertou!\n");
    }
}

int main() {
    int numeroGerado = gerarNumero();
    rodaJogo(numeroGerado);

    return 0;
}