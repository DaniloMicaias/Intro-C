#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    copa = 0, ouro, pau, espada
} Naipe;

typedef enum{
    A = 1, DOIS, TRES, QUATRO, CINCO, SEIS, SETE, OITO, NOVE, DEZ, J, Q, K
} Numero;

typedef struct{
    Naipe naipe;
    Numero numero;
} Carta;

typedef struct{
    int quantidade;
    Carta cartas[];
} Jogo;


void main(){
    Jogo maco;
    Jogo usuario;
    Jogo computador;

    maco.quantidade = 104;
    usuario.quantidade =  9;
    computador.quantidade = 9;

    for (int i = 0; i < usuario.quantidade; i++){
        usuario.cartas[i].numero = rand() % 13;
        usuario.cartas[i].naipe = rand() % 3;
    }


    while(1){
        char resp[1];
        int naipe = 0;
        int numero = 0;
        printf("Jogador 1: Deseja pegar uma carta no maço?(s or n)");
        scanf("%s", resp);

        if(strcmp(resp, "s") == 0){
            
            int randNaipe = rand() % 3;
            int randNum = rand() % 104;

            //falta definir o numero e o naipe da carta que o jogador irá receber

            printf("Você recebeu a carta: ");
            printf("%i", numero);
            if(naipe == 0){
                printf(" de Copas\n");
            }else if(naipe == 1){
                printf(" de Ouros\n");
            }else if(naipe == 2){
                printf(" de Paus\n");
            }else if(naipe == 3){
                printf(" de Espada\n");
            }

        }

    }
    

}