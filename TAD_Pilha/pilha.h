#ifndef _PILHA_H
#define _PILHA_H

#include "conexao.h"

#define TAM 10
#define ERRO -32000

typedef struct pilha PILHA;

PILHA* pilha_criar();
void pilha_apagar(PILHA** pilha);
int pilha_vazia(PILHA* pilha);
int pilha_cheia(PILHA* pilha);
int pilha_tamanho(PILHA* pilha);
CONEXAO* pilha_topo(PILHA* pilha);
int pilha_empilhar(PILHA* pilha, CONEXAO* conexao);
CONEXAO* pilha_desempilhar(PILHA* pilha);
void pilha_print(PILHA* p);

#endif