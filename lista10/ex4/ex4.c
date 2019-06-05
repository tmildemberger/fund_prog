#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int** alocaMatriz(int l, int c);

void desalocaMatriz(int **m, int l);

void imprimeMatriz(int **mat, int nl, int nc);

int main() {

    int n;
    scanf("%d", &n);

    int **matriz = alocaMatriz(n, n);


    matriz[0][0] = 1;

    int i, j;
    for(i = 1; i < n; ++i) {
        matriz[i][0] = 1;
        for(j = 1; j < n; ++j) {
            matriz[i][j] = matriz[i-1][j-1] + matriz[i-1][j];
        }
    }

    imprimeMatriz(matriz, n, n);

    desalocaMatriz(matriz, n);
    return 0;
}

void imprimeMatriz(int **mat, int nl, int nc) {
    int i, j;
    for (i = 0; i < nl; ++i) {
        for (j = 0; j < nc; ++j) {
            if (mat[i][j]) printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int** alocaMatriz(int l, int c){
    int **m, i;
    m = (int**) malloc(l*sizeof(int*));
    for (i = 0; i < l; ++i) m[i] = (int*) calloc(c, sizeof(int));

    return m;
}

void desalocaMatriz(int **m, int l){
    int i;
    for(i = 0; i < l; ++i) free(m[i]);
    free(m);
}
