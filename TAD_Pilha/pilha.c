#include <stdlib.h>
#include <stdio.h>
#include "Pilha.h"

struct no typedef NO;

struct no {
    CONEXAO* conexao;
    NO* anterior;
};

struct pilha
{
    NO *TOPO;
    int tamanho;
};

PILHA *pilha_criar()
{
    PILHA *pilha = (PILHA *)malloc(sizeof(PILHA));
    if (pilha != NULL)
    {
        pilha->tamanho = 0;
        pilha->TOPO = NULL;
    }
    return pilha;
}

void pilha_apagar(PILHA **pilha)
{
    NO* paux;
    if (*pilha != NULL && !pilha_vazia(*pilha))
    {
        while (pilha_topo != NULL){
            paux->conexao = pilha_desempilhar(*pilha);
            apagar_conexao(&(paux->conexao));
        }
    }
    free(*pilha);
}

int pilha_cheia(PILHA *pilha)
{
    NO* n = (NO*) malloc(sizeof(NO));
    if (n != NULL){
        free(n);
        n = NULL;
        return 0;
    }
    return 1;
}

int pilha_vazia(PILHA *pilha)
{
    return ((pilha != NULL) ? pilha->tamanho <= 0: ERRO);
}

int pilha_tamanho(PILHA *pilha)
{
    return ((pilha != NULL) ? pilha->tamanho: ERRO);
}

CONEXAO *pilha_topo(PILHA *pilha)
{
    CONEXAO* conexao = NULL;
    if (!pilha_vazia(pilha) && pilha != NULL)
        conexao = (pilha->TOPO)->conexao;
    return conexao;
}

int pilha_empilhar(PILHA *pilha, CONEXAO *conexao)
{
    NO* novo_no = (NO*) malloc(sizeof(NO));
    if (novo_no != NULL)
    {
        novo_no->conexao = conexao;
        novo_no->anterior = pilha->TOPO;
        pilha->TOPO = novo_no;
        (pilha->tamanho)++;
        return 1;
    }
    return 0;
}

CONEXAO *pilha_desempilhar(PILHA *pilha)
{
    CONEXAO *conexao = NULL;
    if (!pilha_vazia(pilha) && pilha !=NULL)
    {
        NO* no = pilha->TOPO;
        conexao = pilha_topo(pilha);
        pilha->TOPO = (pilha->TOPO)->anterior;
        no->anterior = NULL;
        free(no);
        no = NULL;
        pilha->tamanho--;
    }
    return conexao;
}

void pilha_print(PILHA *p)
{
    printf("PILHA: \n");
    printf("Tamanho: %i\n", p->tamanho);
}
