#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main(){
    int n;
    int *v;
    scanf("%i", &n);
    v = malloc(n * sizeof(int));
    for(int i = 0;i < n;i++){
        scanf("%i", &v[i]);
    }

    for(int i = 0;i < n;i++){
        printf("%i\n", v[i]);
    }

    free(v);
}