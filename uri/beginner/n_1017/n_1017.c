#include <stdio.h>
#define KM_PER_LITER 12.0

int main() {
    int spent_time, average_speed;
    scanf("%d %d", &spent_time, &average_speed);
    printf("%.3f\n", spent_time * average_speed / KM_PER_LITER);
    return 0;
}