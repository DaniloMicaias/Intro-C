#include "console.h"

int max(int v[], int n){
    int m = 0;
    for(int i = 0; i < n;i++){
        if(v[i] > m){
           m = v[i];
        }
    }
    return m;
}

void main(){
    print("Digite o tamanho do vetor:");
    int x = readInt();
    int v[x];

    print("Valores do vetor:");
    for (int i = 0; i < x; i++){
        v[i] = readInt();
    }

    print("Maior número do vetor:");
    printInt(max(v, x));
}