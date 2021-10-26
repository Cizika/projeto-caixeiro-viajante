#include <stdlib.h>
#include <stdio.h>
#include "Lista.h"

struct no_ typedef NO;

struct no_
{
  NO *proximo;
  CAMINHO *caminho;
};

struct lista_caminhos_
{
  NO *inicio;
  NO *fim;
  int tamanho;
};

// Cria logicamente uma lista de Caminhos
CAMINHOS *caminhos_criar(void)
{
  CAMINHOS *lista = (CAMINHOS *)malloc(sizeof(CAMINHOS));
  if (lista != NULL)
  {
    lista->inicio = inicial;
    lista->fim = NULL;
    lista->tamanho = 0;
  }
  return lista;
}

// Insere um Caminho no final da lista.
unsigned int caminhos_inserir(CAMINHOS *lista, unsigned int cidade, int distancia_total)
{
  if (lista != NULL)
  {
    NO *pnovo = (NO *)malloc(sizeof(NO));
    pnovo->caminho = caminho_criar(cidade, distancia_total);
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
  return 0;
}

// Apaga a lista de caminhos e desaloca a memória utilizada
void caminhos_apagar(CAMINHOS **lista)
{
  NO *no_atual = (*lista)->inicio;
  NO *no_proximo = NULL;
  if (lista != NULL)
  {
    while (no_atual != NULL)
    {
      caminho_apagar(&(no_atual->caminho));
      no_proximo = no_atual->proximo;
      free(no_atual);
      no_atual = no_proximo;
    }
    free(*lista);
  }
}

// Retorna o tamanho da lista
int caminhos_tamanho(CAMINHOS *lista)
{
  return lista->tamanho;
}

// Verifica se a lista de cidades está vazia
unsigned int caminhos_vazia(CAMINHOS *lista)
{
  if (lista->inicio == NULL)
    return 1;
  return 0;
}

// Remove a última cidade visitada da lista de caminhos
unsigned int caminhos_remover(CAMINHOS *lista)
{
  if (lista != NULL)
  {
    NO *pro = lista->inicio;
    NO *ant = NULL;
    while (pro != NULL && pro != lista->fim)
    {
      ant = pro;
      pro = pro->proximo;
    }
    ant->proximo = pro->proximo;
    pro->proximo = NULL;
    lista->fim = ant;
    lista->tamanho--;
    caminho_apagar(&(pro->caminho));
    free(pro);
    return 0;
  }
  return 1;
}

// Busca iterativamente por uma cidade na lista de caminhos
BOOLEAN caminhos_visitado(CAMINHOS *lista, unsigned int cidade)
{
  NO *no_atual = lista->inicio;
  if (lista != NULL)
  {
    while (no_atual != NULL)
    {
      if (caminho_get_ultima_cidade(no_atual->caminho) == cidade)
        return 1;
      no_atual = no_atual->proximo;
    }
  }
  return 0;
}

// Retorna o último caminho dentro da lista (última cidade visitada)
CAMINHO *caminhos_final(CAMINHOS *lista)
{
  return lista->fim->caminho;
}

// Copia uma lista caminhos para outra
CAMINHOS *caminhos_copiar(CAMINHOS *lista)
{
  CAMINHOS *nova_lista = caminhos_criar();
  NO *no_atual = lista->inicio;
  if (lista != NULL)
  {
    while (no_atual != NULL)
    {
      caminhos_inserir(nova_lista, caminho_get_ultima_cidade(no_atual->caminho), caminho_get_distancia_total(no_atual->caminho));
      no_atual = no_atual->proximo;
    }
  }
  return nova_lista;
}

// Imprime todas as cidades visitadas nos Caminhos
void caminhos_print(CAMINHOS *lista)
{
  NO *no_atual = lista->inicio;

  printf("%i", caminho_get_ultima_cidade(no_atual->caminho));
  no_atual = no_atual->proximo;

  if (lista != NULL)
  {
    while (no_atual != NULL)
    {
      caminho_print_ultima_cidade(no_atual->caminho);
      no_atual = no_atual->proximo;
    }
  }
}