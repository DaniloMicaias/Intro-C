#include <stdio.h>
#include "console.h"

void binario(int n){
    int d, r = n;
    if(n > 1){
        d = n / 2;
        r = n % 2;
        binario(d);
    }
    printf("%i\n", r);
}


void main(){
    int n;
    scanf("%i", &n);
    binario(n);
}