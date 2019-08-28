#include "console.h"
#include <stdio.h>

void main(){
    int l, c, lh, ch;
    int lin = readInt();
    int col = readInt();
    int m[lin][col];

    for (l = 0; l < lin; l++){
        for (c = 0; c < col; c++){
            m[l][c] = readInt();
            if(m[l][c] == 0){
                lh = l;
                ch = c;
            }
        }
    }
    print("Mapa:");
    for (l = 0; l < lin; l++){
        for (c = 0; c < col; c++){
            printf("%i", m[l][c]);
        }
        printf("\n");
    }
    
    int hasWayPoint = 1;

    while(hasWayPoint){
        hasWayPoint = 0;
        if(lh > 0 && m[lh-1][ch] == 1){
            lh = lh - 1;
            m[lh][ch] = -1;
            hasWayPoint = 1;
        }
        if(lh < lin-1 && m[lh+1][ch] == 1){
            lh = lh + 1;
            m[lh][ch] = -1;
            hasWayPoint = 1;
        }
        if(ch < col -1 && m[lh][ch+1] == 1){
            ch = ch + 1;
            m[lh][ch] = -1;
            hasWayPoint = 1;
        }
        if(ch > 0 && m[lh][ch-1] == 1){
            ch = ch - 1;
            m[lh][ch] = -1;
            hasWayPoint = 1;
        }
    }
    printInt(lh+1);
    printInt(ch+1);
    
}