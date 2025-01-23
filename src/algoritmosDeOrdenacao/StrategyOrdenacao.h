#ifndef STRATEGY_ORDENACAO_H
#define STRATEGY_ORDENACAO_H

#include <vector>

/**
 * @brief Classe abstrata que define a interface para algoritmos de ordenação.
 *
 * A classe `StrategyOrdenacao` serve como base para diferentes estratégias de ordenação. Ela define
 * o método virtual puro `ordenar`, que deve ser implementado pelas classes derivadas para realizar
 * a ordenação de um vetor de inteiros de acordo com o algoritmo específico.
 */
class StrategyOrdenacao
{
public:
    /**
     * @brief Ordena um vetor de inteiros.
     *
     * Este método é implementado pelas classes derivadas para ordenar o vetor de acordo com o
     * algoritmo específico. O tamanho do vetor pode ser passado como argumento ou ser inferido
     * automaticamente dependendo do algoritmo.
     *
     * @param vetor O vetor a ser ordenado.
     * @param tamanho (Opcional) O tamanho do vetor, usado por certos algoritmos. O valor padrão é -1.
     */
    virtual void ordenar(std::vector<int> &vetor, int tamanho = -1) = 0;

    /**
     * @brief Destruidor virtual da classe base.
     *
     * O destruidor é virtual para garantir que o destruidor das classes derivadas seja chamado corretamente
     * quando um objeto da classe derivada for deletado através de um ponteiro para a classe base.
     */
    virtual ~StrategyOrdenacao() = default;
};

#endif // STRATEGY_ORDENACAO_H
