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
CAMINHOS *caminhos_criar(void) // 12 (função caminhos_criar)
{
    CAMINHOS *lista = (CAMINHOS *)malloc(sizeof(CAMINHOS)); // 4 = 2 operações primitivas (atribuição e referência de ponteiro) + 2 (sizeof e malloc)
    if (lista != NULL) // 2 operações primitivas (condição e comparação)
    {
        lista->inicio = inicial; // 2 operações primitivas (atribuição e operador seta)
        lista->fim = NULL; // 2 operações primitivas (atribuição e operador seta)
        lista->tamanho = 0; // 2 operações primitivas (atribuição e operador seta)
    }
    return lista;
}

// Insere um Caminho no final da lista.
unsigned int caminhos_inserir(CAMINHOS *lista, unsigned int cidade, int distancia_total) // 29 (função caminhos_inserir)
{
    if (lista != NULL) // 2 operações primitivas (condição e comparação)
    {
        NO *pnovo = (NO *)malloc(sizeof(NO)); // 4 = 2 operações primitivas (atribuição e referência de ponteiro) + 2 (sizeof e malloc)
        pnovo->caminho = caminho_criar(cidade, distancia_total); // 12 = 2 operações primitivas (atribuição e operador seta) + 10 (função caminho_criar)
        if (lista->inicio == NULL) // 3 operações primitivas (condição, comparação e operador seta)
        {
            lista->inicio = pnovo; // 2 operações primitivas (atribuição e operador seta)
        }
        else
            lista->fim->proximo = pnovo; // 3 operações primitivas (atribuição e 2 operador seta)
        pnovo->proximo = NULL; // 2 operações primitivas (atribuição e operador seta)
        lista->fim = pnovo; // 2 operações primitivas (atribuição e operador seta)
        lista->tamanho++; // 2 operações primitivas (atribuição e soma)
        return 1;
    }
    return 0;
}

// Apaga a lista de caminhos e desaloca a memória utilizada
void caminhos_apagar(CAMINHOS **lista) // 22(n_cidades) + 10 (função caminhos_apagar)
{
    NO *no_atual = (*lista)->inicio; // 4 operações primitivas (atribuição, 2 referência de ponteiro e operador seta)
    NO *no_proximo = NULL; // 2 operações primitivas (atribuição e referência de ponteiro)
    if (lista != NULL) // 2 operações primitivas (condição e comparação)
    {
        while (no_atual != NULL) // 2(n_cidades) = 2 operações primitivas (condição e comparação) * n_cidades
        {
            caminho_apagar(&(no_atual->caminho)); // 7 = 2 operações primitivas (referência e operador seta) + 5 (função caminho_apagar)
            no_proximo = no_atual->proximo; // 2 operações primitivas (atribuição e operador seta)
            free(no_atual); // 1 (função free)
            no_atual = no_proximo; // 1 operação primitiva (atribuição)
        }
        free(*lista); // 2 = 1 operação primitiva (referência de ponteiro) + 1 (função free)
    }
}

// Retorna o tamanho da lista
int caminhos_tamanho(CAMINHOS *lista) // 1 (função caminhos_tamanho)
{
    return lista->tamanho; // 1 operação primitiva (operador seta)
}

// Verifica se a lista de cidades está vazia
unsigned int caminhos_vazia(CAMINHOS *lista)
{
    if (lista->inicio == NULL)
        return 1;
    return 0;
}

// Remove a última cidade visitada da lista de caminhos
unsigned int caminhos_remover(CAMINHOS *lista) // 15(n_cidades) + 24 (função caminhos_remover)
{
    if (lista != NULL) // 2 operações primitivas (condição e comparação)
    {
        NO *pro = lista->inicio; // 3 operações primitivas (atribuição, referência de ponteiro e operador seta)
        NO *ant = NULL; // 2 operações primitivas (atribuição e referência de ponteiro)
        while (pro != NULL && pro != lista->fim) // 5(n_cidades) = 5 operações primitivas (condição, 3 comparações e operador seta) * n_cidades
        {
            ant = pro; // 1 operação primitiva (atribuição)
            pro = pro->proximo; // 2 operações primitivas (atribuição e operador seta)
        }
        ant->proximo = pro->proximo; // 3 operações primitivas (atribuição e 2 operador seta)
        pro->proximo = NULL; // 2 operações primitivas (atribuição e operador seta)
        lista->fim = ant; // 2 operações primitivas (atribuição e operador seta)
        lista->tamanho--; // 2 operações primitivas (operador seta e subtração)
        caminho_apagar(&(pro->caminho)); // 7 = 2 operações primitivas (referência e operador seta) + 5 (função caminho_apagar)
        free(pro); // 1 (função free)
        return 0;
    }
    return 1;
}

// Busca iterativamente por uma cidade na lista de caminhos
BOOLEAN caminhos_visitado(CAMINHOS *lista, unsigned int cidade)
{
    NO *no_atual = lista->inicio; // 3 operações primitivas (atribuição, referência de ponteiro e operador seta)
    if (lista != NULL) // 2 operações primitivas (condição e comparação)
    {
        while (no_atual != NULL) // 2(n_cidades) = 2 operações primitivas (condição e comparação) * (n_cidades)
        {
            if (caminho_get_ultima_cidade(no_atual->caminho) == cidade) // 4 = 3 operações primitivas (condição, comparação e operador seta) + 1 (função caminho_get_ultima_cidade)
                return 1;
            no_atual = no_atual->proximo; // 2 operações primitivas (atribuição e operador seta)
        }
    }
    return 0;
}

// Retorna o último caminho dentro da lista (última cidade visitada)
CAMINHO *caminhos_final(CAMINHOS *lista) // 2 (função caminhos_final)
{
    return lista->fim->caminho; // 2 operações primitivas (2 operador seta)
}

// Copia uma lista caminhos para outra
CAMINHOS *caminhos_copiar(CAMINHOS *lista) // 70(n_cidades) + 19 (função caminhos_copiar)
{
    CAMINHOS *nova_lista = caminhos_criar(); // 14 = 2 operações primitivas (atribuição e referência de ponteiro) + 12 (função caminhos_criar)
    NO *no_atual = lista->inicio; // 3 operações primitivas (atribuição, referência de ponteiro e operador seta)
    if (lista != NULL) // 2 operações primitivas (condição e comparação)
    {
        while (no_atual != NULL) // 2(n_cidades) = 2 operações primitivas (condição e comparação) * n_cidades
        {
            caminhos_inserir(nova_lista, caminho_get_ultima_cidade(no_atual->caminho), caminho_get_distancia_total(no_atual->caminho)); // 33 = 29 (caminhos_inserir) + 2 operações primitivas (operador seta) + 2 (funções caminho_get_ultima_cidade e caminho_get_distancia_total)
            no_atual = no_atual->proximo; // 2 operações primitivas (atribuição e operador seta)
        }
    }
    return nova_lista;
}

// Imprime todas as cidades visitadas nos Caminhos
void caminhos_print(CAMINHOS *lista) // 10(n_cidades) + 9 (função caminhos_print)
{
    NO *no_atual = lista->inicio; // 3 operações primitivas (atribuição, referência de ponteiro e operador seta)

    printf("%i", caminho_get_ultima_cidade(no_atual->caminho)); // 2 (funções printf e caminho_get_ultima_cidade)
    no_atual = no_atual->proximo; // 2 operações primitivas (atribuição e operador seta)

    if (lista != NULL) // 2 operações primitivas (condição e comparação)
    {
        while (no_atual != NULL) // 2(n_cidades) = 2 operações primitivas (condição e comparação) * n_cidades
        {
            caminho_print_ultima_cidade(no_atual->caminho); // 3 = 1 operação primitiva (operador seta) + 2 (função caminho_print_ultima_cidade)
            no_atual = no_atual->proximo; // 2 operações primitivas (atribuição e operador seta)
        }
    }
}