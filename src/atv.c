#include "/home/theking7br/Documentos/itp/inc/console.h"

void main(){
    int i, j, cont = 0;
    int n = readInt();
    int a[n];

    for(i = 0; i < n; i++){
        a[i]= readInt();
    }

    for (i = 0; i < n; i++){
        cont = 0;
        for(j = 0; j < n; j++){
            if(a[i] == a[j]){
                cont++;
            }
        }
        if(cont == 1){
            printInt(a[i]);
        }
    }
    
}