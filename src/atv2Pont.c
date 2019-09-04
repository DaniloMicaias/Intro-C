#include <stdio.h>

void sum(float x1, float y1, float x2, float y2, float *x, float *y){
    *x = x1 + x2;
    *y = y1 + y2;
}

void main(){
    float x1, y1, x2, y2;
    float x = 0;
    float y = 0;

    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);

    sum(x1, y1, x2, y2, &x, &y);
    printf("%.1f\n", x);
    printf("%.1f", y);
    
}