#include <stdio.h>
#include <string.h>

void func(char *str1, char *str2) {
    char aux[100] = {"\0"};

    if (strcmp(str1, str2) == 0) {
        printf("Contudo igual!\n");
    }
    else if (strlen(str1) == strlen(str2))  {
        printf("Tamanho igual|");
    }
    else {
        strcat(aux, str1);
        strcat(aux, str2);
        int i=0;
        while (aux[i] != '\0') {
            printf("%c", aux[i]);
            i++;
        }
    }

}




int main(){
    char str1[16] = "Hoje e Domingo!";
    char str2[16] = "Hoje e Domingo!";
    char str3[20] = "Hoje nao e Domingo!";

    func(str1, str2);

    return 0;
}