#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);
    int x, y;
    for (x = 1; x <= num; ++x) {
        printf ("%d -> ", x);
        for (y = 1; y <= x; ++y) {
            printf("%d ", x * y);
        }
        printf("\n");
    }
    return 0;
}