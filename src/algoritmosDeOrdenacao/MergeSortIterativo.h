#ifndef MERGE_SORT_ITERATIVE_H
#define MERGE_SORT_ITERATIVE_H

#include "StrategyOrdenacao.h"

class MergeSortIterativo : public StrategyOrdenacao
{
public:
    /**
     * @brief Ordena um vetor de inteiros utilizando o algoritmo Merge Sort de forma iterativa.
     *
     * Este método divide o vetor em subvetores menores e os ordena utilizando uma abordagem iterativa.
     * A ordenação é realizada em etapas, combinando os subvetores ordenados até que o vetor inteiro esteja ordenado.
     *
     * @param list Vetor de inteiros a ser ordenado.
     * @param tamanhoDoVetor Tamanho do vetor a ser ordenado.
     */
    void ordenar(std::vector<int> &list, int tamanhoDoVetor) override;

    /**
     * @brief Realiza a fusão de dois subvetores ordenados em um único subvetor ordenado.
     *
     * Este método é utilizado como parte do processo de Merge Sort, para combinar duas metades de um vetor
     * ordenado de forma iterativa.
     *
     * @param list Vetor de inteiros a ser modificado.
     * @param left Índice inicial do subvetor à esquerda.
     * @param mid Índice do meio que divide os subvetores.
     * @param right Índice final do subvetor à direita.
     */
    void merge(std::vector<int> &list, int left, int mid, int right);
};

#endif // MERGE_SORT_ITERATIVE_H
