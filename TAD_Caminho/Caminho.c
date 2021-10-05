#include "Caminho.h"

#include <stdio.h>
#include <stdlib.h>

struct caminho
{
    int atual;
    int distancia;
    int visitados[12];
    int tamanho;
};

CAMINHO *caminho_criar(int atual, int distancia, int visitados[], int tamanho)
{
    CAMINHO *novo_caminho = (CAMINHO *)malloc(sizeof(CAMINHO));

    if (novo_caminho != NULL)
    {
        novo_caminho->atual = atual;
        novo_caminho->distancia = distancia;
        for(int i =0; i<tamanho; i++)
        {
          novo_caminho->visitados[i] = visitados[i];
        }
        novo_caminho->tamanho = tamanho;
        return novo_caminho;
    }
    exit(1);
}

void caminho_apagar(CAMINHO *caminho)
{
    if (caminho != NULL)
        free(caminho);
}


int caminho_get_atual(CAMINHO *caminho)
{
    return caminho->atual;
}

int caminho_get_distancia(CAMINHO *caminho)
{
    return caminho->distancia;
}

int *caminho_get_visitados(CAMINHO *caminho)
{
    return caminho->visitados;
}

void print_caminho(CAMINHO *caminho)
{
  for(int i=0;i<caminho->tamanho;i++)
  {
    printf("%i ",caminho->visitados[i]);
  }
  printf("%i\n",caminho->atual);
}

void caminho_visitar(CAMINHO *caminho)
{
  caminho->visitados[caminho->tamanho] = caminho->atual;
  caminho->tamanho++;
}

int caminho_visitado(CAMINHO *caminho, int a)
{
  for(int i=0;i<caminho->tamanho;i++)
  {
    if(caminho->visitados[i]==a) return 1;
  }
  return 0;
}

int caminho_get_tamanho(CAMINHO *caminho)
{
    return caminho->tamanho;
}