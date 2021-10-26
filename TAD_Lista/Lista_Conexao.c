#include <stdlib.h>
#include <stdio.h>
#include "Lista.h"

struct no_ typedef NO;

struct no_
{
  NO *proximo;
  CONEXAO *conexao;
};

struct lista_conexoes_
{
  NO *inicio;
  NO *fim;
  int tamanho;
};

// Cria logicamente uma lista de Conexões
CONEXOES *conexoes_criar(void)
{
  CONEXOES *lista = (CONEXOES *)malloc(sizeof(CONEXOES));
  if (lista != NULL)
  {
    lista->inicio = inicial;
    lista->fim = NULL; // Lista vazia
    lista->tamanho = 0;
  }
  return lista;
}

// Insere uma conexão no fim da lista.
BOOLEAN conexoes_inserir(CONEXOES *lista, CONEXAO *conexao)
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
void conexoes_apagar(CONEXOES **lista)
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

// Retorna as conexões que envolvem a cidade fornecida
int conexoes_get_envolvidas(CONEXOES *lista, unsigned int cidade, CONEXAO ***conexoes_envolvidas)
{
  NO *atual = lista->inicio;
  int tamanho = lista->tamanho;
  *conexoes_envolvidas = (CONEXAO **)malloc(tamanho * sizeof(CONEXAO *));

  int num_conexoes = 0;

  for (int i = 0; i < tamanho; i++)
  {
    if (conexao_get_origem(atual->conexao) == cidade || conexao_get_destino(atual->conexao) == cidade)
      (*conexoes_envolvidas)[num_conexoes++] = atual->conexao;
    atual = atual->proximo;
  }
  return num_conexoes;
}

// Retorna o tamanho da lista
int conexoes_tamanho(CONEXOES *lista)
{
  return lista->tamanho;
}

// Verifica se a lista está vazia
BOOLEAN conexoes_vazia(CONEXOES *lista)
{
  if (lista->inicio == NULL)
    return 1;
  return 0;
}