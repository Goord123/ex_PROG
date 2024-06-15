#include <stdio.h>


typedef struct {
    int h, m;
} tempo;

typedef struct Voo voo;
struct Voo {
    char codigo[6];     // código do voo
    char destino[4];    // código do destino
    int emTerra;        // sim = 1; não = 0;
    tempo t;            // hora de partida
};




