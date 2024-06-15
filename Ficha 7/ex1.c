#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void preenche(int *a, int tam){ // ultimo loop: a + tam = 8 + 5 = 13; (13, 5)
    printf("\n%d, %d", *a, tam);
    for(int i=0; i<tam; i++)
        a[i] = 5*i;
}
int* f1(int *a, int *tam){
    int *p, i;
    p = realloc(a, sizeof(int)*(*tam + a[1])); // realocar um novo tamanho de memoria para a data
    if(p == NULL)                   // 3 + 5 = 8 de espaço realocado
        return a;
    a = p;
    preenche(a + *tam, a[1]);
    *tam += a[1];
    return a;
}
int main(){
    int *v = NULL, total = 0;
    v = malloc(sizeof(int) * 3); // alocar 3ints the espaço
    if(v == NULL)
        return 0;
    total = 3;
    preenche(v, total); // 5 10 15
    v = f1(v, &total);
    free(v);
    return 0;
}