#include <stdio.h>
#include <stdlib.h>

int main() {
    char caractere;
    int n, i, j;
    scanf("%c %d", &caractere, &n);
    for (i = 0; i <= 2 * n; ++i) {
        for (j = 0; j < abs(n - i); ++j) {
            printf(" ");
        }
        for (j = 0; j < (1 + 2 * (n - abs(n - i))); ++j) {
            printf("%c", caractere);
        }
        printf("\n");
    }


    return 0;
}

//n -> numero i ->linha
//abs(n-i) espaços 1 + 2*i caracteres
