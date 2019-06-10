#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

typedef struct valor {
    int reais;
    int centavos;

} Valor;

typedef struct eletro {
    int codigo;
    int telefoneLoja;
    Valor preco;
} Eletro;

Eletro aleatorio();

int main() {
    srand(time(NULL));
    Eletro domesticos[N];
    int i;
    for (i = 0; i < N; ++i) {
        domesticos[i] = aleatorio();
        printf("%d: %d cel:%d R$%03d.%02d\n", i, domesticos[i].codigo, domesticos[i].telefoneLoja, domesticos[i].preco.reais, domesticos[i].preco.centavos);
    }
    Valor medio;
    medio.reais = 0;
    medio.centavos = 0;

    for (i = 0; i < N; ++i) {
        medio.centavos += domesticos[i].preco.centavos;
        medio.reais += domesticos[i].preco.reais;
    }
    medio.reais += medio.centavos/100;
    medio.centavos %= 100;
    medio.centavos = (medio.centavos)/N+100*(medio.reais/(float)N -medio.reais/N);
    medio.reais /= N;

    printf("preco medio = R$%03d.%02d\nLojas com preço abaixo da media:\n", medio.reais, medio.centavos);
    for (i = 0; i < N; ++i) {
        if ((domesticos[i].preco.reais < medio.reais) || ((domesticos[i].preco.reais == medio.reais) && ((domesticos[i].preco.centavos < medio.centavos)) ))
            printf("%d: telefone: %d\n", i, domesticos[i].telefoneLoja);
    }


    return 0;
}

Eletro aleatorio() {
    Eletro retorno;
    retorno.codigo = rand();
    retorno.telefoneLoja = rand() % 100000000;
    retorno.preco.reais = rand() % 1000;
    retorno.preco.centavos = rand() % 100;

    return retorno;
}
