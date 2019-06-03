#include <stdio.h>
#include <stdlib.h>

int main() {
    int* v;
    while (1) {
        v = (int*) malloc(sizeof *v * 1024);
        printf("%d", *v);
    }
    return 0;
}
