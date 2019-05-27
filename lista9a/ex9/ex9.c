#include <stdio.h>

#define N 3

void imprime_mat(int mat[N][N], int nl, int nc);

int main() {
    int mat[N][N];
    int i, j;
    int e_perm = 1;
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            scanf("%d", &mat[i][j]);
        }
    }
    int pivoLinha, pivoColuna;
    for (i = 0; i < N && e_perm; ++i) {
        pivoLinha = 0;
        pivoColuna = 0;
        for (j = 0; j < N; ++j) {
            if (mat[i][j] == 1) {
                ++pivoLinha;
                if (pivoLinha > 1) {
                    e_perm = 0;
                    break;
                }
            }
            else if (mat[i][j] != 0) {
                e_perm = 0;
                break;
            }
            if (mat[j][i] == 1) {
                ++pivoColuna;
                if (pivoColuna > 1) {
                    e_perm = 0;
                    break;
                }
            }
            else if (mat[j][i] != 0) {
                e_perm = 0;
                break;
            }
        }
        if (pivoLinha != 1 || pivoColuna != 1) {
            e_perm = 0;
        }
    }
    if (e_perm) printf("e matriz de permutacao\n");
    else printf("N e matriz de permutacao\n");
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
