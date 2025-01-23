#ifndef MERGE_SORT_RECURSIVE_H
#define MERGE_SORT_RECURSIVE_H

#include "StrategyOrdenacao.h"

class MergeSortRecursivo : public StrategyOrdenacao
{
public:
    /**
     * @brief Ordena um vetor de inteiros utilizando o algoritmo Merge Sort de forma recursiva.
     *
     * Este método divide o vetor em subvetores menores e os ordena utilizando a abordagem recursiva.
     * O vetor é dividido em duas metades e as metades são ordenadas recursivamente até que o vetor inteiro
     * esteja ordenado.
     *
     * @param lista Vetor de inteiros a ser ordenado.
     * @param tamanhoDoVetor Tamanho do vetor a ser ordenado.
     */
    void ordenar(std::vector<int> &lista, int tamanhoDoVetor) override;

private:
    /**
     * @brief Função recursiva que divide o vetor e chama o Merge Sort nas duas metades.
     *
     * Esta função é chamada recursivamente para dividir o vetor em subvetores cada vez menores
     * até que os subvetores possuam apenas um elemento, momento em que começam a ser mesclados.
     *
     * @param list Vetor de inteiros a ser dividido.
     * @param left Índice inicial do vetor.
     * @param right Índice final do vetor.
     */
    void mergeSort(std::vector<int> &list, int left, int right);

    /**
     * @brief Realiza a fusão de dois subvetores ordenados em um único subvetor ordenado.
     *
     * Este método é utilizado como parte do processo de Merge Sort, para combinar duas metades de um vetor
     * ordenado de forma recursiva.
     *
     * @param list Vetor de inteiros a ser modificado.
     * @param left Índice inicial do subvetor à esquerda.
     * @param mid Índice do meio que divide os subvetores.
     * @param right Índice final do subvetor à direita.
     */
    void merge(std::vector<int> &list, int left, int mid, int right);
};

#endif // MERGE_SORT_RECURSIVE_H
