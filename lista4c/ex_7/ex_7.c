#include <stdio.h>

int main() {
    int i, j, maior_palindrome = 0;
    for (i = 999; i >= 100; --i) {
        for (j = 999; j >= 100; --j) {
            int n = i * j;
            {
                int numero = n, numero_invertido = 0, n_digitos = 0, temp;
                temp = n;
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
                    maior_palindrome = n;
                    break;
                }
            }
        }
        if (maior_palindrome != 0) {
            break;
        }
    }
    printf("o maior palindromo multiplo de dois numeros de 3 digitos e: %d x %d = %d\n", i, j, maior_palindrome);
    return 0;
}
