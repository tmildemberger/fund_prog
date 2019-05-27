#include <stdio.h>

#define N 3

void imprime_mat(int mat[N][N], int nl, int nc);

int main() {
    int mat[N][N];
    int i, j;
    int eMagico = 1;
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            scanf("%d", &mat[i][j]);
        }
    }

    int seg = 0;
    for (i = 0; i < N; ++i) seg += mat[i][i];

    int segAtual = 0;
    for (i = 0; i < N; ++i) segAtual += mat[i][N-1-i];

    if (seg != segAtual) eMagico = 0;
    else {
        int somaLinha, somaColuna;
        for (i = 0; i < N; ++i) {
            somaLinha = 0;
            somaColuna = 0;
            for (j = 0; j < N; ++j) {
                somaLinha += mat[i][j];
                somaColuna += mat[j][i];
            }

            if (somaLinha != seg || somaColuna != seg) {
                eMagico = 0;
                break;
            }

        }

    }

    if (eMagico) printf("\ne magico\n");
    else printf("\nnao e quadrado magico!\n");
    return 0;
}

void imprime_mat(int mat[N][N], int nl, int nc) {
    int i, j;
    for (i = 0; i < nl; ++i) {
        for (j = 0; j < nc; ++j) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
