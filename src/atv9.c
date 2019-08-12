#include "/home/theking7br/Documentos/itp/inc/console.h"


void ordene(int n, int o[]){
    int aux = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(o[i] > o[j]){
                aux = o[i];
                o[i] = o[j];
                o[j] = aux;
            }
        }
    }
    print("Lista Ordenada decrescentemente!");
    print("Qual a posição que você deseja conferir?");
    int p = readInt();
    printInt(o[p-1]);
}

void main(){
    int i, j;
    int n = readInt();
    int p;
    int a[n];

    print("Valores do vetor:");
    for(i = 0; i< n; i++){
        a[i] = readInt();
    }

    ordene(n, a);
}