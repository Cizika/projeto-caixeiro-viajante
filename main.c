#include <stdio.h>
#include <stdlib.h>
#include "Conexao.h"
#include "Lista.h"

int main(){
    LISTA* lista_teste = lista_criar();
    CONEXAO* conexao1 = conexao_criar(1, 1, 2);
    CONEXAO* conexao2 = conexao_criar(1, 2, 3);
    lista_inserir(lista_teste, conexao1);
    lista_inserir(lista_teste, conexao2);
    int teste = conexao_get_distancia(lista_busca(lista_teste, 2, 1));
    printf("Distancia: %i\n", teste);
    lista_apagar(&lista_teste);
    return 0;
}