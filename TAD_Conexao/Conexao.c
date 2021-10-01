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

void conexao_apagar(CONEXAO **conexao)
{
    if (conexao != NULL)
        free(*conexao);
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