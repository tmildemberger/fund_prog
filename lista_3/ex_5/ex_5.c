#include <stdio.h>

int main() {
    int horaInicial, minutosInicial,
    horaFinal, minutosFinal,
    duracaoHoras, duracaoMinutos;
    printf("Escreva a hora de inicio e de fim do jogo:");
    scanf("%d:%d %d:%d", &horaInicial, &minutosInicial, &horaFinal, &minutosFinal);
    if(horaFinal > horaInicial) {
      duracaoHoras = horaFinal - horaInicial;
    }
    else {
      duracaoHoras = 24 + (horaFinal - horaInicial);
    }

    if(minutosFinal > minutosInicial) {
      duracaoMinutos = minutosFinal - minutosInicial;
    } else if (minutosFinal < minutosInicial) {
      duracaoHoras--;
      duracaoMinutos = 60 + (minutosFinal - minutosInicial);
    } else {
      duracaoMinutos = 0;
    }


    printf("O jogo durou %d hora(s) e %d minuto(s)", duracaoHoras, duracaoMinutos);

    return 0;
}
