#include "console.h"
#include <stdio.h>

void main(){
    int i, dist;
    int n = readInt();
    int x[n];
    int y[n];
    

    
    for(i = 0;i < n;i++){
        x[i] = readInt();
        y[i] = readInt();
    }

    for(i = 0;i < n;i++){
        if(i>0){
            dist = sqrt((pow(0,2)-pow(x[i],2))+(pow(0,2)-pow(y[i],2)));
        }else{
            printInt(0);
        }
    }

}