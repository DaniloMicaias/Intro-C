#include "console.h"
#include <stdio.h>

void main(){
    int n = readInt();
    int l, c;
    char folha[n][n];

    for (l = 0; l < n; l++){
        for (c = 0; c < n; c++){
            folha[l][c] = readChar();
        }
    }
    
    char cor;
    for(cor = '0'; cor < '9';cor++){
        for (l = 0; l < n; l++){
            for (c = 0; c < n; c++){
                if(folha[l][c] == cor){
                    if(l > 0 && folha[l-1][c] == '*'){
                        folha[l-1][c] = cor + 1;
                    }
                    if(l < n-1 && folha[l+1][c] == '*'){
                        folha[l+1][c] = cor + 1;
                    }
                    if(c > 0 && folha[l][c-1] == '*'){
                        folha[l][c-1] = cor + 1;
                    }
                    if(c < n-1 && folha[l][c+1] == '*'){
                        folha[l][c+1] = cor + 1;
                    }
                }
            }
        }
    }
    for (l = 0; l < n; l++){
        for (c = 0; c < n; c++){
            printf("%c", folha[l][c]);
        }
        printf("\n");
    }
    
}