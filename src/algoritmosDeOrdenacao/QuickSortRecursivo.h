#ifndef QUICK_SORT_RECURSIVE_H
#define QUICK_SORT_RECURSIVE_H

#include "StrategyOrdenacao.h"

class QuickSortRecursivo : public StrategyOrdenacao
{
public:
    /**
     * @brief Ordena um vetor de inteiros utilizando o algoritmo Quick Sort de forma recursiva.
     *
     * Este método escolhe um pivô e particiona o vetor em duas seções. O processo é repetido recursivamente
     * para ordenar as seções à esquerda e à direita do pivô até que o vetor esteja completamente ordenado.
     *
     * @param lista Vetor de inteiros a ser ordenado.
     * @param tamanhoLista Tamanho do vetor a ser ordenado.
     */
    void ordenar(std::vector<int> &lista, int tamanhoLista) override;

private:
    /**
     * @brief Função recursiva que aplica o algoritmo Quick Sort nas seções à esquerda e à direita do pivô.
     *
     * Esta função é chamada recursivamente para dividir o vetor em seções menores, até que cada seção contenha
     * apenas um elemento, momento em que o vetor é considerado ordenado.
     *
     * @param lista Vetor de inteiros a ser ordenado.
     * @param esquerda Índice inicial do vetor a ser ordenado.
     * @param direita Índice final do vetor a ser ordenado.
     */
    void quickSort(std::vector<int> &lista, int esquerda, int direita);

    /**
     * @brief Particiona o vetor em torno de um pivô, de modo que todos os elementos à esquerda
     *        do pivô sejam menores e os elementos à direita sejam maiores.
     *
     * Este método escolhe um pivô e rearranja os elementos do vetor para que todos os valores menores que o pivô
     * fiquem à esquerda e os maiores à direita, retornando a posição final do pivô.
     *
     * @param lista Vetor de inteiros a ser particionado.
     * @param esquerda Índice inicial do vetor a ser particionado.
     * @param direita Índice final do vetor a ser particionado.
     *
     * @return Índice do pivô após o particionamento.
     */
    int particionar(std::vector<int> &lista, int esquerda, int direita);
};

#endif // QUICK_SORT_RECURSIVE_H
