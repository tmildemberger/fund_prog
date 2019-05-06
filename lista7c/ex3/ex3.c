#include <stdio.h>

#define TAM 10

int tiraDuplicados(int *v, int tam);
int main() {
    int v[10] = {1,2,3,4,4,6,5,5,9,10}, i;
    int remanescentes = tiraDuplicados(v,TAM);
    for (i = 0; i < remanescentes; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int tiraDuplicados(int *v, int tam) {
    int nRestante = tam, i, j, k;
    for (i = tam-1; i > 0; i--) {

        for(j = i - 1; j > 0; j--) {
            if (v[i] == v[j]) {

                nRestante--;
                for (k = i; k < nRestante; k ++) {
                    v[k] = v[k+1];
                }
            }
        }
    }
    return nRestante;
}
