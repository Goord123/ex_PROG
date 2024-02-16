#include "stdio.h"

void func( int tam, int arr[tam][3]) {
    printf("Introduza 3 numeros: \n(Exemplo: 1 2 3)\n");
    scanf("%d %d %d", &arr[0][0], &arr[1][0], &arr[2][0]);
    for (int i=0; i<tam; i++) {
        for (int j=1; j<3; j++) {
            if (j == 1) {
                arr[i][j] = arr[i][0] * arr[i][0];
            }
            if (j == 2) {
                arr[i][j] = arr[i][0] * arr[i][0] * arr[i][0];
        }
        printf("\n");
        }
    }
    for (int i=0; i<tam; i++) {
        for (int j=0; j<3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}


int main() {

        int arr[3][3] ={};
        func(3, arr);


}