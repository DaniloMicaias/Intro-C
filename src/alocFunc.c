#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int matriz(int l, int c){
    int lin, col, **a;
    //alocação
    a = calloc(l, sizeof(int*));
    for(lin = 0;lin < l; lin++){
        a[lin] = calloc(c, sizeof(int));
        for(col = 0;col < c; col++){
            a[lin][col] = 100;
        }
    }

    return **a;
}

void main(){
    int l, c, **a;
    scanf("%i %i", &l, &c);
    
    **a = matriz(l, c);
}
