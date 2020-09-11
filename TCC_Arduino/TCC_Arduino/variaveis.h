#ifndef variaveis
#define variaveis

#include "Arduino.h"

#define MAX_ESTADOS    5
#define MAX_TRANSICOES 25
#define MAX_PALAVRA    16

/* 
 MATRIZ
 ESTADO TRANSIÇÃO ESTADO
 */
char matriz[MAX_TRANSICOES][3]; // MATRIZ QUE ARMAZENA AS TRANSIÇÕES.
int numero_transicao=0;
char palavra[MAX_PALAVRA];
char estados_finais[MAX_ESTADOS];
int posicao_matriz=0;
int numero_estados_finais=0;
int tamanho_palavra=0;
char estado_atual='0'; // O ESTADO INICIAL SERÁ SEMPRE O ZERO.
bool flag_nok=false;

#endif

