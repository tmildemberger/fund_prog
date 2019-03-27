#include <stdio.h>

int main() {
    int numero, i;    //x(1/3) é menor que x/3 para todos os x > 6
    scanf("%d", &numero);
    int triangular = 0;
    if (numero % 6 == 0) {
        for (i = 2; i <= numero/3; ++i) {
            if (numero == i * i * i - i) {
                triangular = 1;
                break;
            }
        }
    }
    if (triangular) printf("eh triangular\n");
    return 0;
}
