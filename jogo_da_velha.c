#include <stdio.h>
#include <stdlib.h>
#include "jogo_da_velha.h"

int** cria_tab(int l, int c){
    int** tab = calloc(l, sizeof(int*));
    for (int i = 0; i < l; i++){
        tab[i] = calloc(c, sizeof(int));
    }
    return tab;
}

void libera_tab(int** tab, int l, int c){
    for (int i = 0; i < l; i++){
        free(tab[i]);
    }
    free(tab);
}

int verificador_casa(int** tab, int l, int c){
    if (tab[l][c] != 2 && tab[l][c] != 1){
        return 1;
    }else return 0;
    
}

int verifica_vitoria(int** tab, int jogador){
    if (tab[0][0] == jogador && tab[0][1] == jogador && tab[0][2] == jogador ||
        tab[1][0] == jogador && tab[1][1] == jogador && tab[1][2] == jogador ||
        tab[2][0] == jogador && tab[2][1] == jogador && tab[2][2] == jogador ||

        tab[0][0] == jogador && tab[1][0] == jogador && tab[2][0] == jogador ||
        tab[0][1] == jogador && tab[1][1] == jogador && tab[2][1] == jogador ||
        tab[0][2] == jogador && tab[1][2] == jogador && tab[2][2] == jogador ||

        tab[0][0] == jogador && tab[1][1] == jogador && tab[2][2] == jogador ||
        tab[0][2] == jogador && tab[1][1] == jogador && tab[2][0] == jogador){
        return 1;
    }else return 0;
    
}

int dentro_do_jogo(int l, int c){
    if (l >= 0 && l <= 2 && c >= 0 && c <= 2){
        return 1;
    }else return 0;
}

int* jogada_cpu(int** tab, int* pc){
    if(tab[1][1] != 0 && tab[0][1] != 0 && tab[1][0] != 0 && tab[1][2] != 0 && tab[2][1] != 0){
        if (tab[0][0] == 0 && (tab[0][1] == 1 || tab[1][1] == 1 || tab[1][0] == 1)){
            pc[0] = 0;
            pc[1] = 0;
            return pc;
        }else if (tab[0][2] == 0 && (tab[0][1] == 1 || tab[1][2] == 1 || tab[1][1] == 1)){
            pc[0] = 0;
            pc[1] = 2;
            return pc;
        }else if (tab[2][0] == 0 && (tab[2][1] == 1 || tab[1][1] == 1 || tab[1][0] == 1)){
            pc[0] = 2;
            pc[1] = 0;
            return pc;
        }else if (tab[2][2] == 0 && (tab[2][1] == 1 || tab[1][1] == 1 || tab[1][2] == 1)){
            pc[0] = 2;
            pc[1] = 2;
            return pc;
        } 
    }else{
        if (tab[1][1] == 0){
            pc[0] = 1;
            pc[1] = 1;
            return pc;
        }else if (tab[0][1] == 0 && (tab[0][0] == 1 || tab[0][2] == 1 || tab[1][1] == 1)){
            pc[0] = 0;
            pc[1] = 1;
            return pc;
        }else if (tab[1][0] == 0 && (tab[0][0] == 1 || tab[2][0] == 1 || tab[1][1] == 1)){
            pc[0] = 1;
            pc[1] = 0;
            return pc;
        }else if (tab[1][2] == 0 && (tab[2][2] == 1 || tab[0][2] == 1 || tab[1][1] == 1)){
            pc[0] = 1;
            pc[1] = 2;
            return pc;
        }else if (tab[2][1] == 0 && (tab[2][2] == 1 || tab[2][0] == 1 || tab[1][1] == 1)){
            pc[0] = 2;
            pc[1] = 1;
            return pc;
        }
    }

    if (tab[0][0] != 0 && tab[0][2] != 0 && tab[2][0] != 0 && tab[2][2] != 0){
        pc = jogada_cpu(tab, pc);
        return pc;
    }else if (tab[0][0] == 0 && (tab[0][1] == 1 || tab[1][1] == 1 || tab[1][0] == 1)){
            pc[0] = 0;
            pc[1] = 0;
            return pc;
        }else if (tab[0][2] == 0 && (tab[0][1] == 1 || tab[1][2] == 1 || tab[1][1] == 1)){
            pc[0] = 0;
            pc[1] = 2;
            return pc;
        }else if (tab[2][0] == 0 && (tab[2][1] == 1 || tab[1][1] == 1 || tab[1][0] == 1)){
            pc[0] = 2;
            pc[1] = 0;
            return pc;
        }else if (tab[2][2] == 0 && (tab[2][1] == 1 || tab[1][1] == 1 || tab[1][2] == 1)){
            pc[0] = 2;
            pc[1] = 2;
            return pc;
        }
}

int verifica_empate(int** tab){
    int cont = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (tab[i][j] != 0){
                cont++;
            }
        }
    }
    
    if (cont == 9){
        return 1;
    }else return 0;
}

int partidas(int** tab, int num){
    // 1 - user e 2 - cpu
    int aux = 0;
    int l,c;
    int* pc = malloc(2 * sizeof(int));
    int v;
    int cpu_move[2];
    tab = cria_tab(3,3);

    do{
       do{
            scanf("%d %d", &l, &c);
            v = verificador_casa(tab, l, c);
            if (v == 1){
                tab[l][c] = 1;  
            }
        } while (v == 0);

        if (verifica_vitoria(tab, 1) == 1){
            return 1;
        }

        if (verifica_empate(tab) == 0){
            pc = jogada_cpu(tab, pc);
            tab[pc[0]][pc[1]] = 2;
            printf("%d %d\n", pc[0], pc[1]);

            if (verifica_vitoria(tab, 2) == 1){
                return -1;
            }
        }
        aux++;

    } while (aux != 5);
    
    free(pc);
    libera_tab(tab, 3,3);
    return 0;
}