#include <stdio.h>

# define N 81

int e_letra(char c) {
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}


int main ()
{
    char string [ N ];
    int i = 0 , j , tam = 0 , palindromo = 1;
    printf ( " Digite uma string : " ) ;
    fgets ( string , N , stdin ) ;
    while ( string [ tam ] && ( string [ tam ] != '\n') )
    tam ++;
    for ( i =0 , j = tam -1; palindromo && (i < j ) ; i ++ ,j --) {
        while (( !e_letra(string [ i ])) && ( i < j ) )
        i ++;
        while (( !e_letra(string [ j ])) && ( i < j ) )
        j --;
        palindromo = ( string [ i ] == string [ j ]) ;
    }

    if ( palindromo )
    printf ( " Palindromo \n " ) ;
    return 0;
}
