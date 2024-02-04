#include "stdio.h"


int mostraTab(int a[], int tam){
    int maior=0;
    for(int i=0; i<tam; i++) {
        if (a[i] > maior)
            maior = a[i];
    }
    return maior;
}


int main() {

    int arr[5] = {1,2,3,4,5};
    int len = sizeof(arr)/sizeof(arr[0]);
    printf("Res: %d", mostraTab(arr, len));
}