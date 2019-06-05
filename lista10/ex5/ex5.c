#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** alocaMatriz(int l, int c);
void desalocaMatriz(int **m, int l);
void imprimeMatriz(int **mat, int nl, int nc);
int* alocaVetor(int tam);

int custo_cidades(int *cidades, int n_cidades, int **m);

int main() {
    int n;
    scanf("%d", &n);
    int **mat = alocaMatriz(n, n);
    int i, j;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            scanf("%d", &mat[i][j]);
        }
    }
    int n_viagens;
    scanf("%d", &n_viagens);
    int *viagens = alocaVetor(n_viagens);
    for (i = 0; i < n_viagens; ++i) {
        scanf("%d", &viagens[i]);
    }
    printf("o custo da viagem total e %d\n", custo_cidades(viagens, n_viagens, mat));
    desalocaMatriz(mat, n);
    free(viagens);
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
    m = (int**) malloc(l * sizeof(int*));
    for (i = 0; i < l; ++i) m[i] = (int*) malloc(c * sizeof(int));

    return m;
}

void desalocaMatriz(int **m, int l){
    int i;
    for(i = 0; i < l; ++i) free(m[i]);
    free(m);
}

int custo_cidades(int *cidades, int n_cidades, int **m) {
    int i, custo = 0;
    for (i = 0; i < n_cidades - 1; ++i) {
        custo += m[cidades[i]][cidades[i + 1]];
    }
    return custo;
}

int* alocaVetor(int tam) {
    return malloc(sizeof (int) * tam);
}
