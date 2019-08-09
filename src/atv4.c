#include "/home/theking7br/Documentos/itp/inc/console.h"

void main(){
    int i, j;
    int c = 0;
    int x = 0;
    int n = readInt();
    int m = readInt();
    int a[n];
    int b[n];

    print("Valores de A:");
    for(i = 0; i < n; i++){
        a[i] = readInt();
        c++;
    }

    print("Valores de B:");
    for(i = 0; i < m; i++){
        b[i] = readInt();
        c++;
    }

    i = 0;
    j = 0;
    print("_________");
    while(x < c){
        if(a[i] < b[j]){
            printInt(a[i]);
            i++;
        }else{
            printInt(b[j]);
            j++;
        }
    x++;
    }

    

}