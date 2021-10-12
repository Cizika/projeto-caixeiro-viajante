#include "Pilha.h"

#include <stdlib.h>
#include <stdio.h>
#include "../TAD_Caminho/Caminho.h"

struct no typedef NO;

struct no
{
    CAMINHO *caminho;
    NO *anterior;
};

struct pilha
{
    NO *TOPO;
    unsigned int tamanho;
};

// Cria e retorna uma Pilha Encadeada de Caminhos
PILHA *pilha_criar()
{
    PILHA *pilha = (PILHA *)malloc(sizeof(PILHA));
    if (pilha != NULL)
    {
        pilha->tamanho = 0;
        pilha->TOPO = NULL;
    }
    return pilha;
}

// Apaga em memória uma Pilha de Caminhos
void pilha_apagar(PILHA **pilha)
{
    NO *paux = malloc(sizeof(NO));
    if (*pilha != NULL && !pilha_vazia(*pilha))
    {
        while (pilha_tamanho(*pilha) != 0)
        {
            paux->caminho = pilha_desempilhar(*pilha);
            caminho_apagar(&(paux->caminho));
        }
    }
    free(*pilha);
    free(paux);
}

// Insere um novo Caminho no Topo da Pilha, retornando o status da operação
unsigned int pilha_empilhar(PILHA *pilha, CAMINHO *caminho)
{
    NO *novo_no = (NO *)malloc(sizeof(NO));
    if (novo_no != NULL)
    {
        novo_no->caminho = caminho;
        novo_no->anterior = pilha->TOPO;
        pilha->TOPO = novo_no;
        (pilha->tamanho)++;
        return 1;
    }
    return 0;
}

// Retorna o Caminho no Topo, removendo-o da Pilha
CAMINHO *pilha_desempilhar(PILHA *pilha)
{
    CAMINHO *caminho = NULL;
    if (!pilha_vazia(pilha) && pilha != NULL)
    {
        NO *no = pilha->TOPO;
        caminho = pilha_topo(pilha);
        pilha->TOPO = (pilha->TOPO)->anterior;
        no->anterior = NULL;
        free(no);
        no = NULL;
        pilha->tamanho--;
    }
    return caminho;
}

// Retorna o Caminho no Topo da Pilha
CAMINHO *pilha_topo(PILHA *pilha)
{
    CAMINHO *caminho = NULL;
    if (!pilha_vazia(pilha) && pilha != NULL)
        caminho = (pilha->TOPO)->caminho;
    return caminho;
}

// Verifica se a Pilha está cheia
unsigned int pilha_cheia(PILHA *pilha)
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

// Verifica se a Pilha está vazia
int pilha_vazia(PILHA *pilha)
{
    return ((pilha != NULL) ? pilha->tamanho == 0 : ERRO);
}

// Retorna o tamanho da Pilha
int pilha_tamanho(PILHA *pilha)
{
    return ((pilha != NULL) ? pilha->tamanho : ERRO);
}

// Retorna uma cópia de uma Pilha
PILHA *pilha_copiar(PILHA *pilha)
{
    PILHA *copia = pilha_criar();
    unsigned int tamanho = pilha_tamanho(pilha);
    CAMINHO **caminhos = (CAMINHO **)malloc(tamanho * sizeof(CAMINHO *));

    for (int i = 0; i < tamanho; i++)
        caminhos[i] = pilha_desempilhar(pilha);

    for (int i = tamanho - 1; i >= 0; i--)
    {
        pilha_empilhar(copia, caminho_criar(caminho_get_ultima_cidade(caminhos[i]), caminho_get_distancia_total(caminhos[i])));
        pilha_empilhar(pilha, caminhos[i]);
    }
    free(caminhos);

    return copia;
}

// Imprime a Pilha na saída padrão
void pilha_print(PILHA *p)
{
    unsigned int tamanho = pilha_tamanho(p);
    PILHA *copia = pilha_copiar(p);

    CAMINHO *caminho_inicial = pilha_desempilhar(copia);
    printf("%i", caminho_get_ultima_cidade(caminho_inicial));
    caminho_apagar(&caminho_inicial);

    for (int i = 1; i < tamanho; i++)
    {
        CAMINHO *caminho_atual = pilha_desempilhar(copia);
        caminho_print_ultima_cidade(caminho_atual);
        caminho_apagar(&caminho_atual);
    }

    pilha_apagar(&copia);
}

// Inverte uma Pilha
void pilha_inverter(PILHA *pilha)
{
    unsigned int tamanho = pilha_tamanho(pilha);
    CAMINHO **caminhos = (CAMINHO **)malloc(tamanho * sizeof(CAMINHO *));

    for (int i = 0; i < tamanho; i++)
        caminhos[i] = pilha_desempilhar(pilha);

    for (int i = 0; i < tamanho; i++)
        pilha_empilhar(pilha, caminhos[i]);

    free(caminhos);
}

// Verifica se um Caminho já foi visitado, isto é, já está dentro da Pilha
unsigned int caminho_visitado(PILHA *pilha, unsigned int cidade)
{
    unsigned int tamanho = pilha_tamanho(pilha);
    unsigned int visitado = 0;
    PILHA *copia = pilha_copiar(pilha);

    for (int i = 0; i < tamanho; i++)
    {
        CAMINHO *caminho_atual = pilha_desempilhar(copia);
        if (caminho_get_ultima_cidade(caminho_atual) == cidade)
            visitado = 1;
        caminho_apagar(&caminho_atual);
    }

    pilha_apagar(&copia);

    return visitado;
}
