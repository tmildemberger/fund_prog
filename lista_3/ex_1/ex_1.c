#include <stdio.h>

int main() {

    float nota1, nota2, nota3, media;

    printf("digite as notas do aluno:");
    scanf("%f %f %f", &nota1, &nota2, &nota3 );

    media = (nota1 + nota2 + nota3)/3;
    if(media < 0 && media > 10) printf("que\n");
    if (media > 7) printf("o aluno esta aprovado :)\n");
    else if (media < 4 ) printf("o aluno esta reprovado :(\n");
    else printf("o aluno esta em exame :|\n");

    return 0;
}
