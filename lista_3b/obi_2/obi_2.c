#include <stdio.h>

int main() {
    float preco_a, preco_g, rend_a, rend_g;
    scanf("%f %f %f %f", &preco_a, &preco_g, &rend_a, &rend_g);
    if (preco_g / rend_g > preco_a / rend_a) {
        // quer dizer que gasolina gasta mais reais por litro
        printf("A\n");
    } else {
        // quer dizer que a gasolina é mais economica ou é indiferente
        printf("G\n");
    }
    return 0;
}