#include "console.h"
#include <stdio.h>

void main(){
    int i, media;
    int soma = 0;
    int min = 0;
    int max = 0;
    int n = readInt();
    int a[n];

    for(i = 0;i < n;i++){
        a[i] = readInt();
    }
    for(i = 0;i < n;i++){
        soma += a[i];
    }
    media = soma/n;
    printInt(media);
    /*
    for(i = 0;i < n;i++){
        if(a[i] < min){
            min = a[i];
        }
        if(a[i] > max){
            max = a[i];
        }
    }
    */
}

