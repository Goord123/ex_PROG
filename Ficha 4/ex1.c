#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMatrix(int matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void mediaColunas(int matrix[3][3]) {
    double media = 0;

    for (int i=0; i<3; i++) {
        media+=matrix[i][0];
    }
    printf("media: %0.2f\n", media/3);
}

void transpostaMatrix(int n, int matrix[][n]){
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int temp = matrix[j][i];
            matrix[j][i] = matrix[i][j];
            matrix[i][j] = temp;
        }
    }
}

// create a function that check if there are no repeated numbers in the matrix
int checkRepeated(int n, int matrix[][n]){

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {

            for (int a = 0; a < n; a++) {
                for (int b = 0; b < n; b++) {

                    if (matrix[i][j] == matrix[a][b] && (i != a || j != b)) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

int main() {

    // build a dummy 3x3 matrix
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    printMatrix(matrix);
    mediaColunas(matrix);
    transpostaMatrix(3,matrix);
    printMatrix(matrix);
    printf("Repeated numbers: %d\n", checkRepeated(3, matrix));
}
