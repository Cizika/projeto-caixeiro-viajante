#ifndef CONEXAO_H
#define CONEXAO_H

typedef struct conexao CONEXAO;

CONEXAO *conexao_criar(int distancia, int origem, int destino);
CONEXAO **conexao_lista(int tamanho);
void conexao_lista_add(CONEXAO **lista, CONEXAO *conexao, int tamanho);
void conexao_apagar(CONEXAO *conexao);
int conexao_contem(CONEXAO *conexao, int a);
int conexao_get_distancia(CONEXAO *conexao);
int conexao_get_destino(CONEXAO *conexao);
int conexao_get_origem(CONEXAO *conexao);

#endif