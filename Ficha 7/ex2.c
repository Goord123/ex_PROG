#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    char *nome;
    int numero;
} Agenda;

bool addToAgenda(Agenda **agenda, int *tam, char*userNome, int userContacto) {
    for(int i=0; i<*tam; i++) {
        if (strcmp(userNome, (*agenda)[i].nome) == 0) {
            printf("Nome já em utilizacao!\n");
            return false;
        }
    }

    *agenda = realloc(*agenda, sizeof(Agenda) * (*tam + 1));
    (*agenda)[*tam].nome = strdup(userNome);
    (*agenda)[*tam].numero = userContacto;
    (*tam)++;
    return true;
}

void printList(Agenda *agenda, int *tam) {
    for (int i=0; i<*tam; i++) {
        printf("Nome: %s, Contacto: %d\n", agenda[i].nome, agenda[i].numero);
    }
}

int lookForPhoneNumberOfContact(Agenda *agenda, int tam, char *contact) {
    for (int i=0; i<tam; i++) {
        if (strcmp(agenda[i].nome, contact) == 0)
            return agenda[i].numero;
    }
    return -1;
}

int updateContact(Agenda **agenda, int tam, char *contact, int newNr) {
    for (int i=0; i<tam; i++) {
        if (strcmp((*agenda)[i].nome, contact) == 0) {
            (*agenda)[i].numero = newNr;
            printf("Updated %s's number to: %d", (*agenda)[i].nome, newNr);
            return 1;
        }
    }
    return 0;
}

Agenda* deleteContact(Agenda **agenda, int *tam, char *personToDelete) {
    for (int i=0; i<*tam; i++) {
        if (strcmp((*agenda)[i].nome, personToDelete) == 0) {
            free((*agenda)[i].nome);

            for (int j=i; j<(*tam-1); j++) {
                (*agenda)[j] = (*agenda)[j+1];
            }

            (*tam)--;

            Agenda *temp = realloc(*agenda, sizeof(Agenda) * (*tam));
            if (temp == NULL && *tam > 0) {
                printf("Erro de realocação de memória!\n");
                return NULL;
            }

            *agenda = temp;
            return *agenda;

        }
    }
    return NULL;
}


int main() {
    Agenda *agenda = NULL;
    int tamAgenda = 0;

    addToAgenda(&agenda, &tamAgenda, "to", 991);
    addToAgenda(&agenda, &tamAgenda, "maria", 222);
    addToAgenda(&agenda, &tamAgenda, "lena", 342);

    printList(agenda, &tamAgenda);

    int res = lookForPhoneNumberOfContact(agenda, tamAgenda, "maria");
    if (res != -1)
        printf("\nNumero de '%s': %d\n", "maria", res);

    updateContact(&agenda, tamAgenda, "to", 1337);

    Agenda *delRes = deleteContact(&agenda, &tamAgenda, "lena");
    if (delRes != NULL)
        printf("\nUser deleted!\n");




    free(agenda);

}