#ifndef CAMINHO_H
#define CAMINHO_H

#include <stdio.h>

typedef struct caminho CAMINHO;

CAMINHO *caminho_criar(int cidade_atual, int distancia_total);
void caminho_apagar(CAMINHO **caminho);
int caminho_get_cidade_atual(CAMINHO *caminho);
int caminho_get_distancia(CAMINHO *caminho);

#endif