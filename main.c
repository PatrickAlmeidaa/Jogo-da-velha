#include <stdio.h>
#include <stdlib.h>
#include "jogo_da_velha.h"

int main(){
    int** tab;
    int npu = 0;
    int npc = 0;
    int aux;
    int n;
    char continuar;

    for (int i = 0; i < 3; i++){
        aux = partidas(tab, 3);
        if (aux == 1){
            npu++;
        }else if(aux == -1){
            npc++;
        }else{
            // em caso de empate, nenhum jogador recebe ponto
            npu = npu;
            npc = npc;
        }
        printf("\n");
    }

    while (scanf("%c", &continuar)){
        switch (continuar){
        case 'p':
            printf("%d %d\n", npu, npc);
            exit(1);
            break;
        
        case 'c':
            for (int i = 0; i < 2; i++){
                aux = partidas(tab, 2);
                if (aux == 1){
                    npu++;
                }else if (aux == -1){
                    npc++;
                } else{
                    npu = npu;
                    npc = npc;
                }
            }
            break;
        }
    }
    return 0;
}