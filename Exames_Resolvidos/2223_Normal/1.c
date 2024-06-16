#include <stdio.h>
#include <time.h>
#include <string.h>
#include <malloc.h>


typedef struct {
    int h, m;
} tempo;

typedef struct Voo Voo;
struct Voo {
    char codigo[6];     // código do voo
    char destino[4];    // código do destino
    int emTerra;        // sim = 1; não = 0;
    tempo t;            // hora de partida
};


void writeBinFile(const char *string, struct Voo pVoo[7], int i) {
    FILE *file;
    file = fopen(string, "wb");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    fwrite(pVoo, sizeof(struct Voo), i, file);
    fclose(file);
}

void readBinFile(const char *string, struct Voo pVoo[7], int i) {
    FILE *file;
    file = fopen(string, "rb");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    fread(pVoo, sizeof(struct Voo), i, file);
    for (int j = 0; j < i; j++) {
        printf("Voo %d\n", j + 1);
        printf("Código: %s\n", pVoo[j].codigo);
        printf("Destino: %s\n", pVoo[j].destino);
        printf("Em terra: %d\n", pVoo[j].emTerra);
        printf("Hora de partida: %d:%d\n", pVoo[j].t.h, pVoo[j].t.m);
    }
    fclose(file);
}

void updateBinFile(const char *fileName) {
    FILE *file;
    file = fopen(fileName, "rb");
    if (file == NULL) return;

    // Get the current time
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);
    int current_hour = current_time->tm_hour;
    int current_minute = current_time->tm_min;

    Voo voo;
    while (fread(&voo, sizeof(Voo), 1, file) == 1) {
        // Check if the flight's departure time has passed
        if (voo.emTerra == 1 && (voo.t.h < current_hour ||
        (voo.t.h == current_hour && voo.t.m <= current_minute))) {
            // Update the emTerra field
            voo.emTerra = 0;
            fseek(file,-sizeof(Voo), SEEK_CUR);
            fwrite(&voo, sizeof(Voo), 1, file);
        }
    }

    fclose(file);
}

Voo* listFlightsFromDest(Voo *voos, int tam, const char *dest, int *indexOfNewLista) {
    Voo *lista = NULL;
    *indexOfNewLista = 0;

    for (int i=0; i<tam; i++) {
        if (strcmp(voos[i].destino, "LIS") == 0) {
            lista = realloc(lista, sizeof(Voo) * (*indexOfNewLista+1));
            if (lista == NULL){
                free(lista);
                return NULL;
            }
            lista[*indexOfNewLista] = voos[i];
            (*indexOfNewLista)++;
        }
    }
    return lista;
}

int main() {
    Voo voos[7] = {
        {"TP123", "LIS", 1, {23, 30}},
        {"TP124", "OPO", 0, {13, 30}},
        {"TP125", "FAO", 0, {14, 30}},
        {"TP126", "LIS", 1, {15, 30}},
        {"TP127", "OPO", 0, {16, 30}},
        {"TP128", "FAO", 0, {17, 30}},
        {"TP129", "LIS", 1, {18, 30}}
    };

    writeBinFile("data.bin", voos, 7);
    //readBinFile("data.bin", voos, 7);
    //updateBinFile("data.bin");
    //readBinFile("data.bin", voos, 7);

    int tamLista = 0;
    Voo *lista = listFlightsFromDest(voos, 7,"LIS", &tamLista);
    for (int i=0; i<tamLista; i++) {
        printf("Voo %d\n", i+1);
        printf("Código: %s\n", lista[i].codigo);
        printf("Destino: %s\n", lista[i].destino);
        printf("Em terra: %d\n", lista[i].emTerra);
        printf("Hora de partida: %d:%d\n", lista[i].t.h, lista[i].t.m);
    }
    free(lista);

}







