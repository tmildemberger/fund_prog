#include <stdio.h>

float calculaMedia(float nota1, float nota2, float nota3, char tipoMedia);

int main() {
    float n1, n2, n3;
    char ch;
    scanf("%f %f %f %c", &n1, &n2, &n3, &ch);
    printf("%.2f\n", calculaMedia(n1, n2, n3, ch));
    return 0;
}

float calculaMedia(float nota1, float nota2, float nota3, char tipoMedia) {
    if (tipoMedia == 'A') {
        return (nota1 + nota2 + nota3) / 3.0f;
    } else if (tipoMedia == 'P') {
        return (nota1 * 5.0f + nota2 * 3.0f + nota3 * 2.0f) / 10.0f;
    }
    return 10.0f;
}
