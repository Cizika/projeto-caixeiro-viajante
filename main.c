#include "TAD_Lista/Lista.h"
#include <stdio.h>
#include <stdlib.h>

#define cidade_inicial 1

void calcular_caminho(CONEXOES *conexoes, CAMINHOS *caminhos);
int dist_menor = -1;
CAMINHOS *melhor_caminho = NULL;
int n_cidades = 0;

int main()
{
  unsigned int cidade_a, cidade_b, distancia;

  scanf(" %i", &n_cidades);

  // Criando lista com todas as Conexões do Problema
  CONEXOES *conexoes = conexoes_criar();

  // Lendo as conexões até encontrar um EOF
  while (scanf(" %i %i %i", &cidade_a, &cidade_b, &distancia) != EOF)
    conexoes_inserir(conexoes, conexao_criar(distancia, cidade_a, cidade_b));

  // Criando Lista de Caminhos para testar todas as possibilidades (Força bruta)
  CAMINHOS *caminhos = caminhos_criar();

  // Armazenando a cidade de origem do problema na Pilha
  caminhos_inserir(caminhos, cidade_inicial, 0);

  // Função recursiva para encontrar o melhor caminho (menor distância)
  calcular_caminho(conexoes, caminhos);

  // Imprimindo a cidade de origem do Problema
  printf("%i\n", cidade_inicial);

  // Imprimindo o Melhor Caminho
  caminhos_print(melhor_caminho);

  // Imprimindo a distância total do Melhor Caminho
  printf("\n%i\n", dist_menor);

  // Desalocando memória Heap
  conexoes_apagar(&conexoes);
  caminhos_apagar(&caminhos);
  caminhos_apagar(&melhor_caminho);

  return (EXIT_SUCCESS);
}

void calcular_caminho(CONEXOES *conexoes, CAMINHOS *caminhos)
{
  CAMINHO *caminho_atual = caminhos_final(caminhos);
  unsigned int cidade_atual = caminho_get_ultima_cidade(caminho_atual);
  int distancia_total = caminho_get_distancia_total(caminho_atual);

  // Condição de parada => verifica se retornou à cidade de início da viagem
  if (cidade_atual == cidade_inicial && distancia_total != 0 && caminhos_tamanho(caminhos) == n_cidades + 1)
  {
    if (dist_menor == -1 || distancia_total < dist_menor)
    {
      if (melhor_caminho != NULL)
        caminhos_apagar(&melhor_caminho);

      melhor_caminho = caminhos_copiar(caminhos);
      dist_menor = distancia_total;
    }
    return;
  }

  CONEXAO **conexoes_envolvidas;
  int n_conexoes = conexoes_get_envolvidas(conexoes, cidade_atual, &conexoes_envolvidas);

  for (int i = 0; i < n_conexoes; i++)
  {
    unsigned int origem = conexao_get_origem(conexoes_envolvidas[i]);
    unsigned int destino = conexao_get_destino(conexoes_envolvidas[i]);
    int distancia_somada = distancia_total + conexao_get_distancia(conexoes_envolvidas[i]);

    // Verificando se a cidade atual está na origem da conexão e se seu destino ainda não foi visitado
    if (cidade_atual == origem && !caminhos_visitado(caminhos, destino))
    {
      caminhos_inserir(caminhos, destino, distancia_somada);
      calcular_caminho(conexoes, caminhos);
      caminhos_remover(caminhos);
    }

    // Verificando se a cidade atual está no destino da conexão e se sua origem ainda não foi visitada
    if (cidade_atual == destino && !caminhos_visitado(caminhos, origem))
    {
      caminhos_inserir(caminhos, origem, distancia_somada);
      calcular_caminho(conexoes, caminhos);
      caminhos_remover(caminhos);
    }

    // Verificando se a origem da conexão é novamente a cidade de início (Último caminho a ser adicionado)
    if (cidade_atual == origem && destino == cidade_inicial && caminhos_tamanho(caminhos) == n_cidades)
    {
      caminhos_inserir(caminhos, destino, distancia_somada);
      calcular_caminho(conexoes, caminhos);
      caminhos_remover(caminhos);
    }

    // Verificando se o destino da conexão é novamente a cidade de início (Último caminho a ser adicionado)
    if (cidade_atual == destino && origem == cidade_inicial && caminhos_tamanho(caminhos) == n_cidades)
    {
      caminhos_inserir(caminhos, origem, distancia_somada);
      calcular_caminho(conexoes, caminhos);
      caminhos_remover(caminhos);
    }
  }

  free(conexoes_envolvidas);
}