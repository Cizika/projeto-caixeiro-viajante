#ifndef CONEXAO_H
#define CONEXAO_H

typedef struct conexao CONEXAO;

CONEXAO *conexao_criar(int distancia, int cidadeA, int cidadeB);
void conexao_apagar(CONEXAO *conexao);
int conexao_get_distancia(CONEXAO *conexao);
int *conexao_get_cidades(CONEXAO *conexao);

#endif