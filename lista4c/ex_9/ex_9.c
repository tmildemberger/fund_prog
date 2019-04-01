#include <stdio.h>

int main() {
    int numeros;
    scanf("%d", &numeros);
    int soma = 0, soma_dos_quadrados = 0, quadrado_da_soma = 0, i;
    for (i = 1; i <= numeros; ++i) {
        soma += i;
        soma_dos_quadrados += i * i;
    }
    quadrado_da_soma = soma * soma;
    printf("a diferenca entre a soma dos quadrados (%d) e o quadrado da soma (%d) : %d\n", soma_dos_quadrados, quadrado_da_soma, quadrado_da_soma - soma_dos_quadrados);
    return 0;
}