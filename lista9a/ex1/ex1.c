#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NC 2
#define NL 2

void imprime_mat(int mat[NL][NC], int nl, int nc);
void preenche_mat(int mat[NL][NC], int nl, int nc);

int main() {
    srand(time(NULL));
    int mat[NL][NC];
    preenche_mat(mat, NL, NC);
    imprime_mat(mat, NL, NC);
    printf("\n");
    int i, j;
    for (i = 0; i < NL; ++i) {
        for (j = 0; j < NC; ++j) {
            printf("%d ", mat[j][i]);
        }
        printf("\n");
    }
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
