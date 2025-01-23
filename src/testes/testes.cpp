#include <gtest/gtest.h>
#include <vector>
#include <memory>
#include "../algoritmosDeOrdenacao/BubbleSortIterativo.h"
#include "../algoritmosDeOrdenacao/BubbleSortRecursivo.h"
#include "../algoritmosDeOrdenacao/MergeSortRecursivo.h"
#include "../algoritmosDeOrdenacao/MergeSortIterativo.h"
#include "../algoritmosDeOrdenacao/QuickSortIterativo.h"
#include "../algoritmosDeOrdenacao/QuickSortRecursivo.h"
#include "../algoritmosDeBusca/BuscaBinaria.h"
#include "../algoritmosDeBusca/BuscaBinariaRecursiva.h"
#include "../algoritmosDeBusca/BuscaLinear.h"
#include "Contexto.h"
#include "../medicao/MedicaoDeTempo.h"

void imprimirVetor(const std::vector<int> &vetor)
{
    for (int num : vetor)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

// Testes de Ordenação
TEST(BubbleIterativo, Desordenado)
{
    std::vector<int> vetorDesordenado = {45, 12, 89, 33, 56, 78, 10, 23, 67};
    std::vector<int> vetorOrdenado = {10, 12, 23, 33, 45, 56, 67, 78, 89};

    Contexto contexto;
    contexto.setEstrategiaOrdenacao(std::unique_ptr<BubbleSortIterativo>(new BubbleSortIterativo));
    contexto.ordenar(vetorDesordenado);
    EXPECT_EQ(vetorDesordenado, vetorOrdenado);
}

TEST(BubbleIterativo, OrdemDecrescente)
{
    std::vector<int> vetorDesordenado = {89, 78, 67, 56, 45, 33, 23, 12, 10};
    std::vector<int> vetorOrdenado = {10, 12, 23, 33, 45, 56, 67, 78, 89};

    Contexto contexto;
    contexto.setEstrategiaOrdenacao(std::unique_ptr<BubbleSortIterativo>(new BubbleSortIterativo));
    contexto.ordenar(vetorDesordenado);
    EXPECT_EQ(vetorDesordenado, vetorOrdenado);
}

TEST(BubbleIterativo, ParcialmenteOrdenado)
{
    std::vector<int> vetorDesordenado = {10, 12, 23, 45, 33, 56, 78, 67, 89};
    std::vector<int> vetorOrdenado = {10, 12, 23, 33, 45, 56, 67, 78, 89};

    Contexto contexto;
    contexto.setEstrategiaOrdenacao(std::unique_ptr<BubbleSortIterativo>(new BubbleSortIterativo));
    contexto.ordenar(vetorDesordenado);
    EXPECT_EQ(vetorDesordenado, vetorOrdenado);
}

TEST(BubbleIterativo, TodosIguais)
{
    std::vector<int> vetorDesordenado = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<int> vetorOrdenado = {1, 1, 1, 1, 1, 1, 1, 1, 1};

    Contexto contexto;
    contexto.setEstrategiaOrdenacao(std::unique_ptr<BubbleSortIterativo>(new BubbleSortIterativo));
    contexto.ordenar(vetorDesordenado);
    EXPECT_EQ(vetorDesordenado, vetorOrdenado);
}

TEST(BubbleIterativo, OrdemCrescente)
{
    std::vector<int> vetorDesordenado = {10, 12, 23, 45, 33, 56, 78, 67, 89};
    std::vector<int> vetorOrdenado = {10, 12, 23, 33, 45, 56, 67, 78, 89};

    Contexto contexto;
    contexto.setEstrategiaOrdenacao(std::unique_ptr<BubbleSortIterativo>(new BubbleSortIterativo));
    contexto.ordenar(vetorDesordenado);
    EXPECT_EQ(vetorDesordenado, vetorOrdenado);
}

TEST(BubbleRecursivo, Desordenado)
{
    std::vector<int> vetorDesordenado = {45, 12, 89, 33, 56, 78, 10, 23, 67};
    std::vector<int> vetorOrdenado = {10, 12, 23, 33, 45, 56, 67, 78, 89};

    Contexto contexto;
    contexto.setEstrategiaOrdenacao(std::unique_ptr<BubbleSortRecursivo>(new BubbleSortRecursivo));
    contexto.ordenar(vetorDesordenado);
    EXPECT_EQ(vetorDesordenado, vetorOrdenado);
}

TEST(BubbleRecursivo, OrdemDecrescente)
{
    std::vector<int> vetorDesordenado = {89, 78, 67, 56, 45, 33, 23, 12, 10};
    std::vector<int> vetorOrdenado = {10, 12, 23, 33, 45, 56, 67, 78, 89};

    Contexto contexto;
    contexto.setEstrategiaOrdenacao(std::unique_ptr<BubbleSortRecursivo>(new BubbleSortRecursivo));
    contexto.ordenar(vetorDesordenado);
    EXPECT_EQ(vetorDesordenado, vetorOrdenado);
}

TEST(BubbleRecursivo, ParcialmenteOrdenado)
{
    std::vector<int> vetorDesordenado = {10, 12, 23, 45, 33, 56, 78, 67, 89};
    std::vector<int> vetorOrdenado = {10, 12, 23, 33, 45, 56, 67, 78, 89};

    Contexto contexto;
    contexto.setEstrategiaOrdenacao(std::unique_ptr<BubbleSortRecursivo>(new BubbleSortRecursivo));
    contexto.ordenar(vetorDesordenado);
    EXPECT_EQ(vetorDesordenado, vetorOrdenado);
}

TEST(BubbleRecursivo, TodosIguais)
{
    std::vector<int> vetorDesordenado = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<int> vetorOrdenado = {1, 1, 1, 1, 1, 1, 1, 1, 1};

    Contexto contexto;
    contexto.setEstrategiaOrdenacao(std::unique_ptr<BubbleSortRecursivo>(new BubbleSortRecursivo));
    contexto.ordenar(vetorDesordenado);
    EXPECT_EQ(vetorDesordenado, vetorOrdenado);
}

TEST(BubbleRecursivo, OrdemCrescente)
{
    std::vector<int> vetorDesordenado = {10, 12, 23, 45, 33, 56, 78, 67, 89};
    std::vector<int> vetorOrdenado = {10, 12, 23, 33, 45, 56, 67, 78, 89};

    Contexto contexto;
    contexto.setEstrategiaOrdenacao(std::unique_ptr<BubbleSortRecursivo>(new BubbleSortRecursivo));
    contexto.ordenar(vetorDesordenado);
    EXPECT_EQ(vetorDesordenado, vetorOrdenado);
}

TEST(MergeIterativo, Desordenado)
{
    std::vector<int> vetorDesordenado = {45, 12, 89, 33, 56, 78, 10, 23, 67};
    std::vector<int> vetorOrdenado = {10, 12, 23, 33, 45, 56, 67, 78, 89};

    Contexto contexto;
    contexto.setEstrategiaOrdenacao(std::unique_ptr<MergeSortIterativo>(new MergeSortIterativo));
    contexto.ordenar(vetorDesordenado);
    EXPECT_EQ(vetorDesordenado, vetorOrdenado);
}

TEST(MergeIterativo, OrdemDecrescente)
{
    std::vector<int> vetorDesordenado = {89, 78, 67, 56, 45, 33, 23, 12, 10};
    std::vector<int> vetorOrdenado = {10, 12, 23, 33, 45, 56, 67, 78, 89};

    Contexto contexto;
    contexto.setEstrategiaOrdenacao(std::unique_ptr<MergeSortIterativo>(new MergeSortIterativo));
    contexto.ordenar(vetorDesordenado);
    EXPECT_EQ(vetorDesordenado, vetorOrdenado);
}

TEST(MergeIterativo, ParcialmenteOrdenado)
{
    std::vector<int> vetorDesordenado = {10, 12, 23, 45, 33, 56, 78, 67, 89};
    std::vector<int> vetorOrdenado = {10, 12, 23, 33, 45, 56, 67, 78, 89};

    Contexto contexto;
    contexto.setEstrategiaOrdenacao(std::unique_ptr<MergeSortIterativo>(new MergeSortIterativo));
    contexto.ordenar(vetorDesordenado);
    EXPECT_EQ(vetorDesordenado, vetorOrdenado);
}

TEST(MergeIterativo, TodosIguais)
{
    std::vector<int> vetorDesordenado = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<int> vetorOrdenado = {1, 1, 1, 1, 1, 1, 1, 1, 1};

    Contexto contexto;
    contexto.setEstrategiaOrdenacao(std::unique_ptr<MergeSortIterativo>(new MergeSortIterativo));
    contexto.ordenar(vetorDesordenado);
    EXPECT_EQ(vetorDesordenado, vetorOrdenado);
}

TEST(MergeIterativo, OrdemCrescente)
{
    std::vector<int> vetorDesordenado = {10, 12, 23, 45, 33, 56, 78, 67, 89};
    std::vector<int> vetorOrdenado = {10, 12, 23, 33, 45, 56, 67, 78, 89};

    Contexto contexto;
    contexto.setEstrategiaOrdenacao(std::unique_ptr<MergeSortIterativo>(new MergeSortIterativo));
    contexto.ordenar(vetorDesordenado);
    EXPECT_EQ(vetorDesordenado, vetorOrdenado);
}

TEST(MergeRecursivo, Desordenado)
{
    std::vector<int> vetorDesordenado = {45, 12, 89, 33, 56, 78, 10, 23, 67};
    std::vector<int> vetorOrdenado = {10, 12, 23, 33, 45, 56, 67, 78, 89};

    Contexto contexto;
    contexto.setEstrategiaOrdenacao(std::unique_ptr<MergeSortRecursivo>(new MergeSortRecursivo));
    contexto.ordenar(vetorDesordenado);
    EXPECT_EQ(vetorDesordenado, vetorOrdenado);
}

TEST(MergeRecursivo, OrdemDecrescente)
{
    std::vector<int> vetorDesordenado = {89, 78, 67, 56, 45, 33, 23, 12, 10};
    std::vector<int> vetorOrdenado = {10, 12, 23, 33, 45, 56, 67, 78, 89};

    Contexto contexto;
    contexto.setEstrategiaOrdenacao(std::unique_ptr<MergeSortRecursivo>(new MergeSortRecursivo));
    contexto.ordenar(vetorDesordenado);
    EXPECT_EQ(vetorDesordenado, vetorOrdenado);
}

TEST(MergeRecursivo, ParcialmenteOrdenado)
{
    std::vector<int> vetorDesordenado = {10, 12, 23, 45, 33, 56, 78, 67, 89};
    std::vector<int> vetorOrdenado = {10, 12, 23, 33, 45, 56, 67, 78, 89};

    Contexto contexto;
    contexto.setEstrategiaOrdenacao(std::unique_ptr<MergeSortRecursivo>(new MergeSortRecursivo));
    contexto.ordenar(vetorDesordenado);
    EXPECT_EQ(vetorDesordenado, vetorOrdenado);
}

TEST(MergeRecursivo, TodosIguais)
{
    std::vector<int> vetorDesordenado = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<int> vetorOrdenado = {1, 1, 1, 1, 1, 1, 1, 1, 1};

    Contexto contexto;
    contexto.setEstrategiaOrdenacao(std::unique_ptr<MergeSortRecursivo>(new MergeSortRecursivo));
    contexto.ordenar(vetorDesordenado);
    EXPECT_EQ(vetorDesordenado, vetorOrdenado);
}

TEST(MergeRecursivo, OrdemCrescente)
{
    std::vector<int> vetorDesordenado = {10, 12, 23, 45, 33, 56, 78, 67, 89};
    std::vector<int> vetorOrdenado = {10, 12, 23, 33, 45, 56, 67, 78, 89};

    Contexto contexto;
    contexto.setEstrategiaOrdenacao(std::unique_ptr<MergeSortRecursivo>(new MergeSortRecursivo));
    contexto.ordenar(vetorDesordenado);
    EXPECT_EQ(vetorDesordenado, vetorOrdenado);
}

TEST(QuickIterativo, Desordenado)
{
    std::vector<int> vetorDesordenado = {45, 12, 89, 33, 56, 78, 10, 23, 67};
    std::vector<int> vetorOrdenado = {10, 12, 23, 33, 45, 56, 67, 78, 89};

    Contexto contexto;
    contexto.setEstrategiaOrdenacao(std::unique_ptr<QuickSortIterativo>(new QuickSortIterativo));
    contexto.ordenar(vetorDesordenado);
    EXPECT_EQ(vetorDesordenado, vetorOrdenado);
}

TEST(QuickIterativo, OrdemDecrescente)
{
    std::vector<int> vetorDesordenado = {89, 78, 67, 56, 45, 33, 23, 12, 10};
    std::vector<int> vetorOrdenado = {10, 12, 23, 33, 45, 56, 67, 78, 89};

    Contexto contexto;
    contexto.setEstrategiaOrdenacao(std::unique_ptr<QuickSortIterativo>(new QuickSortIterativo));
    contexto.ordenar(vetorDesordenado);
    EXPECT_EQ(vetorDesordenado, vetorOrdenado);
}

TEST(QuickIterativo, ParcialmenteOrdenado)
{
    std::vector<int> vetorDesordenado = {10, 12, 23, 45, 33, 56, 78, 67, 89};
    std::vector<int> vetorOrdenado = {10, 12, 23, 33, 45, 56, 67, 78, 89};

    Contexto contexto;
    contexto.setEstrategiaOrdenacao(std::unique_ptr<QuickSortIterativo>(new QuickSortIterativo));
    contexto.ordenar(vetorDesordenado);
    EXPECT_EQ(vetorDesordenado, vetorOrdenado);
}

TEST(QuickIterativo, TodosIguais)
{
    std::vector<int> vetorDesordenado = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<int> vetorOrdenado = {1, 1, 1, 1, 1, 1, 1, 1, 1};

    Contexto contexto;
    contexto.setEstrategiaOrdenacao(std::unique_ptr<QuickSortIterativo>(new QuickSortIterativo));
    contexto.ordenar(vetorDesordenado);
    EXPECT_EQ(vetorDesordenado, vetorOrdenado);
}

TEST(QuickIterativo, OrdemCrescente)
{
    std::vector<int> vetorDesordenado = {10, 12, 23, 45, 33, 56, 78, 67, 89};
    std::vector<int> vetorOrdenado = {10, 12, 23, 33, 45, 56, 67, 78, 89};

    Contexto contexto;
    contexto.setEstrategiaOrdenacao(std::unique_ptr<QuickSortIterativo>(new QuickSortIterativo));
    contexto.ordenar(vetorDesordenado);
    EXPECT_EQ(vetorDesordenado, vetorOrdenado);
}

TEST(QuickRecursivo, Desordenado)
{
    std::vector<int> vetorDesordenado = {45, 12, 89, 33, 56, 78, 10, 23, 67};
    std::vector<int> vetorOrdenado = {10, 12, 23, 33, 45, 56, 67, 78, 89};

    Contexto contexto;
    contexto.setEstrategiaOrdenacao(std::unique_ptr<QuickSortRecursivo>(new QuickSortRecursivo));
    contexto.ordenar(vetorDesordenado);
    EXPECT_EQ(vetorDesordenado, vetorOrdenado);
}

TEST(QuickRecursivo, OrdemDecrescente)
{
    std::vector<int> vetorDesordenado = {89, 78, 67, 56, 45, 33, 23, 12, 10};
    std::vector<int> vetorOrdenado = {10, 12, 23, 33, 45, 56, 67, 78, 89};

    Contexto contexto;
    contexto.setEstrategiaOrdenacao(std::unique_ptr<QuickSortRecursivo>(new QuickSortRecursivo));
    contexto.ordenar(vetorDesordenado);
    EXPECT_EQ(vetorDesordenado, vetorOrdenado);
}

TEST(QuickRecursivo, ParcialmenteOrdenado)
{
    std::vector<int> vetorDesordenado = {10, 12, 23, 45, 33, 56, 78, 67, 89};
    std::vector<int> vetorOrdenado = {10, 12, 23, 33, 45, 56, 67, 78, 89};

    Contexto contexto;
    contexto.setEstrategiaOrdenacao(std::unique_ptr<QuickSortRecursivo>(new QuickSortRecursivo));
    contexto.ordenar(vetorDesordenado);
    EXPECT_EQ(vetorDesordenado, vetorOrdenado);
}

TEST(QuickRecursivo, TodosIguais)
{
    std::vector<int> vetorDesordenado = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<int> vetorOrdenado = {1, 1, 1, 1, 1, 1, 1, 1, 1};

    Contexto contexto;
    contexto.setEstrategiaOrdenacao(std::unique_ptr<QuickSortRecursivo>(new QuickSortRecursivo));
    contexto.ordenar(vetorDesordenado);
    EXPECT_EQ(vetorDesordenado, vetorOrdenado);
}

TEST(QuickRecursivo, OrdemCrescente)
{
    std::vector<int> vetorDesordenado = {10, 12, 23, 45, 33, 56, 78, 67, 89};
    std::vector<int> vetorOrdenado = {10, 12, 23, 33, 45, 56, 67, 78, 89};

    Contexto contexto;
    contexto.setEstrategiaOrdenacao(std::unique_ptr<QuickSortRecursivo>(new QuickSortRecursivo));
    contexto.ordenar(vetorDesordenado);
    EXPECT_EQ(vetorDesordenado, vetorOrdenado);
}

// Testes de Busca
TEST(BuscaBinariaIterativa, AlvoNoInicio)
{
    std::vector<int> vetorBusca = {10, 12, 23, 33, 45, 56, 67, 78, 89};
    int valor = 10;

    Contexto contexto;
    contexto.setEstrategiaBusca(std::unique_ptr<BuscaBinaria>(new BuscaBinaria));
    int indice = contexto.buscar(vetorBusca, valor);
    EXPECT_EQ(indice, 0);
}

TEST(BuscaBinariaIterativa, AlvoNoFim)
{
    std::vector<int> vetorBusca = {10, 12, 23, 33, 45, 56, 67, 78, 89};
    int valor = 89;

    Contexto contexto;
    contexto.setEstrategiaBusca(std::unique_ptr<BuscaBinaria>(new BuscaBinaria));
    int indice = contexto.buscar(vetorBusca, valor);
    EXPECT_EQ(indice, 8);
}

TEST(BuscaBinariaIterativa, AlvoNoMeio)
{
    std::vector<int> vetorBusca = {10, 12, 23, 33, 45, 56, 67, 78, 89};
    int valor = 45;

    Contexto contexto;
    contexto.setEstrategiaBusca(std::unique_ptr<BuscaBinaria>(new BuscaBinaria));
    int indice = contexto.buscar(vetorBusca, valor);
    EXPECT_EQ(indice, 4);
}

TEST(BuscaBinariaIterativa, AlvoAusente)
{
    std::vector<int> vetorBusca = {10, 12, 23, 33, 45, 56, 67, 78, 89};
    int valor = 100;

    Contexto contexto;
    contexto.setEstrategiaBusca(std::unique_ptr<BuscaBinaria>(new BuscaBinaria));
    int indice = contexto.buscar(vetorBusca, valor);
    EXPECT_EQ(indice, -1);
}

TEST(BuscaBinariaRecursiva, AlvoNoInicio)
{
    std::vector<int> vetorBusca = {10, 12, 23, 33, 45, 56, 67, 78, 89};
    int valor = 10;

    Contexto contexto;
    contexto.setEstrategiaBusca(std::unique_ptr<BuscaBinariaRecursiva>(new BuscaBinariaRecursiva));
    int indice = contexto.buscar(vetorBusca, valor);
    EXPECT_EQ(indice, 0);
}

TEST(BuscaBinariaRecursiva, AlvoNoFim)
{
    std::vector<int> vetorBusca = {10, 12, 23, 33, 45, 56, 67, 78, 89};
    int valor = 89;

    Contexto contexto;
    contexto.setEstrategiaBusca(std::unique_ptr<BuscaBinariaRecursiva>(new BuscaBinariaRecursiva));
    int indice = contexto.buscar(vetorBusca, valor);
    EXPECT_EQ(indice, 8);
}

TEST(BuscaBinariaRecursiva, AlvoNoMeio)
{
    std::vector<int> vetorBusca = {10, 12, 23, 33, 45, 56, 67, 78, 89};
    int valor = 45;

    Contexto contexto;
    contexto.setEstrategiaBusca(std::unique_ptr<BuscaBinariaRecursiva>(new BuscaBinariaRecursiva));
    int indice = contexto.buscar(vetorBusca, valor);
    EXPECT_EQ(indice, 4);
}

TEST(BuscaBinariaRecursiva, AlvoAusente)
{
    std::vector<int> vetorBusca = {10, 12, 23, 33, 45, 56, 67, 78, 89};
    int valor = 100;

    Contexto contexto;
    contexto.setEstrategiaBusca(std::unique_ptr<BuscaBinariaRecursiva>(new BuscaBinariaRecursiva));
    int indice = contexto.buscar(vetorBusca, valor);
    EXPECT_EQ(indice, -1);
}

TEST(BuscaLinear, AlvoNoInicio)
{
    std::vector<int> vetorBusca = {10, 12, 23, 33, 45, 56, 67, 78, 89};
    int valor = 10;

    Contexto contexto;
    contexto.setEstrategiaBusca(std::unique_ptr<BuscaLinear>(new BuscaLinear));
    int indice = contexto.buscar(vetorBusca, valor);
    EXPECT_EQ(indice, 0);
}

TEST(BuscaLinear, AlvoNoFim)
{
    std::vector<int> vetorBusca = {10, 12, 23, 33, 45, 56, 67, 78, 89};
    int valor = 89;

    Contexto contexto;
    contexto.setEstrategiaBusca(std::unique_ptr<BuscaLinear>(new BuscaLinear));
    int indice = contexto.buscar(vetorBusca, valor);
    EXPECT_EQ(indice, 8);
}

TEST(BuscaLinear, AlvoNoMeio)
{
    std::vector<int> vetorBusca = {10, 12, 23, 33, 45, 56, 67, 78, 89};
    int valor = 45;

    Contexto contexto;
    contexto.setEstrategiaBusca(std::unique_ptr<BuscaLinear>(new BuscaLinear));
    int indice = contexto.buscar(vetorBusca, valor);
    EXPECT_EQ(indice, 4);
}

TEST(BuscaLinear, AlvoAusente)
{
    std::vector<int> vetorBusca = {10, 12, 23, 33, 45, 56, 67, 78, 89};
    int valor = 100;

    Contexto contexto;
    contexto.setEstrategiaBusca(std::unique_ptr<BuscaLinear>(new BuscaLinear));
    int indice = contexto.buscar(vetorBusca, valor);
    EXPECT_EQ(indice, -1);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
