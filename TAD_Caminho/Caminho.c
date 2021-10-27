#include "Caminho.h"

#include <stdio.h>
#include <stdlib.h>

struct caminho
{
    unsigned int ultima_cidade;
    int distancia_total;
};

// Cria um novo Caminho em memória com os argumentos passados
CAMINHO *caminho_criar(unsigned int ultima_cidade, int distancia_total) // 10 (função caminho_criar)
{
    CAMINHO *novo_caminho = (CAMINHO *)malloc(sizeof(CAMINHO)); // 4 = 2 operações primitivas (atribuição e referência de ponteiro) + 2 (sizeof e malloc)
    if (novo_caminho != NULL) // 2 operações primitivas (condição e comparação)
    {
        novo_caminho->ultima_cidade = ultima_cidade; // 2 operações primitivas (atribuição e operador seta)
        novo_caminho->distancia_total = distancia_total; // 2 operações primitivas (atribuição e operador seta)
    }
    return novo_caminho;
}

// Apaga um Caminho da memória
void caminho_apagar(CAMINHO **caminho) // 5 (função caminho_apagar)
{
    if (*caminho != NULL) // 3 operações primitivas (condição, comparação e referência de ponteiro)
        free(*caminho); // 2 = 1 operação primitiva (referência de ponteiro) + 1 (função free)
}

// Retorna a cidade atual de um Caminho
unsigned int caminho_get_ultima_cidade(CAMINHO *caminho) // 1 (função caminho_get_ultima_cidade)
{
    return caminho->ultima_cidade; // 1 operação primitiva (operador seta)
}

// Retorna a distância total até a última cidade de um caminho
int caminho_get_distancia_total(CAMINHO *caminho) // 1 (função caminho_get_distancia_total)
{
    return caminho->distancia_total; // 1 operação primitiva (operador seta)
}

// Imprime a última cidade do Caminho na saída padrão
void caminho_print_ultima_cidade(CAMINHO *caminho)
{
    printf("-%i", caminho_get_ultima_cidade(caminho)); // 2 (funções printf e caminho_get_ultima_cidade)
}
