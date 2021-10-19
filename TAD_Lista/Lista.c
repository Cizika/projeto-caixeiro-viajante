#include <stdlib.h>
#include <stdio.h>
#include "Lista.h"

struct no_ typedef NO;

struct no_
{
  NO *proximo;
  CONEXAO *conexao;
};

struct lista_
{
  NO *inicio;
  NO *fim;
  int tamanho;
};

LISTA *lista_criar(void)
{
  LISTA *lista = (LISTA *)malloc(sizeof(LISTA));
  if (lista != NULL)
  {
    lista->inicio = inicial;
    lista->fim = NULL; // Lista vazia
    lista->tamanho = 0;
  }
  return lista;
}

// Insere uma conexão no fim da lista.
int lista_inserir(LISTA *lista, CONEXAO *conexao)
{
  if (lista != NULL)
  {
    NO *pnovo = (NO *)malloc(sizeof(NO));
    pnovo->conexao = conexao;
    if (lista->inicio == NULL)
    {
      lista->inicio = pnovo;
    }
    else
      lista->fim->proximo = pnovo;
    pnovo->proximo = NULL;
    lista->fim = pnovo;
    lista->tamanho++;
    return 1;
  }
  else
    return 0;
}

// Apaga a lista e desaloca memória
void lista_apagar(LISTA **lista)
{
  NO *no_atual = (*lista)->inicio;
  NO *no_proximo = NULL;
  if (lista != NULL)
  {
    while (no_atual != NULL)
    {
        conexao_apagar(&(no_atual->conexao));
        no_proximo = no_atual->proximo;
        free(no_atual);
        no_atual = no_proximo;
    }
    free(*lista);
  }
}

CONEXAO *lista_get_conexao(LISTA *lista, int k)
{
  NO *atual = lista->inicio;
  for(int i=0;i<k;i++)
  {
    atual=atual->proximo;
  }
  return atual->conexao;
}

// Retorna o tamanho da lista
int lista_tamanho(LISTA *lista)
{
  return lista->tamanho;
}

int empty_list(LISTA *lista)
{
  if(lista->inicio==NULL) return 1;
  return 0;
}