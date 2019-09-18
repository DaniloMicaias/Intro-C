#include <stdio.h>

int flood(int lin, int col, int n, int x , int y, int table[x][y]){
    int l, c;
    if(table[0][1] != n && table[1][0] != n){
        printf("impossível");
    }

    int ini = table[0][0];

    if(x < col-1 && table[x][y+1] == ini){
        table[x][x+1] = n;
        flood(lin, col, table, n, x, y+1);
    }
    if(x > 0 && table[x][y-1] == ini){
        table[x+1][x] = n;
        flood(lin, col, table, n, x, y-1);
    }
    if(x < lin-1 && table[x+1][y] == ini){
        table[x+1][x] = n;
        flood(lin, col, table, n, x+1, y);
    }
    if(x > 0 && table[x-1][y] == ini){
        table[x-1][x] = n;
        flood(lin, col, table, n, x-1, y);
    }

    for (l = 0; l < lin; l++){
        for (c = 0; c < col; c++){
            printf("%i", table[l][c]);
        }
        printf("\n");
    }
    return 1;
}


void main(){
    int lin, col, l, c;
    scanf("%i %i", &lin, &col);
    int table[lin][col];

    for (l = 0; l < lin; l++){
        for (c = 0; c < col; c++){
            scanf("%i", &table[l][c]);
        }
    }
    int n;
    scanf("%i", &n);

    // flood(int lin, int col, int n, int x , int y, int table[x][y])
    flood(lin, col, n, 0, 0,table);

}