#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NC 5
#define NL 5

void imprime_mat(int mat[NL][NC], int nl, int nc);
void preenche_mat(int mat[NL][NC], int nl, int nc);

void operacao(int mat[NL][NC], int nl, int nc, int m, int n);

int main() {
    srand(time(NULL));
    int matriz[NL][NC];
    preenche_mat(matriz, NL, NC);
    imprime_mat(matriz, NL, NC);
    int m, n;
    scanf("%d %d", &m, &n);
    printf("\n");

    operacao(matriz, NL, NC, m, n);
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

void operacao(int mat[NL][NC], int nl, int nc, int m, int n) {
    int j;
    (void) nl;
    for (j = 0; j < nc; ++j) {
        int temp = mat[m][j];
        mat[m][j] = mat[n][j];
        mat[n][j] = temp;
    }
}
