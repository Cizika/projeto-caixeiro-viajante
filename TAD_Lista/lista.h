#ifndef _LISTA_H
#define _LISTA_H

#include <stdio.h>
#include "conexao.h"

#define inicial 0
#define TAMANHO 100

typedef struct lista_ LISTA;

LISTA* lista_criar(void);
int lista_inserir(LISTA *lista, CONEXAO *conexao);
int lista_inserir_posicao(LISTA *lista, int pos, CONEXAO* conexao);
int lista_apagar(LISTA **lista);
int lista_remover(LISTA *lista);

CONEXAO* lista_busca(LISTA* lista, int origem, int destino);

int lista_cheia(LISTA *lista);
int lista_vazia(LISTA *lista);
int lista_tamanho(LISTA *lista);

#endif