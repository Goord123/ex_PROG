#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct local no, *pno;
struct local {
    char nome[50];
    pno prox;
};

pno addNo_1(pno lista, char *st) {
    pno novo;
    novo = malloc(sizeof(no));
    if (novo == NULL) return lista;
    strcpy(novo->nome, st);
    novo->prox = lista;
    return novo;
}

pno addNo_3(pno lista, char *st) {
    pno novo;
    novo = malloc(sizeof(no));
    if (novo == NULL) return lista;
    strcpy(novo->nome, st);
    if (lista == NULL) {
        novo->prox = lista;
        lista = novo;
    } else {
        novo->prox = lista->prox;
        lista->prox = novo;
    }
    return lista;
}

int main() {
    pno lista = NULL;
    lista = addNo_3(lista, "AAA");
    lista = addNo_3(lista, "BBB");
    lista = addNo_3(lista, "CCC");
    lista = addNo_3(lista, "DDD");
    printf("%s", lista->prox->nome);
}