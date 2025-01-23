#ifndef QUICK_SORT_ITERATIVE_H
#define QUICK_SORT_ITERATIVE_H

#include "StrategyOrdenacao.h"
#include <stack>

class QuickSortIterativo : public StrategyOrdenacao
{
public:
    /**
     * @brief Ordena um vetor de inteiros utilizando o algoritmo Quick Sort de forma iterativa.
     *
     * Este método utiliza a técnica de particionamento para dividir o vetor em subvetores e ordená-los.
     * A ordenação é realizada de forma iterativa, utilizando uma pilha para simular o comportamento recursivo.
     *
     * @param list Vetor de inteiros a ser ordenado.
     * @param tamanhoDoVetor Tamanho do vetor a ser ordenado.
     */
    void ordenar(std::vector<int> &list, int tamanhoDoVetor) override;

private:
    /**
     * @brief Particiona o vetor em torno de um pivô, de modo que todos os elementos à esquerda
     *        do pivô sejam menores e os elementos à direita sejam maiores.
     *
     * Esta função é utilizada como parte do processo de ordenação do Quick Sort, dividindo o vetor em
     * duas seções em relação ao pivô escolhido.
     *
     * @param lista Vetor de inteiros a ser particionado.
     * @param esquerda Índice inicial do vetor a ser particionado.
     * @param direita Índice final do vetor a ser particionado.
     *
     * @return Índice do pivô após o particionamento.
     */
    int particionar(std::vector<int> &lista, int esquerda, int direita);
};

#endif // QUICK_SORT_ITERATIVE_H
