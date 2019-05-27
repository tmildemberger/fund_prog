#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NC 5
#define NL 5

void imprime_mat(int mat[NL][NC], int nl, int nc);
void preenche_mat(int mat[NL][NC], int nl, int nc);

void operacao(int mat[NL][NC], int nl, int nc);

int main() {
    srand(time(NULL));
    int matriz[NL][NC];
    preenche_mat(matriz, NL, NC);
    imprime_mat(matriz, NL, NC);
    printf("\n");

    operacao(matriz, NL, NC);
    imprime_mat(matriz, NL, NC);
    return 0;
}

void imprime_mat(int mat[NL][NC], int nl, int nc) {
    int i, j;
    for (i = 0; i < nl; ++i) {
        for (j = 0; j < nc; ++j) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void preenche_mat(int mat[NL][NC], int nl, int nc) {
    int i, j;
    for (i = 0; i < nl; ++i) {
        for (j = 0; j < nc; ++j) {
            mat[i][j] = rand() % 15 - 7;
        }
    }
}

void operacao(int mat[NL][NC], int nl, int nc) {
    int i, j, maior, j_maior;
    for (i = 0; i < nl; ++i) {
        maior = mat[i][0];
        j_maior = 0;
        for (j = 1; j < nc; ++j) {
            if (mat[i][j] > maior) {
                maior = mat[i][j];
                j_maior = j;
            }
        }
        mat[i][j_maior] = mat[i][i];
        mat[i][i] = maior;
    }
}
