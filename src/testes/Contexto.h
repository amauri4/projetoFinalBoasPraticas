#ifndef CONTEXTO_H
#define CONTEXTO_H

#include "../algoritmosDeBusca/StrategyBusca.h"
#include "../algoritmosDeOrdenacao/StrategyOrdenacao.h"
#include <memory>
#include <vector>
#include <iostream>

/**
 * @brief Classe que gerencia a estratégia de ordenação e busca.
 *
 * A classe `Contexto` permite definir e alterar as estratégias de ordenação e busca em tempo de execução.
 * Ela usa o padrão de projeto Strategy, permitindo a troca de algoritmos de ordenação e busca conforme necessário.
 * Esta classe delega a execução dos algoritmos para as respectivas estratégias configuradas.
 */
class Contexto
{
private:
    /**
     * @brief Ponteiro único para a estratégia de ordenação.
     *
     * Este ponteiro é responsável por armazenar a estratégia de ordenação atualmente configurada.
     */
    std::unique_ptr<StrategyOrdenacao> estrategiaOrdenacao;

    /**
     * @brief Ponteiro único para a estratégia de busca.
     *
     * Este ponteiro é responsável por armazenar a estratégia de busca atualmente configurada.
     */
    std::unique_ptr<StrategyBusca> estrategiaBusca;

public:
    /**
     * @brief Define a estratégia de ordenação.
     *
     * Este método permite configurar uma nova estratégia de ordenação, substituindo a estratégia atual.
     *
     * @param estrategia Ponteiro para a nova estratégia de ordenação a ser configurada.
     */
    void setEstrategiaOrdenacao(std::unique_ptr<StrategyOrdenacao> estrategia)
    {
        estrategiaOrdenacao = std::move(estrategia);
    }

    /**
     * @brief Define a estratégia de busca.
     *
     * Este método permite configurar uma nova estratégia de busca, substituindo a estratégia atual.
     *
     * @param estrategia Ponteiro para a nova estratégia de busca a ser configurada.
     */
    void setEstrategiaBusca(std::unique_ptr<StrategyBusca> estrategia)
    {
        estrategiaBusca = std::move(estrategia);
    }

    /**
     * @brief Realiza a ordenação de um vetor utilizando a estratégia configurada.
     *
     * Este método ordena o vetor passado como argumento utilizando o algoritmo de ordenação configurado
     * através da estratégia definida. Caso a estratégia de ordenação não tenha sido configurada,
     * uma mensagem de erro será exibida.
     *
     * @param lista Vetor de inteiros a ser ordenado.
     */
    void ordenar(std::vector<int> &lista)
    {
        if (estrategiaOrdenacao)
        {
            estrategiaOrdenacao->ordenar(lista, lista.size());
        }
        else
        {
            std::cout << "Estratégia de ordenação não configurada!" << std::endl;
        }
    }

    /**
     * @brief Realiza a busca de um elemento em um vetor utilizando a estratégia configurada.
     *
     * Este método busca a chave fornecida no vetor utilizando o algoritmo de busca configurado
     * através da estratégia definida. Caso a estratégia de busca não tenha sido configurada,
     * uma mensagem de erro será exibida.
     *
     * @param lista Vetor de inteiros onde a busca será realizada.
     * @param chave Elemento a ser buscado no vetor.
     * @return O índice do elemento encontrado ou uma mensagem de erro se a busca falhar.
     */
    int buscar(const std::vector<int> &lista, int chave)
    {
        if (estrategiaBusca)
        {
            return estrategiaBusca->buscar(lista, chave, lista.size());
        }
        else
        {
            std::cout << "Estratégia de busca não configurada!" << std::endl;
            return false;
        }
    }
};

#endif // CONTEXTO_H
