#include <stdio.h>

#define MAX_POINT 50

typedef struct{
    char name[MAX_POINT];
    int age;
} Pessoa;



void main(){
    Pessoa danilo = { "Danilo Micaías", 18};

    printf("%i\n%s\n", danilo.age, danilo.name);
}