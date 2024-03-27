#include <stdio.h>
#include <time.h>

typedef struct tempo Tempo;
struct tempo {
    unsigned int hora;
    unsigned int minutos;
};

typedef struct voo Voo;
struct voo {
    Tempo tempo;
};

void print(Voo voo) {
    printf("%d:%d", voo.tempo.hora, voo.tempo.minutos);
}

void addNewVoo(Voo voo, int hora, int minuto) {
    voo.tempo.hora = hora;
    voo.tempo.minutos = minuto;
}

int checkIfVooJaPartiu(Voo voo, Tempo tempo) {
    if (voo.tempo.hora > tempo.hora) return 1;
    if (voo.tempo.hora == tempo.hora && voo.tempo.minutos > tempo.minutos) return 1;
    return 0;
}

void add(Voo voos[300] , int *len, int hora, int minutos) {
    Voo aux;

    if (*len == 0) {
        aux.tempo.hora = hora;
        aux.tempo.minutos = minutos;
        voos[0] = aux;
        (*len)++;
    }
    else {
        aux.tempo.hora = hora;
        aux.tempo.minutos = minutos;
        voos[*len] = aux;
        (*len)++;
    }
}

void checkIfVoosSoon(int *nrVoos, Voo voos[*nrVoos]){
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    int horaAtual = local->tm_hour;
    int minAtual = local->tm_min;
    int cont = 0;

    for (int i=0; i<*nrVoos; i++) {
        if (voos[i].tempo.hora == horaAtual &&
            voos[i].tempo.minutos - minAtual <= 30 )
            cont++;
        if (voos[i].tempo.hora == horaAtual - 1 &&
            minAtual - voos[i].tempo.minutos >= 30)
            cont++;
    }
    printf("\nVoos Soon: %d", cont);
}

void retiraElemento(int *len, Voo voos[*len]) {
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    int horaAtual = local->tm_hour;
    int minAtual = local->tm_min;
    int tam = *len;

    for (int i=0; i<tam; i++) {
        if (horaAtual > voos[i].tempo.hora) {
            for (int j = i; j < tam; j++) {
                voos[j] = voos[j + 1];
            }
            (*len)--;
        }
        else if (horaAtual == voos[i].tempo.hora &&
            minAtual > voos[i].tempo.minutos) {
            for (int j = i; j < tam; j++) {
                voos[j] = voos[j + 1];
            }
            (*len)--;
        }
    }
}

int main() {
    Tempo tempo;
    tempo.hora = 4;
    tempo.minutos = 14;
    Voo voo;
    voo.tempo = tempo;
    print(voo);

    Voo voo2;
    addNewVoo(voo2,2,2);

    printf("check: %d\n", checkIfVooJaPartiu(voo2, tempo));

    Voo bueBoos[300];
    int len = 0;
    add(bueBoos, &len, 0, 22);
    add(bueBoos, &len, 23, 1);
    add(bueBoos, &len, 23, 2);
    add(bueBoos, &len, 3, 3);
    add(bueBoos, &len, 4, 4);
    printf("\nlen: %d\n", len);

    checkIfVoosSoon(&len, bueBoos);

    retiraElemento(&len, bueBoos);
    printf("\nlen: %d\n", len);


}