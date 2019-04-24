#include <stdio.h>

void converte_hora(int total_segundos, int *hora, int *min, int *seg);

int main() {
    int total, h, m, s;
    scanf("%d", &total);
    converte_hora(total, &h, &m, &s);
    printf("%02d:%02d:%02d\n", h, m, s);
    return 0;
}

void converte_hora(int total_segundos, int *hora, int *min, int *seg) {
    (*seg) = total_segundos % 60;
    total_segundos /= 60;
    (*min) = total_segundos % 60;
    (*hora) = total_segundos / 60;
}
