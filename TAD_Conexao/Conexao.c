#include "Conexao.h"

#include <stdio.h>
#include <stdlib.h>

struct conexao
{
    int distancia;
    unsigned int origem;
    unsigned int destino;
};

// Cria uma nova Conexão em memória com os argumentos passados
CONEXAO *conexao_criar(int distancia, unsigned int origem, unsigned int destino)
{
    CONEXAO *nova_conexao = (CONEXAO *)malloc(sizeof(CONEXAO));

    if (nova_conexao != NULL)
    {
        nova_conexao->distancia = distancia;
        nova_conexao->origem = origem;
        nova_conexao->destino = destino;
    }
    return nova_conexao;
}

// Apaga uma Conexão da memória
void conexao_apagar(CONEXAO **conexao)
{
    if (*conexao != NULL)
        free(*conexao);
}

// Retorna a distância de uma Conexão
int conexao_get_distancia(CONEXAO *conexao)
{
    return conexao->distancia;
}

// Retorna a cidade origem de uma Conexão
unsigned int conexao_get_origem(CONEXAO *conexao)
{
    return conexao->origem;
}

// Retorna a cidade destino de uma Conexão
unsigned int conexao_get_destino(CONEXAO *conexao)
{
    return conexao->destino;
}
