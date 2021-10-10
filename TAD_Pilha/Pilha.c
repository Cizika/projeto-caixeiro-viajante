#include <stdlib.h>
#include <stdio.h>
#include "Pilha.h"
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
    int tamanho;
};

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

void pilha_apagar(PILHA **pilha)
{
    NO* paux = malloc(sizeof(NO));
    if (*pilha != NULL && !pilha_vazia(*pilha))
    {
        while (pilha_tamanho(*pilha) != 0){
            paux->caminho = pilha_desempilhar(*pilha);
            caminho_apagar(&(paux->caminho));
        }
        free(*pilha);
    }
    free(paux);
}

int pilha_cheia(PILHA *pilha)
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

int pilha_vazia(PILHA *pilha)
{
    return ((pilha != NULL) ? pilha->tamanho <= 0 : ERRO);
}

int pilha_tamanho(PILHA *pilha)
{
    return ((pilha != NULL) ? pilha->tamanho : ERRO);
}

CAMINHO *pilha_topo(PILHA *pilha)
{
    CAMINHO *caminho = NULL;
    if (!pilha_vazia(pilha) && pilha != NULL)
        caminho = (pilha->TOPO)->caminho;
    return caminho;
}

int pilha_empilhar(PILHA *pilha, CAMINHO *caminho)
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

void pilha_print(PILHA *p)
{
    int tamanho = p->tamanho;
    CAMINHO **caminhos = (CAMINHO **)malloc(tamanho * sizeof(CAMINHO *));

    caminhos[0] = pilha_desempilhar(p);
    printf("%i", caminho_get_cidade_atual(caminhos[0]));

    for (int i = 1; i < tamanho; i++)
    {
        caminhos[i] = pilha_desempilhar(p);
        printf("-%i", caminho_get_cidade_atual(caminhos[i]));
    }

    for (int i = tamanho - 1; i >= 0; i--)
        pilha_empilhar(p, caminhos[i]);

    free(caminhos);
}

void pilha_inverter(PILHA *pilha)
{
    int tamanho = pilha_tamanho(pilha);
    CAMINHO **caminhos = (CAMINHO **)malloc(tamanho * sizeof(CAMINHO *));
    for (int i = 0; i < tamanho; i++)
        caminhos[i] = pilha_desempilhar(pilha);

    for (int i = 0; i < tamanho; i++)
        pilha_empilhar(pilha, caminhos[i]);
    
    free(caminhos);
}

unsigned int caminho_visitado(PILHA *pilha, int cidade)
{
    int tamanho = pilha->tamanho;
    unsigned int visitado = 0;
    CAMINHO **caminhos = (CAMINHO **)malloc(tamanho * sizeof(CAMINHO *));

    for (int i = 0; i < tamanho; i++)
    {
        caminhos[i] = pilha_desempilhar(pilha);
        if (caminho_get_cidade_atual(caminhos[i]) == cidade)
            visitado = 1;
    }

    for (int i = tamanho - 1; i >= 0; i--)
        pilha_empilhar(pilha, caminhos[i]);

    free(caminhos);

    return visitado;
}

PILHA *pilha_copiar(PILHA *pilha)
{
    PILHA *copia = pilha_criar();
    int tamanho = pilha_tamanho(pilha);
    CAMINHO **caminhos = (CAMINHO **)malloc(tamanho * sizeof(CAMINHO *));
    for (int i = 0; i < tamanho; i++)
        caminhos[i] = pilha_desempilhar(pilha);

    for (int i = tamanho - 1; i >= 0; i--)
    {
        pilha_empilhar(copia, caminho_criar(caminho_get_cidade_atual(caminhos[i]), caminho_get_distancia(caminhos[i])));
        pilha_empilhar(pilha, caminhos[i]);
    }
    free(caminhos);

    return copia;
}