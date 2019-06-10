#include <stdio.h>

typedef struct tempo {
    int horas;
    int minutos;
    int segundos;
} Tempo;

int main() {
    int segundos_totais;
    scanf("%d", &segundos_totais);
    Tempo decorrido;
    decorrido.horas = segundos_totais / 3600;
    segundos_totais %= 3600;
    decorrido.minutos = segundos_totais / 60;
    decorrido.segundos = segundos_totais % 60;
    printf("%d %d %d\n", decorrido.horas, decorrido.minutos, decorrido.segundos);
    return 0;
}
