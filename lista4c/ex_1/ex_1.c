#include <stdio.h>

int main() {
  int i, n, valor, ultimoValor, nSequencias = 0, emSequencia=0;

  scanf("%d", &n);
  scanf("%d", &ultimoValor);

  for (i = 1; i < n; i++) {

    scanf("%d", &valor);

    if (valor == ultimoValor && !emSequencia) {
      emSequencia = 1;
      nSequencias++;
    } else if (valor != ultimoValor) {
      emSequencia = 0;
    }

    ultimoValor = valor;
  }

  printf("%d\n", nSequencias);

  return 0;
}
