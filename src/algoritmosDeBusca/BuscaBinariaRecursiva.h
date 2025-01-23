#ifndef BUSCA_BINARIA_RECURSIVA_H
#define BUSCA_BINARIA_RECURSIVA_H

#include "StrategyBusca.h"

class BuscaBinariaRecursiva : public StrategyBusca
{
public:
    /**
     * @brief Implementação da busca binária recursiva.
     *
     * @param lista Vetor de inteiros onde a busca será realizada (ordenado).
     * @param valor O alvo a ser buscado na lista.
     * @param tamanho O tamanho da lista.
     * @return O índice onde o alvo se encontra, ou -1 caso não esteja presente.
     */
    int buscar(const std::vector<int> &lista, int valor, int tamanho) override;

private:
    /**
     * @brief Função auxiliar para a recursão.
     *
     * @param lista Vetor de inteiros onde a busca será realizada (ordenado).
     * @param valor O alvo a ser buscado na lista.
     * @param inicio Índice inicial da busca.
     * @param fim Índice final da busca.
     * @return O índice onde o alvo se encontra, ou -1 caso não esteja presente.
     */
    int buscarRecursivo(const std::vector<int> &lista, int valor, int inicio, int fim);
};

#endif // BUSCA_BINARIA_RECURSIVA_H
