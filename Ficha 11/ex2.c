#include <stdio.h>
#include <malloc.h>

void sumValuesInBinFile(const char *fileName) {
    FILE *file;

    file = fopen(fileName, "rb");
    if (file == NULL)
        return;

    int num1;
    int num2;
    fread(&num1, sizeof(int), 1, file);
    fread(&num2, sizeof(int), 1, file);

    printf("Sum: %d\n", num1 + num2);

    fclose(file);
}

int* criaVetor(char *nomeFich, int *tam) {
    FILE *f;
    int *vetor = NULL;
    f = fopen(nomeFich, "rb");
    if (f == NULL)
        return NULL;
    int aux;
    int i=0;
    while (fread(&aux, sizeof(int), 1, f) != 0) {
        if (aux % 2 == 0) {
            (*tam)++;
            vetor = realloc(vetor, sizeof(int) * (*tam));
            if (vetor == NULL) {
                perror("Error allocating memory");
                free(vetor);
                fclose(f);
                *tam = 0;
                return NULL;
            }
            vetor[i++] = aux;
        }
    }
    if (vetor != NULL) {
        printf("Numbers inside array: ");
        for (int j=0; j<i; j++) {
            printf("%d", vetor[j]);
        }
    }
    return vetor;
}

void func_C(const char*fileName1, const char*fileName2, const char*fileName3) {
    FILE *file1;
    FILE *file2;
    FILE *file3;
    int *vector = NULL;
    int aux;
    int i=0;
    file1 = fopen(fileName1, "rb");
    while (fread(&aux, sizeof(int), 1, file1) == 1) {
        vector = realloc(vector, sizeof(int) * i + 1);
        vector[i++] = aux;
    }
    if (vector == NULL) return;
    file2 = fopen(fileName2, "wb");
    file3 = fopen(fileName3, "wb");

    for (int j=0; j<i; j++) {
        if (vector[j] <= 3) {
            fwrite(&vector[j], sizeof(int), 1, file2);
        }
        else {
            fwrite(&vector[j], sizeof(int), 1, file3);
        }
    }

    fclose(file1);
    fclose(file2);
    fclose(file3);
    free(vector);

}

int main() {
    FILE *file;
    int num1 = 1;
    int num2 = 2;
    int num3 = 4;
    file = fopen("data.bin", "wb");
    if (file == NULL)
        return 0;
    fwrite(&num1, sizeof(int), 1 , file);
    fwrite(&num2, sizeof(int), 1 , file);
    fwrite(&num3, sizeof(int), 1 , file);
    fclose(file);

    //sumValuesInBinFile("data.bin");
    int ptr = 0;
    criaVetor("data.bin", &ptr);
    func_C("data.bin", "menor.bin", "maior.bin");


    return 0;
}