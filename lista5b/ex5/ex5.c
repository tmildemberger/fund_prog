#include <stdio.h>
int verifica4(int n1, int n2);
int verifica5(int n1, int n2);

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", verifica5(a, b));
    return 0;
}

int verifica4(int n1, int n2) {

    if (n2 > n1) return 0;
    while (n2 != 0 && n1 % 10 == n2 % 10) {
        n1 /= 10;
        n2 /= 10;
    }
    return n2 == 0;
}

int verifica5(int n1, int n2) {
    int x = 2;
    if (n1 == n2) return 0;
    else if (n2 > n1) {
        int aux = n2;
        n2 = n1;
        n1 = aux;
        x = 1;
    }
    
    while (n1 > 0) {
    
        if (verifica4(n1, n2)) return x;
        
        n1 /= 10;
    
    }
    
    return 0;

}
