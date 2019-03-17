#include <stdio.h>

int main() {
    int distance;
    double fuel;
    scanf("%d %lf", &distance, &fuel);
    printf("%.3f km/l\n", distance / fuel);
    return 0;
}