#ifndef UTILITARIOS_H
#define UTILITARIOS_H

#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <limits>
#include <algorithm>
#include "../medicao/MedicaoDeTempo.h"
#include "../algoritmosDeBusca/BuscaLinear.h"
#include "../algoritmosDeBusca/BuscaBinaria.h"
#include "../algoritmosDeBusca/BuscaBinariaRecursiva.h"
#include "../algoritmosDeOrdenacao/BubbleSortIterativo.h"
#include "../algoritmosDeOrdenacao/BubbleSortRecursivo.h"
#include "../algoritmosDeOrdenacao/QuickSortIterativo.h"
#include "../algoritmosDeOrdenacao/QuickSortRecursivo.h"
#include "../algoritmosDeOrdenacao/MergeSortIterativo.h"
#include "../algoritmosDeOrdenacao/MergeSortRecursivo.h"
#include "../medicao/EscritaDeArquivos.h"
#include "../medicao/MedicaoDeTempo.h"
#include "../medicao/EscritaDeArquivos.h"
#include "EscritaDeArquivos.h"

class Utilitarios
{
public:
    // Exibe o menu de opções
    static void exibirMenu();

    // Retorna o nome do algoritmo de ordenação
    static std::string tipoDeAlgoritmoOrdenacao(const std::unique_ptr<StrategyOrdenacao>& algoritmo);
    // Retorna o nome do algoritmo de Busca
    static std::string tipoDeAlgoritmoBusca(const std::unique_ptr<StrategyBusca>& algoritmo);

    // Clona um vetor
    static std::vector<int> clonarVetor(const std::vector<int> &vetorOriginal);

    // Executa e grava a ordenação
    static void executarEGravarOrdenacao(std::unique_ptr<StrategyOrdenacao> algoritmo,
                                         std::vector<int> vetorParaOrdenar,
                                         MedicaoDeTempo &medicao, bool exibirVetorNaSaida);

    // Executa e grava a busca
    static void executarEgravarBusca(std::unique_ptr<StrategyBusca> algoritmo,
                                     std::vector<int> vetor,
                                     int valorParaBuscar,
                                     MedicaoDeTempo &medicao, bool exibirVetorNaSaida);

    // Gera, imprime e grava um vetor
    static std::vector<int> gerarImprimirEGravarVetor(int tamanho,
                                                      int VALOR_MINIMO,
                                                      int VALOR_MAXIMO);

    // Obtém um número inteiro validado
    static size_t obterNumero();

    // Verifica a entrada Y/S
    static bool verificarEntradaYS();

    // Template para gerar vetor aleatório de qualquer tipo
    template <typename T>
    static std::vector<T> gerarVetorAleatorio(size_t tamanho, T valorMin, T valorMax)
    {
        std::vector<T> vetor(tamanho);
        for (auto &elemento : vetor)
        {
            elemento = valorMin + rand() % (valorMax - valorMin + 1);
        }
        return vetor;
    }
};

#endif // UTILITARIOS_H
