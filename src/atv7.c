#include "/home/theking7br/Documentos/itp/inc/console.h"

void main(){
    int i, j, max;
    int n = readInt();
    int a[n];
    int c[n];

    for(i = 0; i < n; i++){
        a[i] = readInt();
        c[i] = 0;
    }

    max = 0;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(a[i] == a[j]){
                c[i]++;
            }
        }
        if(c[i] > max){
            max = c[i];
        }
    }
    print("");
    print("Moda(s):");

    for(i = 0; i < n; i++){
        if(c[i] == max){
            printInt(a[i]);
            for (j = i+1; j < n; j++){
                if(a[i] == a[j]){
                    c[j] = 0;
                }
            }
            
        }
    }
}