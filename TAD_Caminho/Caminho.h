#ifndef CAMINHO_H
#define CAMINHO_H

#include <stdio.h>

typedef struct caminho CAMINHO;

CAMINHO *caminho_criar(int atual, int distancia, int visitados[], int tamanho);
void caminho_apagar(CAMINHO *caminho);
int caminho_get_atual(CAMINHO *caminho);
int caminho_get_distancia(CAMINHO *caminho);
int *caminho_get_visitados(CAMINHO *caminho);
void print_caminho(CAMINHO *caminho);
void caminho_visitar(CAMINHO *caminho);
int caminho_visitado(CAMINHO *caminho, int a);
int caminho_get_tamanho(CAMINHO *caminho);

#endif