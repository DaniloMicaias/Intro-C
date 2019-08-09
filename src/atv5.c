#include "/home/theking7br/Documentos/itp/inc/console.h"
#include "stdio.h"

void main(){
    int i, j;
    int n = readInt();
    int a[n];
    int b[n];

    for(i = 0; i < n; i++){
        a[i] = readInt();
        b[i] = 0;
    }
    for(i = 0; i < n; i++){
        for(j = 0;j < n; j++){
            if(a[i] == a[j]){
                b[i]++;
            }
        }
    }
    print("____");
    
    for(i = 0;i < n;i++){
        //Falta fazer isso
    }


}