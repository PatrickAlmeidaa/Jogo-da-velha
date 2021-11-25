#ifndef jogo_da_velha_h
#define jogo_da_velha_h

#include <stdio.h>

int** cria_tab(int l, int c);
void libera_tab(int** tab, int l, int c);
int verificador_casa(int** tab, int l, int c);
int verifica_vitoria(int** tab, int jogador);
int dentro_do_jogo(int l, int c);
int* jogada_cpu(int** tab, int* pc);
int verifica_empate(int** tab);
int partidas(int** tab, int num);

#endif