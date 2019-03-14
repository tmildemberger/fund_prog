#include <stdio.h>

int main() {
    
    int aux;                                // erro 1: falta o ponto e vírgula

    printf("Digite um numero inteiro: ");   // erro 2: falta fechar aspas
    scanf("%d", &aux);                      // erro 3: uso do # no lugar do %
                                            // erro 4: AUX no lugar de aux
    printf("%d\n", aux);                    // erro 5: prinf deveria ser printf
                                            // erro 6: não devia usar &
    return 0;                               // erro 7: falta o ponto e vírgula
}