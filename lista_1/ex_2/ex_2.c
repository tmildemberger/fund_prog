#include <stdio.h>

int main() {

    char caractere;
    int inteiro;
    float real;
    printf("Escreva um numero inteiro: ");
    scanf("%d", &inteiro);

    printf("Escreva um caractere: ");
    scanf(" %c", &caractere);

    printf("Escreva um numero real: ");
    scanf("%f", &real);

    printf("Aqui esta o seu caractere: %c\n", caractere);
    printf("Aqui esta o seu real: %f\n", real);
    printf("Aqui esta o seu inteiro: %d\n", inteiro);

    return 0;
}