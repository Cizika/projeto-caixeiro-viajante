#include "Caminho.h"

#include <stdio.h>
#include <stdlib.h>

struct caminho
{
  int cidade_atual;
  int distancia_total;
};

CAMINHO *caminho_criar(int cidade_inicial, int distancia_total)
{
  CAMINHO *novo_caminho = (CAMINHO *)malloc(sizeof(CAMINHO));

  if (novo_caminho != NULL)
  {
    novo_caminho->cidade_atual = cidade_inicial;
    novo_caminho->distancia_total = distancia_total;
    return novo_caminho;
  }
  exit(1);
}

void caminho_apagar(CAMINHO **caminho)
{
  if (*caminho != NULL)
    free(*caminho);
}

int caminho_get_cidade_atual(CAMINHO *caminho)
{
  return caminho->cidade_atual;
}

int caminho_get_distancia(CAMINHO *caminho)
{
  return caminho->distancia_total;
}