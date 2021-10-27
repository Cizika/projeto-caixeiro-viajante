#include "TAD_Lista/Lista.h"
#include <stdio.h>
#include <stdlib.h>

#define cidade_inicial 1

void calcular_caminho(CONEXOES *conexoes, CAMINHOS *caminhos);
int dist_menor = -1; // 1 operação primitiva (atribuição)
CAMINHOS *melhor_caminho = NULL; // 2 operações primitivas (atribuição e referência de ponteiro)
int n_cidades = 0; // 1 operação primitiva (atribuição)

int main()
{
    unsigned int cidade_a, cidade_b, distancia;

    scanf(" %i", &n_cidades); // 2 = 1 operação primitiva (referência) + 1 (função scanf)

    // Criando lista com todas as Conexões do Problema
    CONEXOES *conexoes = conexoes_criar(); // 14 = 2 operações primitivas (atribuição e referência de ponteiro) + 12 (função conexoes_criar)

    // Lendo as conexões até encontrar um EOF
    while (scanf(" %i %i %i", &cidade_a, &cidade_b, &distancia) != EOF) // 3(n_conexoes) = 3 operações primitivas (scanf, comparação e condição do while) * (n_conexoes)
        conexoes_inserir(conexoes, conexao_criar(distancia, cidade_a, cidade_b)); // 31(n_conexoes)  = (19 (função conexoes_inserir) + 12 (função conexao_criar))*(n_conexoes)

    // Criando Lista de Caminhos para testar todas as possibilidades (Força bruta)
    CAMINHOS *caminhos = caminhos_criar(); // 14 = 2 operações primitivas (atribuição e referência de ponteiro) + 12 (função caminhos_criar())

    // Armazenando a cidade de origem do problema na Pilha
    caminhos_inserir(caminhos, cidade_inicial, 0); // 29 (função caminhos_inserir)

    // Função recursiva para encontrar o melhor caminho (menor distância)
    calcular_caminho(conexoes, caminhos); // 54(n_cidades^3) + 104(n_cidades^2) - 266(n_cidades) - 298

    // Imprimindo a cidade de origem do Problema
    printf("%i\n", cidade_inicial); // 1 (função printf)

    // Imprimindo o Melhor Caminho
    caminhos_print(melhor_caminho); // 10(n_cidades) + 9

    // Imprimindo a distância total do Melhor Caminho
    printf("\n%i\n", dist_menor); // 1 (função printf)

    // Desalocando memória Heap
    conexoes_apagar(&conexoes); // 22(n_cidades) + 12 = 1 operação primitiva (referência) e 22(n_cidades) + 11 (função conexoes_apagar)
    caminhos_apagar(&caminhos); // 22(n_cidades) + 11 = 1 operação primitiva (referência) e 22(n_cidades) + 10 (função caminhos_apagar)
    caminhos_apagar(&melhor_caminho); // 22(n_cidades) + 11 = 1 operação primitiva (referência) e 22(n_cidades) + 10 (função caminhos_apagar)

    // Custo total = 54(n_cidades^3) + 121(n_cidades^2) - 207(n_cidades) - 190

    return (EXIT_SUCCESS);
}

void calcular_caminho(CONEXOES *conexoes, CAMINHOS *caminhos)
{
    CAMINHO *caminho_atual = caminhos_final(caminhos); // 4 = 2 operações primitivas (atribuição e referência de ponteiro) + 2 (função caminhos_final)
    unsigned int cidade_atual = caminho_get_ultima_cidade(caminho_atual); // 2 = 1 operação primitiva (atribuição) + 1 (função caminho_get_ultima_cidade)
    int distancia_total = caminho_get_distancia_total(caminho_atual); // 2 = 1 operação primitiva (atribuição) + 1 (função caminho_get_distancia_total)

    // Condição de parada => verifica se retornou à cidade de início da viagem
    if (cidade_atual == cidade_inicial && distancia_total != 0 && caminhos_tamanho(caminhos) == n_cidades + 1)  // 8 = 7 operações primitivas (condição, 5 comparações e soma) + 1 (função caminhos_tamanho)
    {
        if (dist_menor == -1 || distancia_total < dist_menor) // 4 operações primitivas (condição e 3 comparações)
        {
            if (melhor_caminho != NULL) // 2 operações primitivas (condição e comparação)
                caminhos_apagar(&melhor_caminho); // 22(n_cidades) + 11 = 1 operação primitiva (referência) e 22(n_cidades) + 10 (função caminhos_apagar)

            melhor_caminho = caminhos_copiar(caminhos); // 70(n_cidades) + 20 = 1 operação primitiva (atribuição) e 70(n_cidades) + 19 (função caminhos_copiar)
            dist_menor = distancia_total; // 1 operação primitiva (atribuição)
        }
        return;
    }

    CONEXAO **conexoes_envolvidas; // 2 operações primitivas (2 referência de ponteiro)
    int n_conexoes = conexoes_get_envolvidas(conexoes, cidade_atual, &conexoes_envolvidas); // 17(n_conexoes) - 3 = 2 operações primitivas (atribuição e referência) e 17(n_conexoes) - 5 (função conexoes_get_envolvidas)

    for (int i = 0; i < n_conexoes; i++) // 2(n_conexoes) - 1 = 1 operação primitiva (atribuição) + 2(n_conexoes - 1) (comparação e soma)
    {
        unsigned int origem = conexao_get_origem(conexoes_envolvidas[i]); // 3 = 2 operações primitivas (atribuição e vetor) + 1 (função conexao_get_origem)
        unsigned int destino = conexao_get_destino(conexoes_envolvidas[i]); // 3 = 2 operações primitivas (atribuição e vetor) + 1 (função conexao_get_destino)
        int distancia_somada = distancia_total + conexao_get_distancia(conexoes_envolvidas[i]); // 4 = 3 operações primitivas (atribuição, vetor e soma) + 1 (função conexao_get_distancia)

        // Verificando se a cidade atual está na origem da conexão e se seu destino ainda não foi visitado
        if (cidade_atual == origem && !caminhos_visitado(caminhos, destino)) // 12(n_cidades) + 9 = 4 operações primitivas (condição e 3 comparações) e 12(n_cidades) + 5 (função caminhos_visitado)
        {
            caminhos_inserir(caminhos, destino, distancia_somada); // 29 (função caminhos_inserir)
            calcular_caminho(conexoes, caminhos);
            caminhos_remover(caminhos); // 15(n_cidades) + 24 (função caminhos_remover)
        }

        // Verificando se a cidade atual está no destino da conexão e se sua origem ainda não foi visitada
        if (cidade_atual == destino && !caminhos_visitado(caminhos, origem)) // 12(n_cidades) + 9 = 4 operações primitivas (condição e 3 comparações) e 12(n_cidades) + 5 (função caminhos_visitado)
        {
            caminhos_inserir(caminhos, origem, distancia_somada); // 29 (função caminhos_inserir)
            calcular_caminho(conexoes, caminhos);
            caminhos_remover(caminhos); // 15(n_cidades) + 24 (função caminhos_remover)
        }

        // Verificando se a origem da conexão é novamente a cidade de início (Último caminho a ser adicionado)
        if (cidade_atual == origem && destino == cidade_inicial && caminhos_tamanho(caminhos) == n_cidades) // 7 = 6 operações primitivas (condição e 5 comparações) e 1 (função caminhos_tamanho)
        {
            caminhos_inserir(caminhos, destino, distancia_somada); // 29 (função caminhos_inserir)
            calcular_caminho(conexoes, caminhos);
            caminhos_remover(caminhos); // 15(n_cidades) + 24 (função caminhos_remover)
        }

        // Verificando se o destino da conexão é novamente a cidade de início (Último caminho a ser adicionado)
        if (cidade_atual == destino && origem == cidade_inicial && caminhos_tamanho(caminhos) == n_cidades) // 7 = 6 operações primitivas (condição e 5 comparações) e 1 (função caminhos_tamanho)
        {
            caminhos_inserir(caminhos, origem, distancia_somada); // 29 (função caminhos_inserir)
            calcular_caminho(conexoes, caminhos);
            caminhos_remover(caminhos); // 15(n_cidades) + 24 (função caminhos_remover)
        }
    }

    free(conexoes_envolvidas); // 1 (função free)
}