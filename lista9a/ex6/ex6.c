#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NC 2
#define NL 10

void imprime_mat(int mat[NL][NC], int nl, int nc);
void preenche_mat(int mat[NL][NC], int nl, int nc);

int main() {
    srand(time(NULL));
    int matriz[NL][NC];
    preenche_mat(matriz, NL, NC);
    imprime_mat(matriz, NL, NC);

    int i, j, n = 0, soma;
    for (i = 0; i < NL; ++i) {
        soma = 0;
        for (j = 0; j < NC; ++j) soma += matriz[i][j];
        if (!soma) n++;
    }

    printf("%d\n", n);

    return 0;
}

void imprime_mat(int mat[NL][NC], int nl, int nc) {
    int i, j;
    for (i = 0; i < nl; ++i) {
        for (j = 0; j < nc; ++j) {
            printf("%2d ", mat[i][j]);
        }
        printf("\n");
    }
}

void preenche_mat(int mat[NL][NC], int nl, int nc) {
    int i, j;
    for (i = 0; i < nl; ++i) {
        for (j = 0; j < nc; ++j) {
            mat[i][j] = rand() % 3 - 1;
        }
    }
}
