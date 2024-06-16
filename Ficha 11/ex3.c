#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define TAM 4
struct paragem{
    char nome[50];
    int minutos; // tempo que demora em media desde a paragem anterior
};

void printStruct(struct paragem *paragens, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("Paragem %d: %s\n", i+1, paragens[i].nome);
        printf("Tempo: %d\n", paragens[i].minutos);
    }
}

void readStructFromBin(struct paragem *paragens, int tam) {
    FILE *file = fopen("paragens.bin", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o ficheiro\n");
        return;
    }

    fread(paragens, sizeof(struct paragem), tam, file);
    fclose(file);
}

int paragemExiste(const char *nomeFich, const char *nomeParagem) {
    FILE *file = fopen(nomeFich, "rb");
    if (file == NULL) {
        perror("Erro ao abrir o ficheiro");
        return 0;
    }

    struct paragem p;
    while (fread(&p, sizeof(struct paragem), 1, file) == 1) {
        if (strcmp(p.nome, nomeParagem) == 0) {
            fclose(file);
            return 1; // Paragem encontrada
        }
    }

    fclose(file);
    return 0; // Paragem não encontrada
}

int main() {
    struct paragem paragens[TAM];

    readStructFromBin(paragens, TAM);
    printStruct(paragens, TAM);

    const char *nomeFich = "paragens.bin";
    const char *nomeParagem = "Porto";

    if (paragemExiste(nomeFich, nomeParagem)) {
        printf("A paragem %s existe no trajeto.\n", nomeParagem);
    } else {
        printf("A paragem %s não existe no trajeto.\n", nomeParagem);
    }

    return 0;
}