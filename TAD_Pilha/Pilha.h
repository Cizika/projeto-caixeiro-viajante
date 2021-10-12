#ifndef _PILHA_H
#define _PILHA_H

#include "../TAD_Caminho/Caminho.h"

#define TAM 10
#define ERRO -32000

typedef struct pilha PILHA;

PILHA *pilha_criar();
void pilha_apagar(PILHA **pilha);
unsigned int pilha_empilhar(PILHA *pilha, CAMINHO *item);
CAMINHO *pilha_desempilhar(PILHA *pilha);
CAMINHO *pilha_topo(PILHA *pilha);
unsigned int pilha_cheia(PILHA *pilha);
int pilha_vazia(PILHA *pilha);
int pilha_tamanho(PILHA *pilha);
PILHA *pilha_copiar(PILHA *pilha);
void pilha_print(PILHA *p);
void pilha_inverter(PILHA *p);
unsigned int caminho_visitado(PILHA *pilha, unsigned int cidade);

#endif