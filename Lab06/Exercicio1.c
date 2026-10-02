#include <stdio.h>

void trocar(int v[], int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void bubble_sort(int v[], int n){
    for (int contador = 1; contador <= n - 1; contador++) {
        for (int i = 0; i < n - 1; i++) {
            if (v[i] > v[i + 1]) {
                trocar(v, i, i + 1);
            }
        }
    }
}

int main() {
    int v[] = {5, 0, -1, 3, 2, 4};
    bubble_sort(v, 6);

    for (int i = 0; i < 6; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}
