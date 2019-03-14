#include <stdio.h>

int main() {
    int segundos;
    printf("Digite um numero de segundos: ");
    scanf("%d", &segundos);
    printf("Isso da %d dias, ", segundos / (3600 * 24));
    segundos %= 3600 * 24;
    printf("%d horas, ", segundos / 3600);
    segundos %= 3600;
    printf("%d minutos, ", segundos / 60);
    segundos %= 60;
    printf("e %d segundos\n", segundos);
    return 0;
}