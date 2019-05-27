#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 12


void imprime_mat(int mat[N][N], int nl, int nc);

int main() {
    int matriz[N][N] = {0};
    printf("\n");

    matriz[0][0] = 1;

    int i, j;
    for(i = 1; i < N; ++i) {
        matriz[i][0] = 1;
        for(j = 1; j < N; ++j) {
            matriz[i][j] = matriz[i-1][j-1] + matriz[i-1][j];
        }
    }

    imprime_mat(matriz, N, N);
    return 0;
}

void imprime_mat(int mat[N][N], int nl, int nc) {
    int i, j;
    for (i = 0; i < nl; ++i) {
        for (j = 0; j < nc; ++j) {
            if (mat[i][j]) printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
