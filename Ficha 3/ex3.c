#include "stdio.h"

void rotacao(float *p1, float *p2, float *p3) {
    float aux = *p1;

    *p1 = *p3;
    *p3 = *p2;
    *p3 = aux;
    printf("1: %f\n", *p1);
    printf("2: %f\n", *p2);
    printf("3: %f\n", *p3);
}


int main() {
    float n1 = 1, n2 = 2, n3 = 3;

    rotacao(&n1, &n2, &n3);
    printf("\nNO MAIN:\n");
    printf("1: %f\n", n1);
    printf("2: %f\n", n2);
    printf("3: %f\n", n3);
}