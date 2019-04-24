#include <stdio.h>

void removeExtremos(int *n, int *pri, int *ult);

int main() {
    int num, e_palindromo = 1;
    scanf("%d", &num);
    while (num > 0) {
        int primeiro_d, ultimo_d;
        removeExtremos(&num, &primeiro_d, &ultimo_d);
        if (primeiro_d != ultimo_d) {
            e_palindromo = 0;
            break;
        }
    }
    if (e_palindromo) {
        printf("palindromo\n");
    } else {
        printf("nao palindromo\n");
    }
    return 0;
}

void removeExtremos(int *n, int *pri, int *ult) {
    int tn, pot = 1;
    tn = *n;
    while(tn >= 10){
        tn = tn / 10;
        pot *= 10;
    }
    *pri = *n / pot;
    *ult = *n % 10;
    *n = *n % pot;
    *n = *n / 10;
}
