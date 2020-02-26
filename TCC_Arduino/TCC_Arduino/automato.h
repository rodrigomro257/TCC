#ifndef automato
#define automato

#include "display.h"

#define MONTA_AUTOMATO 0x00
#define DEFINE_FINAIS  0x01
#define INSERE_PALAVRA 0x02
#define VALIDA_PALAVRA 0x03

#define DEBOUNCE 150
#define TEMPO_EXIBICAO 200

int ESTADO=MONTA_AUTOMATO;

void zera_matriz_e_finais();
void maquina_estados();
bool tem_transicao=false;
bool tem_estado_final=false;

#endif

