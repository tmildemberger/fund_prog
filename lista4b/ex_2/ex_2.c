#include <stdio.h>

int main() {
    int numeros;
    scanf("%d", &numeros);
    int i, crescente = 1;
    int anterior, atual;
    scanf("%d", &anterior);
    for (i = 1; i < numeros; ++i) {
        scanf("%d", &atual);
        if (anterior >= atual) {
            crescente = 0;
        }
        anterior = atual;
    }
    if (crescente) printf("sim\n");
    else printf("nao\n");
    return 0;
}
