#include <stdio.h>

int pot(int base, int exp){
    if(exp == 0){
        return 1;
    }  
    return base * pot(base, exp-1);
}

void main(){
    if(pot(2,3) == 8){
        printf("teste 1: ok\n");
    }
    if(pot(4,2) == 16){
        printf("teste 2: ok\n");
    }
    if(pot(7,0) == 1){
        printf("teste 3: ok\n");
    }
    if(pot(5,1) == 5){
        printf("teste 4: ok\n");
    }
}