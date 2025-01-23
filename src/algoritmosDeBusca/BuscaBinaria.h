#ifndef BUSCA_BINARIA_H
#define BUSCA_BINARIA_H

#include "StrategyBusca.h"

class BuscaBinaria : public StrategyBusca
{
public:
    /**
     * @brief Implementação da busca binária iterativa.
     *
     * @param lista Vetor de inteiros onde a busca será realizada (ordenado).
     * @param valor O alvo a ser buscado na lista.
     * @param tamanho O tamanho da lista.
     * @return O índice onde o alvo se encontra, ou -1 caso não esteja presente.
     */
    int buscar(const std::vector<int> &lista, int valor, int tamanho) override;
};

#endif // BUSCA_BINARIA_H
