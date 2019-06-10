#include <stdio.h>

typedef struct tempo {
    int horas;
    int minutos;
    int segundos;
} Tempo;

Tempo converte(int segundos);

int main() {
    int segundos_totais;
    scanf("%d", &segundos_totais);
    Tempo decorrido = converte(segundos_totais);
    printf("%d %d %d\n", decorrido.horas, decorrido.minutos, decorrido.segundos);
    return 0;
}

Tempo converte(int segundos) {
    Tempo convertido;
    convertido.horas = segundos / 3600;
    segundos %= 3600;
    convertido.minutos = segundos / 60;
    convertido.segundos = segundos % 60;
    return convertido;
}
