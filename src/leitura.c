#include <stdio.h>

void main(){
    FILE *file;
    file = fopen("entrada.txt", "w+");
    /* Tratamento do Erro */
    if (file == NULL){
        printf("Erro na abertura!\n");
    }
    fclose(file);
}