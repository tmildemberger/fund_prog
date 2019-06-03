#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int numeroVizinhas(int **m, int l, int c, int i, int j);

//-1 : esquerda/cima 1:direita/baixo
int borda(int t, int p);

int** alocaMatriz(int l, int c);

void desalocaMatriz(int **m, int l);

void imprimeMatriz(int **m, int l, int c);

void preencheMatrizBlinker(int **m, int l, int c);

void copiaMatriz(int **fonte, int **dest, int l, int c);

int main() {
    int **matriz, **aux, l, c, i, j, k, iter, vizinhas;

    printf("Quantidade de linhas, colunas: ");
    scanf("%d %d", &l, &c);
    printf("Quantas iteracoes? ");
    scanf("%d", &iter);

    matriz = alocaMatriz(l, c);

    aux = alocaMatriz(l, c);

    preencheMatrizBlinker(matriz, l, c);
    system("clear");
    imprimeMatriz(matriz, l, c);
    sleep(1);

    copiaMatriz(matriz, aux, l, c);

    for(k = 0; k < iter; k++) {

        for(i = 0; i < l; i++) {
            for(j = 0;j < c; j++) {
                vizinhas = numeroVizinhas(matriz, l, c, i, j);

                if(matriz[i][j] == 1) {
                    if(2 > vizinhas || vizinhas > 3) aux[i][j] = 0;
                }
                else if(vizinhas == 3) aux[i][j] = 1;
            }
        }

        copiaMatriz(aux, matriz, l, c);

        system("clear");
        imprimeMatriz(matriz, l, c);
        sleep(1);
    }
}

int numeroVizinhas(int **m, int l, int c, int i, int j){
    int bordaH, bordaV, vizinhas = 0;

    bordaH = borda(c, j);
    bordaV = borda(l, i);

    // if (bordaV != -1) {
    //     if (bordaH != -1) vizinhas += m[i-1][j-1];
    //     if (bordaH != 1) vizinhas += m[i-1][j+1];
    //     vizinhas += m[i-1][j];
    // }
    //
    // if (bordaV != 1) {
    //     if (bordaH != -1) vizinhas += m[i+1][j-1];
    //     if (bordaV != 1) vizinhas += m[i+1][j+1];
    //     vizinhas += m[i+1][j];
    //
    //
    // }
    //
    // if (bordaH != -1) vizinhas += m[i][j-1];
    // if (bordaH != 1) vizinhas += m[i][j+1];

    int k, w;
    for (k = -1; k <= 1; ++k) {
        if (bordaV && k == bordaV) continue;
        else {
            for (w = -1; w <= 1; ++w) {
                if ((bordaH && w == bordaH) || (k == 0 && w == 0)) continue;
                else vizinhas += m[i+k][j+w];
            }
        }
    }

    return vizinhas;
}

int borda(int t, int p) {
    if (p == 0) return -1;
    else if (p == t-1) return 1;
    else return 0;
}


int** alocaMatriz(int l, int c){
    int **m, i;
    m = (int**) malloc(l*sizeof(int*));
    for (i = 0; i < l; ++i) m[i] = (int*) malloc(c*sizeof(int));

    return m;
}

void desalocaMatriz(int **m, int l){
    int i;
    for(i = 0; i < l; ++i) free(m[i]);
    free(m);
}

void imprimeMatriz(int **m, int l, int c){

    int i, j;

    for (i = 0; i < l; ++i) {
        for (j = 0; j < c; ++j) {
            printf("%c", (m[i][j] ? '#' : ' ') );
        }
        printf("\n");
    }
}

void preencheMatrizBlinker(int **m, int l, int c) {

    int i, j;

    for (i = 0; i < l; ++i) {
        for (j = 0; j < c; ++j) {
            m[i][j] = 0;
        }
    }

    i = l/2;
    j = c/2;

    m[i - 1][j] = 1;
    m[i][j] = 1;
    m[i + 1][j] = 1;

}

void copiaMatriz(int **fonte, int **dest, int l, int c){
    int i, j;

    for (i = 0; i < l; ++i) {
        for (j = 0; j < c; ++j) {
            dest[i][j] = fonte[i][j];
        }
    }
}
