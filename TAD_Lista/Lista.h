#ifndef _LISTA_H
#define _LISTA_H

#include <stdio.h>
#include "../TAD_Conexao/Conexao.h"

#define inicial 0

typedef struct lista_ LISTA;

LISTA* lista_criar(void);
int lista_inserir(LISTA *lista, CONEXAO *caminho);
void lista_apagar(LISTA **lista);
CONEXAO *lista_get_conexao(LISTA *lista, int i);
int empty_list(LISTA *lista);
int lista_tamanho(LISTA *lista);

#endif