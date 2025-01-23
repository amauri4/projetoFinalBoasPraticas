#ifndef MEDICAO_DE_TEMPO_H
#define MEDICAO_DE_TEMPO_H

#include "../algoritmosDeBusca/StrategyBusca.h"
#include "../algoritmosDeOrdenacao/StrategyOrdenacao.h"
#include <chrono>
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>

class MedicaoDeTempo
{
public:
    /**
     * @brief Mede o tempo de execução de um algoritmo de busca.
     *
     * @param estrategia A estratégia de busca a ser utilizada.
     * @param lista O vetor onde será realizada a busca.
     * @param valor O valor a ser buscado.
     * @param tamanho O tamanho da lista.
     * @param exibirVetorNaSaida Determina se o vetor será escrito ou não no arquivo de saída.
     * @return Medição realizada
     */
    std::string medirBusca(std::unique_ptr<StrategyBusca> estrategia, std::vector<int> &lista, int valor,
                           int tamanho, bool exibirVetorNaSaida = false);

    /**
     * @brief Mede o tempo de execução de um algoritmo de ordenação.
     *
     * @param estrategia A estratégia de ordenação a ser utilizada.
     * @param vetor O vetor a ser ordenado.
     * @param tamanho O tamanho do vetor.
     * @param exibirVetorNaSaida Determina se o vetor será escrito ou não no arquivo de saída.
     * @return Medição realizada
     */
    std::string medirOrdenacao(std::unique_ptr<StrategyOrdenacao> estrategia, std::vector<int> &vetor,
                               int tamanho = -1, bool exibirVetorNaSaida = false);
};

#endif // MEDICAO_DE_TEMPO_H
