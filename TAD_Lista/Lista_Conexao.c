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
CONEXOES *conexoes_criar(void) // 12 (função conexoes_criar)
{
    CONEXOES *lista = (CONEXOES *)malloc(sizeof(CONEXOES)); // 4 = 2 operações primitivas (atribuição e referência de ponteiro) + 2 (funções sizeof e malloc)
    if (lista != NULL) // 2 operações primitivas (condição e comparação)
    {
        lista->inicio = inicial; // 2 operações primitivas (atribuição e operador seta)
        lista->fim = NULL; // 2 operações primitivas (atribuição e operador seta)
        lista->tamanho = 0; // 2 operações primitivas (atribuição e operador seta)
    }
    return lista;
}

// Insere uma conexão no fim da lista.
BOOLEAN conexoes_inserir(CONEXOES *lista, CONEXAO *conexao) // 19 (função conexoes_inserir)
{
    if (lista != NULL) // 2 operações primitivas (condição e comparação)
    {
        NO *pnovo = (NO *)malloc(sizeof(NO)); // 4 = 2 operações primitivas (atribuição e referência de ponteiro) + 2 (sizeof e malloc)
        pnovo->conexao = conexao; // 2 operações primitivas (atribuição e operador seta)
        if (lista->inicio == NULL) // 3 operações primitivas (condição, comparação e operador seta)
        {
            lista->inicio = pnovo; // 2 operações primitivas (atribuição e operador seta)
        }
        else
            lista->fim->proximo = pnovo; // 3 operações primitivas (2 operador seta + atribuição)
        pnovo->proximo = NULL; // 2 operações primitivas (atribuição e operador seta)
        lista->fim = pnovo; // 2 operações primitivas (atribuição e operador seta)
        lista->tamanho++; // 2 operações primitivas (atribuição e soma)
        return 1;
    }
    else
        return 0;
}

// Apaga a lista e desaloca memória
void conexoes_apagar(CONEXOES **lista) // 22(n_cidades) + 11 (função conexoes_apagar)
{
    NO *no_atual = (*lista)->inicio; // 4 operações primitivas (atribuição, 2 referência de ponteiro e operador seta)
    NO *no_proximo = NULL; // 3 operações primitivas (atribuição, referência de ponteiro e operador seta)
    if (lista != NULL) // 2 operações primitivas (condição e comparação)
    {
        while (no_atual != NULL) // 2(n_cidades) = 2 operações primitivas (condição e comparação) * n_cidades
        {
            conexao_apagar(&(no_atual->conexao)); // 7 = 2 operações primitivas (referência e operador seta) + 5 (função conexao_apagar)
            no_proximo = no_atual->proximo; // 2 operações primitivas (atribuição e operador seta)
            free(no_atual); // 1 (função free)
            no_atual = no_proximo; // 1 operação primitiva (atribuição)
        }
        free(*lista); // 2 = 1 operação primitiva (referência de ponteiro) + 1 (função free)
    }
}

// Retorna as conexões que envolvem a cidade fornecida
int conexoes_get_envolvidas(CONEXOES *lista, unsigned int cidade, CONEXAO ***conexoes_envolvidas) // 17(n_conexoes) - 5 (função conexoes_get_envolvidas)
{
    NO *atual = lista->inicio; // 3 operações primitivas (atribuição, referência de ponteiro e operador seta)
    int tamanho = lista->tamanho; // 2 operações primitivas (atribuição e operador seta)
    *conexoes_envolvidas = (CONEXAO **)malloc(tamanho * sizeof(CONEXAO *)); // 5 = 3 operações primitivas (atribuição, referência de ponteiro e multiplicação) + 2 (malloc e sizeof)

    int num_conexoes = 0; // 1 operação primitiva (atribuição)

    for (int i = 0; i < tamanho; i++) // 2(n_conexoes) - 1 = 1 operação primitiva (atribuição) + 2(n_conexoes - 1) (comparação e soma)
    {
        if (conexao_get_origem(atual->conexao) == cidade || conexao_get_destino(atual->conexao) == cidade) // 8 = 6 operações primitivas (condição, 3 comparações e 2 operador seta) + 2 (funções conexao_get_origem e conexao_get_destino)
            (*conexoes_envolvidas)[num_conexoes++] = atual->conexao; // 5 operações primitivas (referência de ponteiro, soma, vetor, atribuição e operador seta)
        atual = atual->proximo; // 2 operações primitivas (atribuição e operador seta)
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