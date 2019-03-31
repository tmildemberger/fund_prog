#include <stdio.h>
#include <math.h>

int main() {
    int quantos_primos, inicial;
    scanf("%d %d", &quantos_primos, &inicial);
    if (quantos_primos <= 0 || inicial <= 0) {
        printf("os numeros devem ser positivos (0 nao e positivo)\n");
        return 1;
    }
    if (inicial == 1) ++inicial; //pois um nao e primo
    int encontrados = 0;
    while (encontrados < quantos_primos) {
        int divisor, e_primo = 1;
        // for (divisor = 2; divisor <= round(sqrt(inicial)); ++divisor) {
        //     if (inicial % divisor == 0) {
        //         e_primo = 0;
        //         break;
        //     }
        // }
        for (divisor = 2; divisor < inicial; ++divisor) {
            if (inicial % divisor == 0) {
                e_primo = 0;
                break;
            }
        }
        if (e_primo) {
            ++encontrados;
            printf("%d eh primo\n", inicial);
        }
        ++inicial;
    }
    return 0;
}