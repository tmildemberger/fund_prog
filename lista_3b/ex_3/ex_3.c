#include <stdio.h>

int main() {
    int dia_nasc, mes_nasc, ano_nasc;
    int dia_atual, mes_atual, ano_atual;
    printf("Escreva uma data de nascimento (formato dd/MM/yyyy): ");
    scanf("%d/%d/%d", &dia_nasc, &mes_nasc, &ano_nasc);
    printf("Escreva uma data atual (formato dd/MM/yyyy): ");
    scanf("%d/%d/%d", &dia_atual, &mes_atual, &ano_atual);
    int idade;
    idade = ano_atual - ano_nasc;
    if (mes_atual < mes_nasc || mes_atual == mes_nasc && dia_atual < dia_nasc) {
        --idade;
    }
    printf("Essa pessoa tem %d anos\n", idade);
    if (idade < 0) {
        printf("Voce nao faz sentido\n");
    }
    // Congruência de Zeller:
    int q = dia_nasc;
    int m = mes_nasc;
    int K = ano_nasc % 100;
    int J = ano_nasc / 100;
    int h = (q + (((m+1) * 26) / 10) + K + K / 4 + J / 4 + 5 * J) % 7;
    const char *dias_da_semana[] = { "sabado", "domingo", "segunda", "terca", 
                                     "quarta", "quinta", "sexta" };
    printf("Alem disso, essa pessoa nasceu em um(a) %s\n", dias_da_semana[h]);
    return 0;
}