#include <stdio.h>

int main() {
    int a, b, c;

    printf("escreva 3 inteiros distintos:");
    scanf("%d %d %d", &a, &b, &c );
    if (a == b || a == c || b == c) {
      printf("Esses valores não são distintos!\n");
    } else {
      if (a > b && a > c) {

        printf("%d>", a);
        if (b > c) printf("%d>%d", b, c); //a>b>c
        else printf("%d>%d", c, b); //a>c>b

      } else if (b > a && b > c) {

        printf("%d>", b);
        if (a > c) printf("%d>%d", a, c);  //b>a>c
        else printf("%d>%d", c, a); //b>c>a

      } else {

        printf("%d>", c);
        if (a > b) printf("%d>%d", a, b);  //c>a>b
        else printf("%d>%d", b, a);  //c>b>a

      }
    }


    return 0;
}
