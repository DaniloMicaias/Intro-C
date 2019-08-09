#include "/home/theking7br/Documentos/itp/inc/console.h"

void main(){
    int i, j;
    int aux = 0;
    int n = readInt();
    int p;
    int a[n];

    print("Valores do vetor:");
    for(i = 0; i< n; i++){
        a[i] = readInt();
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(a[i] > a[j]){
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
        }
    }
    print("Qual a posição que você deseja conferir?");
    p = readInt();
    printInt(a[p-1]);
}