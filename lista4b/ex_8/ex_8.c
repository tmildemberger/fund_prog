#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);
    for (int i = -num; i <= num; ++i) {
        printf("%3d ", i);
        for (int j = 0; j < i * i + i + 1; ++j) {
            printf(".");
        }
        printf("*\n");
    }
    return 0;
}