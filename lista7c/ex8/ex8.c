#include <stdio.h>

#define TAM 8

void consecutivos(int v[], int tam, int *i, int *m);

int main() {
    int v[TAM] = { 3, 3, 9, 6, 3, 9, 6, 9 };
    int i, m;
    consecutivos(v, TAM, &i, &m);
    printf("i == %d\nm == %d\n", i, m);
    return 0;
}

void consecutivos(int v[], int tam, int *i, int *m) {
    int k;
    for (k = 1; k <= tam / 2; ++k) {
        int j;
        // for (*i = 0; *i < tam - *m; ++(*i)) {
        for (j = 0; j < tam - k; ++j) {
            int consec = 1;
            int l;
            for (l = 0; l < k; ++l) {
                if (v[j+l] != v[j+k+l]) {
                    consec = 0;
                    break;
                }
            }
            if (consec) {
                *i = j + 1; //  porque no exercício o índice começa no 1
                *m = k;
            }
        }
    }
}
/**
 *  [2, 3, 5, 6, 3, 6, 3, 9]
 *  6,6
*/