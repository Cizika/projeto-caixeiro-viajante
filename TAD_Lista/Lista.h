#ifndef _LISTA_H
#define _LISTA_H

#include <stdio.h>
#include "../TAD_Caminho/Caminho.h"

#define inicial 0
#define TAMANHO 100
#define ERRO 3200

typedef struct lista_ LISTA;

LISTA* lista_criar(void);
int lista_inserir(LISTA *lista, CAMINHO *caminho);
int lista_inserir_posicao(LISTA *lista, int pos, CAMINHO* caminho);
void lista_apagar(LISTA **lista);
CAMINHO *lista_dequeue(LISTA *lista);
CAMINHO lista_remover(LISTA *lista);

/*CONEXAO* lista_busca(LISTA* lista, int origem, int destino);*/
int empty_list(LISTA *lista);
int lista_cheia(LISTA *lista);
int lista_vazia(LISTA *lista);
int lista_tamanho(LISTA *lista);

#endif