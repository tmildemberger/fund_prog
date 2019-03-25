#include <stdio.h>

int main() {
    int penultimo = 0, ultimo = 1;
    int numero;
    scanf("%d", &numero);
    if (numero > 0) {
        printf("%d\n", penultimo);
    }
    if (numero > 1) {
        printf("%d\n", ultimo);
    }
    while (numero-- > 2) {
        int proximo = penultimo + ultimo;
        penultimo = ultimo;
        ultimo = proximo;
        printf("%d\n", proximo);
    }
    return 0;
}
