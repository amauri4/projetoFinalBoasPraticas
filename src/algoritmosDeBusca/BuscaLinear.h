#ifndef BUSCA_LINEAR_H
#define BUSCA_LINEAR_H

#include "StrategyBusca.h"

class BuscaLinear : public StrategyBusca
{
public:
    /**
     * @brief Implementação da busca Linear.
     *
     * @param lista Vetor de inteiros onde a busca será realizada.
     * @param valor O alvo a ser buscado na lista.
     * @param tamanho O tamanho da lista.
     * @return O índice onde o alvo se encontra, ou -1 caso não esteja presente.
     */
    int buscar(const std::vector<int> &lista, int valor, int tamanho) override;
};

#endif // BUSCA_LINEAR_H
