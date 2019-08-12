#include "/home/theking7br/Documentos/itp/inc/console.h"


float power(float n,int p){
    for(int i = 1; i<p; i++){
        n *= n;
    }
    return n;
}

void main(){
    int a = readInt();
    int b = readInt();

    printInt(power(a, b));
}