#include <stdio.h>

int main() {
    float n1;
    float n2;
    float n3;
    
    printf("Digite a nota 1: ");
    scanf("%f", &n1);

    printf("Digite a nota 2: ");
    scanf("%f", &n2);

    printf("Digite a nota 3: ");
    scanf("%f", &n3);

    float media = (n1 + n2 + n3) / 3;
    printf("\n> Média: %.2f", media);

    return 0;
}