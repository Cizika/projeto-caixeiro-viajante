#ifndef CONEXAO_H
#define CONEXAO_H

typedef struct conexao CONEXAO;

CONEXAO *conexao_criar(int distancia, unsigned int origem, unsigned int destino);
void conexao_apagar(CONEXAO **conexao);
int conexao_get_distancia(CONEXAO *conexao);
unsigned int conexao_get_destino(CONEXAO *conexao);
unsigned int conexao_get_origem(CONEXAO *conexao);

#endif