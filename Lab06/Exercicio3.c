#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void trocar(char *v[], int i, int j) {
    char *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void insertion_sort(char *v[], int n) {
    for (int i = 1; i < n; i++) {
        char *elemento = v[i];
        int j = i - 1;
        bool encontrou = false;

        while (j >= 0 && !encontrou) {
            if (strcmp(v[j], elemento) > 0) {
                v[j + 1] = v[j];

                j--;
            } else {
                encontrou = true;
            } 
        }

        v[j + 1] = elemento;
    }
}

int main() {
    char *v[] = {"Gabriel", "Possato", "Olivia", "Tomaz", "Guilherme", "Jonas"};
    insertion_sort(v, 6);

    for (int i = 0; i < 6; i++) {
        printf("%s ", v[i]);
    }
    printf("\n");
    return 0;
}