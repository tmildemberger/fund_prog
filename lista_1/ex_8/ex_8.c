#include <stdio.h>

int main() {
    
    char letra;

    printf("Digite uma letra maiuscula: ");
    scanf("%c", &letra);

    if (letra >= 'A' && letra <= 'Z') {
        letra = letra - 'A' + 'a';
    }

    printf("%c\n", letra);

    return 0;
}