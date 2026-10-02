#include <stdio.h>

void trocar(float v[], int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void selection_sort(float v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[min]) {
                min = j;
            }
        }

        if (min != i) {
            trocar(v, i, min);
        }   
    }
}

int main() {
    float v[] = {5.66, 0.1, 1.5, 3.6, 2.22, 4.66};
    selection_sort(v, 6);

    for (int i = 0; i < 6; i++) {
        printf("%.2f ", v[i]);
    }
    printf("\n");
    return 0;
}