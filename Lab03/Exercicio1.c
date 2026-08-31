#include <stdio.h>

int retorna_idade() {
    int idade;
    
    printf("Insira a sua idade: ");
    scanf("%d", &idade);

    return idade;
}

int retorna_nadador(int idade) {
    if (idade >= 5 && idade <= 7) {
        return 1;
    } else if (idade >= 8 && idade <= 10) {
        return 2;
    } else if (idade >= 11 && idade <= 13) {
        return 3;
    } else if (idade >= 14 && idade <= 17) {
        return 4;
    } else if (idade >= 18) {
        return 5;
    } else {
        return -1;
    }
}

void formata_retorno(int numero) {
    if (numero == 1) { 
        printf("\n> CATEGORIA: Infantil A");
    } else if (numero == 2) {
         printf("\n> CATEGORIA: Infantil B");
    } else if (numero == 3) {
        printf("\n> CATEGORIA: Juvenil A");
    } else if (numero == 4) {
        printf("\n> CATEGORIA: Juvenil B");
    } else if (numero == 5) {
        printf("\n> CATEGORIA: Adulto");
    } else {
        printf("\nInsira uma idade válida.");
    }
}

int main() {
    int idade = retorna_idade();
    int numero = retorna_nadador(idade);
    formata_retorno(numero);

    return 0;
}