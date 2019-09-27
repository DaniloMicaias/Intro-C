#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    int l, c, lin, col, **a;
    scanf("%i %i", &l, &c);
    a = calloc(l, sizeof(int*));

    for(lin = 0;lin < l; lin++){
        a[lin] = calloc(c, sizeof(int));
        for(col = 0;col < c; col++){
            a[lin][col] = 100;
        }
    }
}