#include "conexao.h"

#include <stdio.h>
#include <stdlib.h>

struct conexao
{
    int distancia;
    int cidades[2];
};

CONEXAO *conexao_criar(int distancia, int cidadeA, int cidadeB)
{
    CONEXAO *nova_conexao = (CONEXAO *)malloc(sizeof(CONEXAO));

    if (nova_conexao != NULL)
    {
        nova_conexao->distancia = distancia;
        nova_conexao->cidades[0] = cidadeA;
        nova_conexao->cidades[1] = cidadeB;
        return nova_conexao;
    }
    exit(1);
}

void conexao_apagar(CONEXAO *conexao)
{
    if(conexao != NULL)
        free(conexao);
}

int conexao_get_distancia(CONEXAO *conexao)
{
    return conexao->distancia;
}

int *conexao_get_cidades(CONEXAO *conexao)
{
    return conexao->cidades;
}