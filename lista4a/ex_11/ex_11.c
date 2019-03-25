#include <stdio.h>

int main() {
    int porquinhos;
    scanf("%d", &porquinhos);
    while (porquinhos >= 0) {
        printf("custo para %d porquinhos: US$ %.2f\n", porquinhos, porquinhos * 0.4 + 10);
        scanf("%d", &porquinhos);
    }
    return 0;
}
