#include <stdio.h>

int main() {
    int numero;
    for (numero = 1000; numero < 10000; numero++) {
        if (numero == (numero/100 + numero%100)*(numero/100 + numero%100)) {
          printf("%d\n", numero);
        }
    }

    return 0;
}
