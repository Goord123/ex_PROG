#include <stdio.h>

struct sala{
    char id[10];
    int total;
};
typedef struct pessoa no, *pno;
struct pessoa{
    char nome[100], num[20]; // Nome e número do aluno
    struct sala* p; // Ptr. para a sala onde o aluno fará o teste
    pno prox;
};

void print(pno lista, struct sala *salas, int tamSalas) {
    int maior=0;
    for (int i=0; i<tamSalas; i++) {
        if (salas[i].total > maior)
            maior = salas[i].total;
    }

    pno aux = lista;
    while (aux != NULL) {
        if (aux->p->total == maior)
            printf("Nome: %s\n", aux->nome);
        aux = aux->prox;
    }
}


int main() {

    struct sala salas[] = {
            {"S1", 3},
            {"S2", 6},
            {"S3", 5}
    };

    no aluno1 = {"Carlos Pinto", "12345", &salas[0], NULL};
    no aluno2 = {"Ana Silva", "54321", &salas[1], NULL};
    no aluno3 = {"Pedro Costa", "67890", &salas[2], NULL};
    no aluno4 = {"Maria Santos", "09876", &salas[1], NULL};
    no aluno5 = {"João Sousa", "13579", &salas[2], NULL};

    aluno1.prox = &aluno2;
    aluno2.prox = &aluno3;
    aluno3.prox = &aluno4;
    aluno4.prox = &aluno5;

    pno lista = &aluno1;

    print(lista, salas, 3);




    return 0;
}