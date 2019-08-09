#include "/home/theking7br/Documentos/itp/inc/console.h"

void main(){
    int i,j;
    int m = readInt();
    int n = readInt();
    int a[m];
    int b[m];

    print("Valores do 1º vetor:");
    for(i = 0; i < m; i++){
        a[i] = readInt();
    }

    print("Valores do 2º vetor:");
    for(i = 0; i < n; i++){
        b[i] = readInt();
    }

    print("Valores Iguais em ambos:");
    for(i = 0; i < m; i++){
        for(j = 0; j < n;j++){
            if(a[i] == b[j]){
                printInt(a[i]);
            }
        }
    }
}