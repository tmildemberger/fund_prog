#include <stdio.h>

#define NC 3
#define NL 3

void imprime_mat(int mat[NL][NC], int nl, int nc);

int main() {
    int mat[NL][NC];
    int i, j;
    for (i = 0; i < NL; ++i) {
        for (j = 0; j < NC; ++j) {
            scanf("%d", &mat[i][j]);
        }
    }
    imprime_mat(mat, NL, NC);
    int maior = mat[0][0], l_maior = 0;
    for (i = 0; i < NL; ++i) {
        for (j = 0; j < NC; ++j) {
            if (mat[i][j] > maior) {
                maior = mat[i][j];
                l_maior = i;
            }
        }
    }
    int minimax = mat[l_maior][0], c_minimax = 0;
    for (j = 0; j < NC; ++j) {
        if (mat[l_maior][j] < minimax) {
            minimax = mat[l_maior][j];
            c_minimax = j;
        }
    }
    printf("mat[%d][%d] = %d (minimax)\n", l_maior, c_minimax, minimax);
    printf("maior = %d\n", maior);

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
