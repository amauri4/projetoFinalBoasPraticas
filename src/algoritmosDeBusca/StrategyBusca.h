#ifndef STRATEGY_BUSCA_H
#define STRATEGY_BUSCA_H

#include <vector>

class StrategyBusca
{
public:
    /**
     * @brief Método virtual puro para busca em uma lista.
     *
     * @param lista Vetor de inteiros onde a busca será realizada.
     * @param valor O alvo a ser buscado na lista.
     * @param tamanho O tamanho da lista.
     * @return O índice onde o alvo se encontra, ou -1 caso não esteja presente.
     */
    virtual int buscar(const std::vector<int> &lista, int valor, int tamanho) = 0;

    virtual ~StrategyBusca() = default;
};

#endif // STRATEGY_BUSCA_H
