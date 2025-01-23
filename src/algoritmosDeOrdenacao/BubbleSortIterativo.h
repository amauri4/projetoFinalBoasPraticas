#ifndef BUBBLE_SORT_ITERATIVE_H
#define BUBBLE_SORT_ITERATIVE_H

#include "StrategyOrdenacao.h"

class BubbleSortIterativo : public StrategyOrdenacao
{
public:
    /**
     * @brief Ordena um vetor de inteiros utilizando o algoritmo Bubble Sort de forma iterativa.
     *
     * Este método percorre o vetor várias vezes, comparando elementos adjacentes e trocando-os
     * de posição se estiverem fora de ordem. O processo é repetido até que o vetor esteja ordenado.
     *
     * @param lista Vetor de inteiros a ser ordenado.
     * @param tamanhoDoVetor Tamanho do vetor a ser ordenado.
     */
    void ordenar(std::vector<int> &lista, int tamanhoDoVetor) override;
};

#endif // BUBBLE_SORT_ITERATIVE_H
