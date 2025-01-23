#include "medicao/MedicaoDeTempo.h"
#include "algoritmosDeBusca/BuscaLinear.h"
#include "algoritmosDeBusca/BuscaBinaria.h"
#include "algoritmosDeBusca/BuscaBinariaRecursiva.h"
#include "algoritmosDeOrdenacao/BubbleSortIterativo.h"
#include "algoritmosDeOrdenacao/BubbleSortRecursivo.h"
#include "algoritmosDeOrdenacao/QuickSortIterativo.h"
#include "algoritmosDeOrdenacao/QuickSortRecursivo.h"
#include "algoritmosDeOrdenacao/MergeSortIterativo.h"
#include "algoritmosDeOrdenacao/MergeSortRecursivo.h"
#include "./medicao/EscritaDeArquivos.h"
#include "./utilitarios/Utilitarios.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <memory>
#include <fstream>

const int VALOR_MINIMO = 1;
const int VALOR_MAXIMO = 100;
const std::vector<size_t> TAMANHOS_VETORES = {10, 100, 1000, 10000};
enum Algoritmos
{
    BUBBLE_SORT_ITERATIVO = 1,
    BUBBLE_SORT_RECURSIVO,
    QUICK_SORT_ITERATIVO,
    QUICK_SORT_RECURSIVO,
    MERGE_SORT_ITERATIVO,
    MERGE_SORT_RECURSIVO,
    BUSCA_LINEAR,
    BUSCA_BINARIA,
    BUSCA_BINARIA_RECURSIVA,
    EXECUTAR_TODOS_OS_TESTES
};

// Cópia do make_unique do c++ feita para evitar conflito de bibliotecas
namespace std
{
    template <typename T, typename... Args>
    std::unique_ptr<T> make_unique(Args &&...args)
    {
        return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
    }
}

int main()
{
    // Inicializar o gerador de números aleatórios
    std::srand(std::time(nullptr));

    // Criar uma instância de MedicaoDeTempo
    MedicaoDeTempo medicao;
    int opcao;
    bool exibirMenu = true;

    do
    {
        if (exibirMenu)
        {
            Utilitarios::exibirMenu();
        }

        opcao = Utilitarios::obterNumero();

        if (opcao < 0 || opcao > 10)
        {
            std::string erro = "Opção inválida. \nTente novamente:";
            std::cout << erro;
            exibirMenu = false;
            continue;
        }

        if (opcao == 0)
        {
            std::cout << opcao;
            std::string mensagem = "Saindo...\n";
            std::cout << mensagem;
            EscritaDeArquivos::gravarEmArquivo(mensagem);
            exit(EXIT_SUCCESS);
            break;
        }

        exibirMenu = true;

        if (opcao == EXECUTAR_TODOS_OS_TESTES)
        {
            bool yesOrNo = Utilitarios::verificarEntradaYS();

            std::string mensagem = "Executando todos os testes...\n";
            EscritaDeArquivos::gravarEmArquivo(mensagem);
            std::cout << mensagem;

            for (size_t tamanho : TAMANHOS_VETORES)
            {
                int alvoBuscaPiorCaso = -1;
                std::vector<int> listaAleatoria = Utilitarios::gerarImprimirEGravarVetor(tamanho, VALOR_MINIMO, VALOR_MAXIMO);
                // Executando ordenações
                Utilitarios::executarEGravarOrdenacao(std::make_unique<BubbleSortIterativo>(), Utilitarios::clonarVetor(listaAleatoria), medicao, yesOrNo);
                Utilitarios::executarEGravarOrdenacao(std::make_unique<BubbleSortRecursivo>(), Utilitarios::clonarVetor(listaAleatoria), medicao, yesOrNo);
                Utilitarios::executarEGravarOrdenacao(std::make_unique<QuickSortIterativo>(), Utilitarios::clonarVetor(listaAleatoria), medicao, yesOrNo);
                Utilitarios::executarEGravarOrdenacao(std::make_unique<QuickSortRecursivo>(), Utilitarios::clonarVetor(listaAleatoria), medicao, yesOrNo);
                Utilitarios::executarEGravarOrdenacao(std::make_unique<MergeSortIterativo>(), Utilitarios::clonarVetor(listaAleatoria), medicao, yesOrNo);
                Utilitarios::executarEGravarOrdenacao(std::make_unique<MergeSortRecursivo>(), Utilitarios::clonarVetor(listaAleatoria), medicao, yesOrNo);
                // Executando Buscas
                Utilitarios::executarEgravarBusca(std::make_unique<BuscaLinear>(), Utilitarios::clonarVetor(listaAleatoria), alvoBuscaPiorCaso, medicao, yesOrNo);
                Utilitarios::executarEgravarBusca(std::make_unique<BuscaBinaria>(), Utilitarios::clonarVetor(listaAleatoria), alvoBuscaPiorCaso, medicao, yesOrNo);
                Utilitarios::executarEgravarBusca(std::make_unique<BuscaBinariaRecursiva>(), Utilitarios::clonarVetor(listaAleatoria), alvoBuscaPiorCaso, medicao, yesOrNo);
            }
            continue; // Volta para o menu após rodar todos os testes
        }

        std::cout << "Informe o tamanho do vetor: ";
        size_t tamanho = Utilitarios::obterNumero();
        std::vector<int> vetorParaOrdenar = Utilitarios::gerarImprimirEGravarVetor(tamanho, VALOR_MINIMO, VALOR_MAXIMO);
        bool yesOrNo = Utilitarios::verificarEntradaYS();

        switch (opcao)
        {
        case BUBBLE_SORT_ITERATIVO:
        {
            Utilitarios::executarEGravarOrdenacao(std::make_unique<BubbleSortIterativo>(), vetorParaOrdenar, medicao, yesOrNo);
            break;
        }
        case BUBBLE_SORT_RECURSIVO:
        {
            Utilitarios::executarEGravarOrdenacao(std::make_unique<BubbleSortRecursivo>(), vetorParaOrdenar, medicao, yesOrNo);
            break;
        }
        case QUICK_SORT_ITERATIVO:
        {
            Utilitarios::executarEGravarOrdenacao(std::make_unique<QuickSortIterativo>(), vetorParaOrdenar, medicao, yesOrNo);
            break;
        }
        case QUICK_SORT_RECURSIVO:
        {
            Utilitarios::executarEGravarOrdenacao(std::make_unique<QuickSortRecursivo>(), vetorParaOrdenar, medicao, yesOrNo);
            break;
        }
        case MERGE_SORT_ITERATIVO:
        {
            Utilitarios::executarEGravarOrdenacao(std::make_unique<MergeSortIterativo>(), vetorParaOrdenar, medicao, yesOrNo);
            break;
        }
        case MERGE_SORT_RECURSIVO:
        {
            Utilitarios::executarEGravarOrdenacao(std::make_unique<MergeSortRecursivo>(), vetorParaOrdenar, medicao, yesOrNo);
            break;
        }
        case BUSCA_LINEAR:
        {
            int valorParaBuscar;
            std::cout << "Informe o valor para buscar: ";
            std::cin >> valorParaBuscar;
            Utilitarios::executarEgravarBusca(std::make_unique<BuscaLinear>(), vetorParaOrdenar, valorParaBuscar,
                                              medicao, yesOrNo);
            break;
        }
        case BUSCA_BINARIA:
        {
            int valorParaBuscar;
            std::cout << "Informe o valor para buscar: ";
            std::cin >> valorParaBuscar;
            Utilitarios::executarEgravarBusca(std::make_unique<BuscaBinaria>(), vetorParaOrdenar, valorParaBuscar,
                                              medicao, yesOrNo);
            break;
        }
        case BUSCA_BINARIA_RECURSIVA:
        {
            int valorParaBuscar;
            std::cout << "Informe o valor para buscar: ";
            std::cin >> valorParaBuscar;
            Utilitarios::executarEgravarBusca(std::make_unique<BuscaBinariaRecursiva>(), vetorParaOrdenar, valorParaBuscar,
                                              medicao, yesOrNo);
            break;
        }
        default:
            break;
        }
    } while (true);

    return 0;
}
