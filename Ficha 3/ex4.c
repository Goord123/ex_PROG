#include "stdio.h"

void conta(int *t, int tam, int *np, int *ni, int *maior, int *pos) {
    for (int i = 0; i < tam; i++) {
        if (t[i] % 2 == 0) {
            (*ni)++;
        }
        if (t[i] > *maior) {
            *maior = t[i];
            *pos = i;
        }
    }
    *np = tam - *ni;
}


int main() {
    int arr[10] = {1, 3, 7, 5, 2, 10, 9, 7, 7, 1};
    int maior = 0, ni = 0, pos = 0, np = 0;

    conta(arr, 10, &np, &ni, &maior, &pos);

    printf("Pares: %d\n", np);
    printf("Impares: %d\n", ni);
    printf("Maior: %d\n", maior);
    printf("Posicao: %d\n", pos);
    return 0;
}