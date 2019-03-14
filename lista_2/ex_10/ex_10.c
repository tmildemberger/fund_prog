#include <stdio.h>

int main() {
    int nota0, nota1, nota2;
    printf("Escreva as suas tres notas: ");
    scanf("%d %d %d", &nota0, &nota1, &nota2);
    float media_ponderada = (nota0 * 2.0 + nota1 * 3.0 + nota2 * 5.0) / 10.0;
    printf("Sua nota final foi %.1f\n", media_ponderada);
    return 0;
}