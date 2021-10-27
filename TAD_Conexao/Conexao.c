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
CONEXAO *conexao_criar(int distancia, unsigned int origem, unsigned int destino) // 12 (função conexao_criar)
{
    CONEXAO *nova_conexao = (CONEXAO *)malloc(sizeof(CONEXAO)); // 4 = 2 operações primitivas (atribuição e referência de ponteiro) + 2 (sizeof e malloc)

    if (nova_conexao != NULL) // 2 operações primitivas (condição e comparação)
    {
        nova_conexao->distancia = distancia; // 2 operações primitivas (atribuição e operador seta)
        nova_conexao->origem = origem; // 2 operações primitivas (atribuição e operador seta)
        nova_conexao->destino = destino; // 2 operações primitivas (atribuição e operador seta)
    }
    return nova_conexao;
}

// Apaga uma Conexão da memória
void conexao_apagar(CONEXAO **conexao)
{
    if (*conexao != NULL) // 3 operações primitivas (condição, comparação e referência de ponteiro)
        free(*conexao); // 2 = 1 operação primitiva (referência de ponteiro) + 1 (função free)
}

// Retorna a distância de uma Conexão
int conexao_get_distancia(CONEXAO *conexao)
{
    return conexao->distancia; // 1 operação primitiva (operador seta)
}

// Retorna a cidade origem de uma Conexão
unsigned int conexao_get_origem(CONEXAO *conexao)
{
    return conexao->origem; // 1 operação primitiva (operador seta)
}

// Retorna a cidade destino de uma Conexão
unsigned int conexao_get_destino(CONEXAO *conexao)
{
    return conexao->destino; // 1 operação primitiva (operador seta)
}
