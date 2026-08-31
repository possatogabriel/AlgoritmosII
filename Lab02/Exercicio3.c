#include <stdio.h>

void resultado(float media, float frequencia) {
    if (frequencia < 75) {
        printf("\n> Você foi REPROVADO.");
    } else if (frequencia >= 75 && media >= 7.5) {
        printf("\n> Você foi APROVADO.");
    } else {
        printf("\n> Você está DE EXAME.");
    } 
}

int main() {
    float media, frequencia;

    printf("Escreva a sua média: ");
    scanf("%f", &media);

    printf("\nEscreva a sua frequência: ");
    scanf("%f", &frequencia);

    resultado(media, frequencia);
    
    return 0;
}