#include <stdio.h>

int main() {
    int horas;

    printf("Informe as horas atualmente: ");
    scanf("%d", &horas);

    int minutos = horas * 60;
    printf("\n> Passaram-se %d minutos desde 00:00!", minutos);

    return 0;
}