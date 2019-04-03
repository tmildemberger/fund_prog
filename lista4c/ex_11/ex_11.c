#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <math.h>

int main() {
    long long int numero;
    scanf("%lld", &numero);
    long long int fator = 2, maior_fator = 0;
    for (fator = 2; fator <= round(sqrt(numero)); ++fator) {
        if (numero % fator == 0) {
            long long int divisor, e_primo = 1;
            for (divisor = 2; divisor <= round(sqrt(fator)); ++divisor) {
                if (fator % divisor == 0) {
                    e_primo = 0;
                    break;
                }
            }
            if (e_primo) {
                if (fator > maior_fator) {
                    maior_fator = fator;
                }
            } else {
                printf("%lld e fator mas n e primo\n", fator);
            }
            long long int outro_fator = numero / fator;
            e_primo = 1;
            for (divisor = 2; divisor <= round(sqrt(outro_fator)); ++divisor) {
                if (outro_fator % divisor == 0) {
                    e_primo = 0;
                    break;
                }
            }
            if (e_primo) {
                if (outro_fator > maior_fator) {
                    maior_fator = outro_fator;
                }
            } else {
                printf("%lld e fator mas n e primo\n", outro_fator);
            }
        }
    }
    printf("%lld e o maior divisor primo de %lld\n", maior_fator, numero);
    return 0;
}