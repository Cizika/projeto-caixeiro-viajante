#include "Caminho.h"

#include <stdio.h>
#include <stdlib.h>

struct caminho
{
  unsigned int ultima_cidade;
  int distancia_total;
};

// Cria um novo Caminho em memória com os argumentos passados
CAMINHO *caminho_criar(unsigned int ultima_cidade, int distancia_total)
{
  CAMINHO *novo_caminho = (CAMINHO *)malloc(sizeof(CAMINHO));
  if (novo_caminho != NULL)
  {
    novo_caminho->ultima_cidade = ultima_cidade;
    novo_caminho->distancia_total = distancia_total;
  }
  return novo_caminho;
}

// Apaga um Caminho da memória
void caminho_apagar(CAMINHO **caminho)
{
  if (*caminho != NULL)
    free(*caminho);
}

// Retorna a cidade atual de um Caminho
unsigned int caminho_get_ultima_cidade(CAMINHO *caminho)
{
  return caminho->ultima_cidade;
}

// Retorna a distância total até a última cidade de um caminho
int caminho_get_distancia_total(CAMINHO *caminho)
{
  return caminho->distancia_total;
}

// Imprime a última cidade do Caminho na saída padrão 
void caminho_print_ultima_cidade(CAMINHO *caminho)
{
  printf("-%i", caminho_get_ultima_cidade(caminho));
}
