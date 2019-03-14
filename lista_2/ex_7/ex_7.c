#include <stdio.h>

int main() {
    int numero;
    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);
    printf("Seu ultimo digito: %d\n", numero % 10);
    return 0;
}