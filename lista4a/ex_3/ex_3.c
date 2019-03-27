#include <stdio.h>

int main() {
    int n;
    float v1, v2, v3;
    scanf("%d", &n);

    for(;n>0;n--) {
      scanf("%f%f%f", &v1, &v2, &v3);
      printf("%.1f\n", (2*v1 + 3*v2 + 5*v3)/(2+3+5) );
    }

    return 0;
}
