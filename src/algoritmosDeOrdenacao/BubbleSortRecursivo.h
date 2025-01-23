#ifndef BUBBLE_SORT_RECURSIVE_H
#define BUBBLE_SORT_RECURSIVE_H

#include "StrategyOrdenacao.h"

class BubbleSortRecursivo : public StrategyOrdenacao
{
public:
    /**
     * @brief Ordena um vetor de inteiros utilizando o algoritmo Bubble Sort de forma recursiva.
     *
     * Este método compara elementos adjacentes do vetor e os troca de posição se estiverem fora de ordem.
     * A ordenação é realizada recursivamente, reduzindo progressivamente o número de comparações a cada chamada.
     *
     * @param lista Vetor de inteiros a ser ordenado.
     * @param tamanhoDoVetor Tamanho do vetor a ser ordenado.
     */
    void ordenar(std::vector<int> &lista, int tamanhoDoVetor) override;
};

#endif // BUBBLE_SORT_RECURSIVE_H
