#include "console.h"

float power(float n,int p){
    int fat = 1;
    for(int i = 1; i<=p; i++){
        fat *= n; 
    }
    return fat;
}

void main(){
    int a = readInt();
    int b = readInt();

    printInt(power(a, b));
}