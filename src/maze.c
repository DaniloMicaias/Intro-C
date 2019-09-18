#include <stdio.h>

int findPath(int lin, int col, int maze[lin][col],
    int linOrg, int colOrg, int linDest, int colDest
    ){
        if(linOrg == linDest && colOrg == colDest){
            return 1;
        }

        if(colOrg < 0 || colOrg >= col || linOrg < 0 || linOrg >= lin){
            return 0;
        }
        if(maze[linOrg][colOrg] != 0){
            return 0;
        }
        maze[linOrg][colOrg] = 2;


        int right = findPath(lin, col, maze, linOrg, colOrg+1, linDest, colDest);
        int left = findPath(lin, col, maze, linOrg, colOrg-1, linDest, colDest);
        int up = findPath(lin, col, maze, linOrg-1, colOrg, linDest, colDest);
        int down = findPath(lin, col, maze, linOrg+1, colOrg, linDest, colDest);

        if(right || left || up || down){
            return 1;
        }else{
            return 0;
        }
}

void main(){
    int lin, col, l, c;
    scanf("%i %i", &lin, &col);
    int maze[lin][col];

    for (l = 0; l < lin; l++){
        for (c = 0; c < col; c++){
            scanf("%i", &maze[l][c]);
        }
    }

    int linO, colO, linD, colD;
    scanf("%i %i %i %i", &linO, &colO, &linD, &colD);
    if(findPath(lin, col, maze, linO, colO, linD, colD)){
        printf("sim\n");
    }else{
        printf("não\n");
    }
}