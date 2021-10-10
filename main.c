#include <stdio.h>
#include <stdlib.h>
#include "TAD_Conexao/Conexao.h"
// #include "TAD_Lista/Lista.h"
#include "TAD_Pilha/Pilha.h"

void calcular_caminho(CONEXAO **conexoes, PILHA *caminhos, int n_conexoes, int n_cidades, int cidade_inicial);
int dist_menor = -1;
PILHA *melhor_caminho = NULL;

int main()
{
  int cidade_a, cidade_b, distancia, n_cidades, n_conexoes = 0;

  scanf(" %i", &n_cidades);

  CONEXAO **conexoes = (CONEXAO **)malloc(6 * sizeof(CONEXAO *));

  // Tornar independente
  for (int i = 0; i < 6; i++)
  {
    scanf(" %i %i %i", &cidade_a, &cidade_b, &distancia);
    conexoes[i] = conexao_criar(distancia, cidade_a, cidade_b);
    n_conexoes++;
  }

  PILHA *caminhos = pilha_criar();
  int cidade_inicial = conexao_get_origem(conexoes[0]);
  pilha_empilhar(caminhos, caminho_criar(cidade_inicial, 0));

  // Encontrando o melhor caminho (menor distância)
  calcular_caminho(conexoes, caminhos, n_conexoes, n_cidades, cidade_inicial);

  // Invertendo a pilha do melhor caminho
  pilha_inverter(melhor_caminho);

  printf("%i\n", cidade_inicial);
  pilha_print(melhor_caminho);
  printf("\n%i\n", dist_menor);

  for (int i = 0; i < 6; i++)
    conexao_apagar(conexoes[i]);
  free(conexoes);

  pilha_apagar(&melhor_caminho);
  pilha_apagar(&caminhos);

  return (EXIT_SUCCESS);
}

void calcular_caminho(CONEXAO **conexoes, PILHA *caminhos, int n_conexoes, int n_cidades, int cidade_inicial)
{
  CAMINHO *caminho_atual = pilha_topo(caminhos);
  int cidade_atual = caminho_get_cidade_atual(caminho_atual);
  int distancia_total = caminho_get_distancia(caminho_atual);
  int p_tamanho = pilha_tamanho(caminhos);

  // Condição de parada => verifica se retornou à cidade de início da viagem
  if (cidade_atual == cidade_inicial && distancia_total != 0 && p_tamanho == n_cidades + 1)
  {
    if (dist_menor == -1 || distancia_total < dist_menor)
    {
      melhor_caminho = pilha_copiar(caminhos);
      dist_menor = distancia_total;
    }
    return;
  }

  // Iterando pelas conexões correspondentes
  for (int i = 0; i < n_conexoes; i++)
  {
    int origem = conexao_get_origem(conexoes[i]);
    int destino = conexao_get_destino(conexoes[i]);
    int distancia_somada = conexao_get_distancia(conexoes[i]) + distancia_total;

    // Verificando se a cidade atual está na origem da conexão e se seu destino ainda não foi visitado
    if (cidade_atual == origem && !caminho_visitado(caminhos, destino))
    {
      pilha_empilhar(caminhos, caminho_criar(destino, distancia_somada));
      calcular_caminho(conexoes, caminhos, n_conexoes, n_cidades, cidade_inicial);
      CAMINHO *caminho = pilha_desempilhar(caminhos);
      caminho_apagar(&caminho);
    }

    // Verificando se a cidade atual está no destino da conexão e se sua origem ainda não foi visitada
    if (cidade_atual == destino && !caminho_visitado(caminhos, origem))
    {
      pilha_empilhar(caminhos, caminho_criar(origem, distancia_somada));
      calcular_caminho(conexoes, caminhos, n_conexoes, n_cidades, cidade_inicial);
      CAMINHO *caminho = pilha_desempilhar(caminhos);
      caminho_apagar(&caminho);
    }

    // Verificando se a origem da conexão é novamente a cidade de início (Último caminho a ser adicionado)
    if (cidade_atual == origem && destino == cidade_inicial && pilha_tamanho(caminhos) == n_cidades)
    {
      pilha_empilhar(caminhos, caminho_criar(destino, distancia_somada));
      calcular_caminho(conexoes, caminhos, n_conexoes, n_cidades, cidade_inicial);
      CAMINHO *caminho = pilha_desempilhar(caminhos);
      caminho_apagar(&caminho);
    }

    // Verificando se o destino da conexão é novamente a cidade de início (Último caminho a ser adicionado)
    if (cidade_atual == destino && origem == cidade_inicial && pilha_tamanho(caminhos) == n_cidades)
    {
      pilha_empilhar(caminhos, caminho_criar(origem, distancia_somada));
      calcular_caminho(conexoes, caminhos, n_conexoes, n_cidades, cidade_inicial);
      CAMINHO *caminho = pilha_desempilhar(caminhos);
      caminho_apagar(&caminho);
    }
  }
}