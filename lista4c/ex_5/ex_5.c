#include <stdio.h>

#define eh_par(X) (X%2==0)

int main() {
    int i = 2, n,
    valor,
    ultimo_e_par, eh_alternante = 1,
    tamanho_sequencia = 1, tamanho_primeira_sequencia = 1;

    scanf("%d", &n);
    scanf("%d", &valor);

    ultimo_e_par = eh_par(valor);

    scanf("%d", &valor);

    while (ultimo_e_par == eh_par(valor) && i < n) {

      ultimo_e_par = eh_par(valor);
      tamanho_primeira_sequencia++;
      scanf("%d", &valor);
      i++;
    }

    ultimo_e_par = eh_par(valor);

    for (; i < n; i++) {

      scanf("%d", &valor);

      if (ultimo_e_par == eh_par(valor)) tamanho_sequencia++;
      else {
        if (tamanho_sequencia !=tamanho_primeira_sequencia) {
          eh_alternante = 0;
        } else tamanho_sequencia = 1;
      }

      ultimo_e_par = eh_par(valor);
    }
    if( !eh_alternante) printf("nao e alternante\n");
    else printf("a sequencia eh %d-alternante\n", tamanho_primeira_sequencia);
    return 0;
}
