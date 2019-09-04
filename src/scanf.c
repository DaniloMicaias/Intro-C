#include <stdio.h>

void main(){
    int a;
    char b;

    float c;

    scanf("%i %c %f", &a, &b, &c);
    printf("Você digitou o:\n");
    printf("%i %c %.1f", a, b, c);
}