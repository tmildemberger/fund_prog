#include <stdio.h>

int contadigitos(int n, int d);
int ehPermutacao(int n1, int n2);

int main() {
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    if (ehPermutacao(n1, n2)) printf("sim\n");
    else printf("nao\n");
    return 0;
}

int contadigitos(int n, int d) {
    int c = 0;
    
    while ( n > 0) {
        if (n % 10 == d) c++;   
        n /= 10;
    }

    return c;
}


int ehPermutacao(int n1, int n2) {

    int i;
    
    for (i = 0; i <= 9; i++) {
        
        if (contadigitos(n1, i) != contadigitos(n2,i)) return 0;        
        
    }
    return 1;
}

