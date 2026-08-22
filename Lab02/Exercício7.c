#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gerarNumero() {
    srand(time(NULL));

    int numeroGerado = 1 + rand() % 100;
    return numeroGerado;
}

int rodaJogo(int numeroGerado) {
    int palpite = 0;
    
    while (palpite < 1 || palpite > 100) {
        printf("\nDê o seu palpite (entre 1 a 100): ");
        scanf("%d", &palpite);

        if (palpite < 1 || palpite > 100) {
            printf("> Insira um número válido.\n");
        }
    }  

    if (palpite < numeroGerado) {
        printf("> É MENOR!\n");
        return 1;
    } else if (palpite > numeroGerado) {
        printf("> É MAIOR!\n");
        return 1;
    } else {
        printf("> PARABÉNS! Você acertou!\n");
        return 0;
    }
}

int main() {
    int numeroGerado = gerarNumero();
    int contagem = 0;
    int i = 1;

    while (i == 1) {
        int resultado = rodaJogo(numeroGerado);
        i = resultado;

        contagem++;

        if (contagem == 5) {
            printf("\nVocê atingiu o número máximo de tentativas. Tente novamente.");
            break;
        }
    }

    return 0;
}