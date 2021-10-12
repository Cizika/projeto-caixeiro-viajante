#ifndef CAMINHO_H
#define CAMINHO_H

typedef struct caminho CAMINHO;

CAMINHO *caminho_criar(unsigned int ultima_cidade, int distancia_total);
void caminho_apagar(CAMINHO **caminho);
unsigned int caminho_get_ultima_cidade(CAMINHO *caminho);
int caminho_get_distancia_total(CAMINHO *caminho);
void caminho_print_ultima_cidade(CAMINHO* caminho);

#endif