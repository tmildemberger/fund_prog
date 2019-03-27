#include <stdio.h>
#include <math.h>
int main() {
    int n, maior, atual, maiord = 0, potencia = 1;
    scanf("%d", &n);
    if (n >0) scanf("%d", &maior);
    for (;n>1; n--) {
      scanf("%d", &atual);
      if (maior < atual) maior = atual;
    }
    // for (n=0; n<=3; n++) {
    //     exp = pow(10, n+1);
    //     maiord += pow(2,n)*(maior%exp)/exp;
    //     maior -= maior%exp;
    // }
    while (maior > 0) {
        maiord += potencia * (maior % 10);
        maior /= 10;
        potencia *= 2;
    }
    printf("o maior e %d\n",  maiord);

    return 0;
}
