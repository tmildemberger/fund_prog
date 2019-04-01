#include <stdio.h>

int main() {
    int i, n,
    valor, ultimo_valor,
    tamanho_sequencia = 1, maior_tamanho_sequencia = 1;

    scanf("%d", &n);
    scanf("%d", &ultimo_valor);

    for (i = 1; i < n; i++) {

      scanf("%d", &valor);

      if (valor > ultimo_valor) {

        tamanho_sequencia++;

        if (tamanho_sequencia > maior_tamanho_sequencia)
          maior_tamanho_sequencia = tamanho_sequencia;

      } else {
        tamanho_sequencia = 1 ;
      }

      ultimo_valor = valor;
    }

    printf("%d\n", maior_tamanho_sequencia);
    return 0;
}
