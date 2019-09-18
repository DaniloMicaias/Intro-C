#include <stdio.h>

int maior(int v[], int n){
    if(n == 1){
        return v[0];
    }
    int m = maior(v, n-1);
    if(v[n-1] > m){
        return v[n-1];
    }else{
        return m;
    }
}

void main(){
    int v[] = {3, 8, 9, 1, 5};

    printf("%i\n", maior(v, 5));
}