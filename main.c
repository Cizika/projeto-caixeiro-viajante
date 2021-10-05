/* 
 * File:   main.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "TAD_Conexao/Conexao.h"
#include "TAD_Lista/Lista.h"

/*
 * 
 */
int main(int argc, char** argv) {

  //declaraçoes
  int n_cidades;
  int n_conexoes= 0;
  scanf(" %i", &n_cidades);
  CONEXAO **conexoes = (CONEXAO**)malloc(6*sizeof(CONEXAO*));
  int a,b,dist;
  printf(".\n");
  CONEXAO* con;
  for(int i=0;i<6;i++)
  {
    n_conexoes++;
    scanf(" %i %i %i", &a, &b, &dist);
    con = conexao_criar(dist, a, b);
    printf("$ %i %i %i\n", conexao_get_origem(con), conexao_get_destino(con), conexao_get_distancia(con));
    conexao_lista_add(conexoes,con,n_conexoes);
  }
  printf("%i.\n",n_conexoes);
  for(int i=0;i<6;i++)
  {
    printf(" %i %i %i\n", conexao_get_origem(conexoes[i]), conexao_get_destino(conexoes[i]), conexao_get_distancia(conexoes[i]));
  }
  printf(".\n");
  LISTA *lista = lista_criar();
  LISTA *validos = lista_criar();
  int *visitados = (int*)malloc(n_cidades*sizeof(int));
  for(int i=0;i<n_cidades;i++)
  {
    visitados[i] = -1;
  }
  printf(".\n");
  CAMINHO *caminho = caminho_criar(1, 0,visitados, 0);
  CAMINHO *filho;
  lista_inserir(lista, caminho);
  do
  {
    caminho = lista_dequeue(lista);
    printf("Abrindo caminho\n");
    print_caminho(caminho);
    caminho_visitar(caminho);
    for(int i=0;i<n_conexoes;i++)
    {
      if(conexao_get_origem(conexoes[i])==caminho_get_atual(caminho) && !caminho_visitado(caminho,conexao_get_destino(conexoes[i])))
      {
        filho = caminho_criar(conexao_get_destino(conexoes[i]),caminho_get_distancia(caminho)+conexao_get_distancia(conexoes[i]),caminho_get_visitados(caminho),caminho_get_tamanho(caminho));
        lista_inserir(lista,filho);
        printf("\tConexao em %i\n\t",conexao_get_destino(conexoes[i]));
        print_caminho(filho);
      }
      if(conexao_get_destino(conexoes[i])==caminho_get_atual(caminho) && !caminho_visitado(caminho,conexao_get_origem(conexoes[i])))
      {
        filho = caminho_criar(conexao_get_origem(conexoes[i]),caminho_get_distancia(caminho)+conexao_get_distancia(conexoes[i]),caminho_get_visitados(caminho),caminho_get_tamanho(caminho));
        lista_inserir(lista,filho);
        printf("\tConexao em %i\n\t",conexao_get_origem(conexoes[i]));
        print_caminho(filho);
      }
      if(conexao_get_origem(conexoes[i])==caminho_get_atual(caminho) && (caminho_get_tamanho(caminho)==n_cidades && conexao_get_destino(conexoes[i]) == 1))
      {
        filho = caminho_criar(conexao_get_destino(conexoes[i]),caminho_get_distancia(caminho)+conexao_get_distancia(conexoes[i]),caminho_get_visitados(caminho),caminho_get_tamanho(caminho));
        lista_inserir(validos,filho);
        print_caminho(filho);
      }
      if(conexao_get_destino(conexoes[i])==caminho_get_atual(caminho) && (caminho_get_tamanho(caminho)==n_cidades && conexao_get_origem(conexoes[i]) == 1))
      {
        filho = caminho_criar(conexao_get_origem(conexoes[i]),caminho_get_distancia(caminho)+conexao_get_distancia(conexoes[i]),caminho_get_visitados(caminho),caminho_get_tamanho(caminho));
        lista_inserir(validos,filho);
        print_caminho(filho);
      }
    }
    caminho_apagar(caminho);
  }while(!empty_list(lista));

  printf("\n\n");
  while(!empty_list(validos))
  {
    caminho = lista_dequeue(validos);
    for(int i=0;i<=n_cidades;i++) printf("%i ",caminho_get_visitados(caminho)[i]);
    printf("| %i",caminho_get_distancia(caminho));
    printf("\n");
  }

    return (EXIT_SUCCESS);
}

