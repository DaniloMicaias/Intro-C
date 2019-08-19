#include "console.h"
#include <stdio.h>

void main(){
    int i, j, c, l;
    l = readInt();
    c = readInt();
    int m[l][c];
    int n[c][l];

    for(i = 0;i < l;i++){
        for(j = 0;j < c;j++){
            m[i][j] = readInt();
        }
    }

    for(i = 0;i < l;i++){
        for(j = 0;j < c;j++){
            n[j][i] = m[i][j];
        }
    }
    print("Matriz Normal:");
    for(i = 0;i < l;i++){
        for(j = 0;j < c;j++){
            printf("%i ", m[i][j]);
        }
        print("\n");
    }
    print("Matriz Transposta:");
    for(i = 0;i < c;i++){
        for(j = 0;j < l;j++){
            printf("%i ", n[i][j]);
        }
        print("\n");
    }

    
}