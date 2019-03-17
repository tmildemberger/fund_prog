#include <stdio.h>
#include <math.h>

int main() {
    int in0, in1, in2;
    scanf("%d %d %d", &in0, &in1, &in2);
    int greatest = (in0 + in1 + abs(in0 - in1)) / 2;
    greatest = (greatest + in2 + abs(greatest - in2)) / 2;
    printf("%d eh o maior\n", greatest);
    return 0;
}