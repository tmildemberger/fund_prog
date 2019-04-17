#include <stdio.h>
#include <math.h>
//#include <stdlib.h>
#define epsilon pow(10, -15)

double f(double x) {
    return log(x)+atan(x);
}

int main() {
    double a, b, x;
    int iteracoes = 0;

    scanf("%lf %lf", &a, &b);
    while (f(a) * f(b) > 0) {
      printf("nao\n");
      scanf("%lf %lf", &a, &b);
    }

    x = (a + b) / 2;
    printf("%f\n", fabs(f(x) - 0));
    while (fabs(f(x) - 0) > epsilon) {

        if (f(b) * f(x) < 0) a = x;
        else if (f(a) * f(x) < 0) b = x;
        x = (a + b) / 2;
        iteracoes++;
        printf("%lf\n", f(x));
    }

    printf("uma raiz de f e %.15lf\nforam necessarias %d iteracoes\n", x, iteracoes);
    return 0;
}
