#include <stdio.h>

#define N 4
int ocorrem_n(int n, int v[]);

int main() {
    int mat[N][N];
    printf("Digite os elementos de uma matriz %d x %d:\n", N, N);
    int i, j;
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            scanf("%d", &mat[i][j]);
        }
    }

    int latino = 1;
    for (i = 0; i < N; ++i) {
        if (!ocorrem_n(N, mat[i])) {
            latino = 0;
            break;
        }
        int coluna[N];
        for (j = 0; j < N; ++j) {
            coluna[j] = mat[i][j];
        }
        if (!ocorrem_n(N, coluna)) {
            latino = 0;
            break;
        }
    }
    if (latino) printf("a matriz e um quadrado latino\n");
    else printf("nao e um quadrado latino\n");
    return 0;
}

int ocorrem_n(int n, int v[]) {
    //sem alocação dinâmica
    int i = 1, j;
    while (i <= n) {
        int encontrei = 0;
        for (j = 0; j < n; ++j) {
            if (v[j] == i) ++encontrei;
        }
        if (encontrei != 1) return 0;
        ++i;
    }
    return 1;
}
