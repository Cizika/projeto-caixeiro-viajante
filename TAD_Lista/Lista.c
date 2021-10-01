#include <stdlib.h>
#include <stdio.h>
#include "Lista.h"
#include "Conexao.h"

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
    if ((!lista_cheia(lista)) && (lista != NULL))
    {
        NO *pnovo = (NO *)malloc(sizeof(NO));
        pnovo->conexao = conexao;
        if (lista->inicio == NULL)
            lista->inicio = pnovo;
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

// Insere uma conexão em determinada posição.
int lista_inserir_posicao(LISTA *lista, int pos, CONEXAO *conexao)
{
    NO *pro = lista->inicio;
    NO *ant = NULL;
    if (lista != NULL && lista_tamanho(lista) > pos)
    {
        NO *pnovo = (NO *)malloc(sizeof(NO));
        pnovo->conexao = conexao;
        for (int i = 0; i < pos; i++)
        {
            ant = pro;
            pro = pro->proximo;
        }

        ant->proximo = pnovo;
        pnovo->proximo = pro;
        return 1;
    }
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

// Busca por uma conexao
CONEXAO *lista_busca(LISTA *lista, int origem, int destino)
{
    NO *no_atual = lista->inicio;
    if (lista != NULL)
    {
        while (no_atual != NULL)
        {
            if ((conexao_get_origem(no_atual->conexao) == destino && conexao_get_destino(no_atual->conexao) == origem) ||
                (conexao_get_origem(no_atual->conexao) == origem && conexao_get_destino(no_atual->conexao) == destino))
                return no_atual->conexao;
            no_atual = no_atual->proximo;
        }
    }
    return NULL;
}

// Remove conexão no final da lista
int lista_remover(LISTA *lista, int destino, int origem)
{
    if (lista != NULL)
    {
        NO *pro = lista->inicio;
        NO *ant = NULL;
        while (pro != NULL && (conexao_get_destino(pro->conexao) != destino || conexao_get_origem(pro->conexao) != origem))
        {
            ant = pro;
            pro = pro->proximo;
        }

        if (pro != NULL)
        {
            if (pro == lista->inicio)
            {
                lista->inicio = pro->proximo;
                pro->proximo = NULL;
            }
            else
            {
                ant->proximo = pro->proximo;
                pro->proximo = NULL;
            }
            if (pro == lista->fim)
                lista->fim = ant;
            lista->tamanho--;
            free(pro);
            return 1;
        }
    }
    return 0;
}

// Verifica se a lista está cheia
int lista_cheia(LISTA *lista)
{
    NO *n = (NO *)malloc(sizeof(NO));
    if (n != NULL)
    {
        free(n);
        n = NULL;
        return 0;
    }
    return 1;
}

// Retorna o tamanho da lista
int lista_tamanho(LISTA *lista)
{
    return lista->tamanho;
}

// Verifica se a lista está vazia
int lista_vazia(LISTA *lista)
{
    return ((lista != NULL) ? lista->tamanho <= 0 : ERRO);
}