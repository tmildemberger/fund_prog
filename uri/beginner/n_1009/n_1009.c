#include <stdio.h>

int main() {
    double fixed_salary, sold;
    scanf("%*s %lf %lf", &fixed_salary, &sold);
    printf("TOTAL = R$ %.2f\n", fixed_salary + sold * 0.15);
    return 0;
}