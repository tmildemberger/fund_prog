#include <stdio.h>

int bloco(int n);
int impar(int n);

int main() {
    int n, i = 2, m = 1, ultSeqImpar, seqImpar, ePiramidal;
    
    scanf("%d", &n);
    
    
    n--;
    
    ultSeqImpar = bloco (1);
    if (ultSeqImpar == -1) ePiramidal = 0;
    else ePiramidal = 1;
    
    while (n > 0) {
    
        if (n - i < 0) ePiramidal = 0;
        else seqImpar = bloco(i);
        
        if (seqImpar == -1) ePiramidal = 0;
        else if (seqImpar == ultSeqImpar) ePiramidal = 0;
        
        
        n -= i++;
        m++;
    
    }
    
    if (ePiramidal) printf("m = %d\n", m);
    else printf("nao\n");
    
    return 0;
}

int bloco (int n) {
    
    int m, seqImpar;
    
    scanf("%d", &m);
    
    seqImpar = impar(m);
    
    for (; n > 1; n--) {
    
        scanf("%d", &m);
        if (impar(m) != seqImpar) return -1;
    
    }    

    return seqImpar;
}

int impar(int n) { return n % 2; }
