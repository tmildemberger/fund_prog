#include <stdio.h>

int main() {
    int numero, primo, soma = 0,
    i, j;

    for(i = 0; i < 10; i++) {

      scanf("%d", &numero);
      if (numero > 1) {
        for(j = 2, primo = 1; j < numero; j++) {
          if (numero%j == 0) {
            primo = 0;
            break;
          }
        }
        if (primo) soma += numero;
      }
    }
    printf("%d\n", soma);
    return 0;
}
