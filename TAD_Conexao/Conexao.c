#include "Conexao.h"

#include <stdio.h>
#include <stdlib.h>

struct conexao
{
    int distancia;
    int origem;
    int destino;
};

CONEXAO *conexao_criar(int distancia, int origem, int destino)
{
    CONEXAO *nova_conexao = (CONEXAO *)malloc(sizeof(CONEXAO));

    if (nova_conexao != NULL)
    {
        nova_conexao->distancia = distancia;
        nova_conexao->origem = origem;
        nova_conexao->destino = destino;
        return nova_conexao;
    }
    exit(1);
}

CONEXAO **conexao_lista(int tamanho)
{
  CONEXAO **con_lista = (CONEXAO**)malloc(tamanho*sizeof(CONEXAO*));
  return con_lista;
}

void conexao_lista_add(CONEXAO **lista, CONEXAO *conexao, int tamanho)
{
  
  //try without this
  //CONEXAO **con_lista;
  //con_lista = (CONEXAO**)realloc(lista,(tamanho+1)*sizeof(CONEXAO*));
  //lista=con_lista;
  //printf(" %i %i %i\n", conexao_get_origem(conexao), conexao_get_destino(conexao), conexao_get_distancia(conexao));
  lista[tamanho-1]=conexao;
  //printf("%i\n",lista[tamanho-1]->origem);
}

int conexao_contem(CONEXAO *conexao, int a)
{
  if(conexao->origem==a || conexao->destino==a) return 1;
  return 0;
}
void conexao_apagar(CONEXAO *conexao)
{
    if (conexao != NULL)
        free(conexao);
}

int conexao_get_distancia(CONEXAO *conexao)
{
    return conexao->distancia;
}

int conexao_get_origem(CONEXAO *conexao)
{
    return conexao->origem;
}

int conexao_get_destino(CONEXAO *conexao)
{
    return conexao->destino;
}