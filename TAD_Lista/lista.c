#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

struct lista_
{
    CONEXAO *lista[TAMANHO];
    int inicio; // inicio da lista
    int fim;    // fim da lista - primeira posição livre para inserção
};

LISTA *lista_criar(void)
{
    LISTA *lista = (LISTA *)malloc(sizeof(LISTA));
    if (lista != NULL)
    {
        lista->inicio = inicial;
        lista->fim = lista->inicio; // Lista vazia
    }
    return lista;
}

// Insere um elemento no fim da lista.
int lista_inserir(LISTA *lista, CONEXAO *conexao)
{
    if (!lista_cheia(lista) && lista != NULL)
    {
        lista->lista[lista->fim] = conexao;
        lista->fim++;
        return 1;
    }
    return 0;
}

// Insere um elemento em determinada posição.
int lista_inserir_posicao(LISTA *lista, int pos, CONEXAO *conexao)
{
    if (!lista_cheia(lista) && (pos <= lista->fim - 1))
    {
        // Movendo itens
        for (int i = lista->fim; i > pos; i--)
            lista->lista[i] = lista->lista[i - 1];
        lista->lista[pos] = conexao; // Insere nova conexão
        lista->fim++;                // Incrementa o tamanho
        return 1;
    }
    return 0;
}

// Apaga a lista e desaloca memória
int lista_apagar(LISTA **lista)
{
    for (int i = (*lista)->inicio; i < (*lista)->fim; i++)
    {
        free((*lista)->lista[i]);
    }
    free(*lista);
}

// Busca Sequencial por uma conexao
CONEXAO *lista_busca(LISTA *lista, int origem, int destino)
{
    for (int i = 0; i < TAMANHO; i++)
    {
        if (conexao_get_origem(lista->lista[i]) == origem &&
            conexao_get_destino(lista->lista[i]) == destino)
            return lista->lista[i];
    }
    return NULL;
}

// Remove conexão no final da lista
int lista_remover(LISTA *lista)
{
    if (!lista_vazia(lista) && lista != NULL)
    {
        lista->lista[lista->fim] = NULL;
        lista->fim--;
        return 1;
    }
    return 0;
}

// Verifica se a lista está cheia
int lista_cheia(LISTA *lista)
{
    return lista->fim == TAMANHO;
}

// Verifica se a lista está vazia
int lista_vazia(LISTA *lista)
{
    return lista->fim == lista->inicio;
}