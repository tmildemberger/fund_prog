#include <stdio.h>

int main() {
    int number, worked_hours;
    double per_hour;
    scanf("%d %d %lf", &number, &worked_hours, &per_hour);
    printf("NUMBER = %d\n", number);
    printf("SALARY = U$ %.2f\n", worked_hours * per_hour);
    return 0;
}