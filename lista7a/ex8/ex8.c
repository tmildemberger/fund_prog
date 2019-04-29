#include <stdio.h>

#define TAM 26

int main() {
    char letra_lampada[TAM];
    int i;
    for (i = 0; i < TAM; ++i) {
        scanf("%c", &letra_lampada[i]);
    }
    int piscadas;
    scanf("%d", &piscadas);
    for (i = 0; i < piscadas; ++i) {
        int lampada;
        scanf("%d", &lampada);
        printf("%c", letra_lampada[lampada - 1]);
    }
    printf("\n");
    return 0;
}
