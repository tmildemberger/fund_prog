#include <stdio.h>

int main() {
    int numero;
    scanf("%d", &numero);
    if (numero < 10) {
        printf("numero rejeitado\n");
        return 1;
    }
    int numero_invertido = 0, n_digitos = 0, temp;
    temp = numero;
    while (temp > 0) {
        numero_invertido = numero_invertido * 10 + temp % 10;
        temp /= 10;
        ++n_digitos;
    }
    int i, e_palindrome = 1;
    for (i = 0; i < (n_digitos / 2 + n_digitos % 2); ++i) {
        if (numero % 10 != numero_invertido % 10) {
            e_palindrome = 0;
            break;
        }
        numero /= 10;
        numero_invertido /= 10;
    }
    if (e_palindrome) {
        printf("eh palindrome\n");
    } else {
        printf("NAO eh palindrome\n");
    }
    return 0;
}
