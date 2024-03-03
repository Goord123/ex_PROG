#include <stdio.h>
#include <string.h>

void printInv(char *str) {
    int tam = strlen(str);
    char temp[20] = {"\0"};

    for (int i=0; i<tam; i++) {
        temp[i] = str[tam-1-i];
    }

    for(int i=0; i<tam; i++) {
        printf("%c", temp[i]);
    }
}

void printComEspacos(char *str) {
    int tam = strlen(str);
    char temp[20] = {"\0"};

    for (int i=0; i<tam; i++) {
        if (str[tam-1-i] == ' ') {
            str[tam-1-i] = '\n';
        }
        temp[i] = str[tam-1-i];
    }

    for(int i=0; i<tam; i++) {
        printf("%c", temp[i]);
    }
}


int main(){
    char str[15] = "Hoje e Domingo!";

    printInv(str);
    printf("\n");
    printComEspacos(str);

    return 0;
}