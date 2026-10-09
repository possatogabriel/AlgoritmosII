#include <stdio.h>
#include <stdbool.h>

void trocar(int v[], int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int bubble_sort_sentinela(int v[], int n) {
    int i, contador;
    int passagens = 0;

    for (contador = 1; contador <= n - 1; contador++) {
        bool sentinela = false;
        passagens++;

        for (i = 0; i < n - 1; i++) {
            if (v[i] > v[i + 1]) {
                trocar(v, i, i + 1);
                sentinela = true;
            }
        }
        if (!sentinela) {
            return passagens;
        }
    }
    return passagens;
}

void imprimir(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int a[] = {1, 2, 3, 5, 4};
    int b[] = {5, 4, 3, 2, 1};

    int pa = bubble_sort_sentinela(a, 5);
    printf("a) Ordenado: ");
    imprimir(a, 5);
    printf("Passagens: %d\n\n", pa);

    int pb = bubble_sort_sentinela(b, 5);
    printf("b) Ordenado: ");
    imprimir(b, 5);
    printf("Passagens: %d\n", pb);

    return 0;
}