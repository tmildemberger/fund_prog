#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 100

int main() {
    char str[N];
    // int tam;
    // scanf("%d", &tam);
    scanf("%s", str);

    // if ((int)sqrt(strlen(str)))
    int i;
    for (i = 0; i < (int)sqrt(strlen(str)); ++i) {
        int j;
        for (j = 0; j < (int)sqrt(strlen(str)); ++j) {
            putchar(str[i + j * (int)sqrt(strlen(str))]);
        }
    }
    putchar('\n');
    return 0;
}
