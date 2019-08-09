#include "/home/theking7br/Documentos/itp/inc/console.h"

void main(){
    int soma, d, x;
    int n2 = 0;

    d = readInt();

    int i = 0; 
    int c = 1;
/*
    while(c <= d){
        n2 = readInt();
        soma += n2;
        if(soma >= 1000000){
            x = c - i;
            i++;
        }
        c++;
        n2 = 0;
    }
*/
    for(int q = 1; q <= d; q++){
        n2 = readInt();
        soma += n2;
        if(soma >= 1000000){
            x = c - i;
            i++;
        }
        c++;
        n2 = 0;
    }
    printInt(x);
}