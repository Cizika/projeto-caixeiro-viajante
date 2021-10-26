#ifndef _LISTA_H
#define _LISTA_H

#include <stdio.h>
#include "../TAD_Caminho/Caminho.h"
#include "../TAD_Conexao/Conexao.h"

#define inicial 0

typedef unsigned int BOOLEAN;

typedef struct lista_caminhos_ CAMINHOS;
typedef struct lista_conexoes_ CONEXOES;

// Métodos da Lista de Caminhos
CAMINHOS *caminhos_criar(void);
BOOLEAN caminhos_inserir(CAMINHOS *lista, unsigned int cidade, int distancia_total);
void caminhos_apagar(CAMINHOS **lista);
BOOLEAN caminhos_remover(CAMINHOS *lista);
BOOLEAN caminhos_vazia(CAMINHOS *lista);
int caminhos_tamanho(CAMINHOS *lista);
BOOLEAN caminhos_visitado(CAMINHOS *lista, unsigned int cidade);
CAMINHO *caminhos_final(CAMINHOS *lista);
CAMINHOS *caminhos_copiar(CAMINHOS *lista);
void caminhos_print(CAMINHOS *lista);

// Métodos da Lista de Conexões
CONEXOES *conexoes_criar(void);
BOOLEAN conexoes_inserir(CONEXOES *lista, CONEXAO *caminho);
void conexoes_apagar(CONEXOES **lista);
int conexoes_get_envolvidas(CONEXOES *lista, unsigned int cidade, CONEXAO ***conexoes_envolvidas);
BOOLEAN conexoes_vazia(CONEXOES *lista);
int conexoes_tamanho(CONEXOES *lista);

#endif