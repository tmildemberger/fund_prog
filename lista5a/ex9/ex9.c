#include <stdio.h>

int retormaMaior(int n1, int n2);

int main() {
    int n1, n2, n3, maior12, maior123;
    scanf("%d %d %d", &n1, &n2, &n3 );
    maior12 = retormaMaior(n1, n2);
    maior123 = retormaMaior(maior12, n3);
    printf("%d\n", maior123);
    return 0;
}

int retormaMaior(int n1, int n2) {
  return ((n1 > n2) ? n1 : n2);
}
