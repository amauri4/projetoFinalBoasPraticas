#include "MedicaoDeTempo.h"

std::string MedicaoDeTempo::medirBusca(std::unique_ptr<StrategyBusca> estrategia, std::vector<int> &lista,
                                       int valor, int tamanho, bool exibirVetorNaSaida)
{
    auto inicio = std::chrono::high_resolution_clock::now();
    int resultado = estrategia->buscar(lista, valor, tamanho);
    auto fim = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracao = fim - inicio;

    std::ostringstream oss;

    std::string saida;
    if (exibirVetorNaSaida)
    {
        saida += "Vetor ordenado: ";
        for (const auto &val : lista)
        {
            saida += std::to_string(val) + " ";
        }
    }
    saida += "Resultado da busca (índice do elemento encontrado): " + std::to_string(resultado) + "\n";
    oss << std::fixed << std::setprecision(6) << duracao.count();
    saida += "\nTempo de busca: " + oss.str() + " milissegundos\n\n";

    return saida;
}

std::string MedicaoDeTempo::medirOrdenacao(std::unique_ptr<StrategyOrdenacao> estrategia, std::vector<int> &vetor,
                                           int tamanho, bool exibirVetorNaSaida)
{
    auto inicio = std::chrono::high_resolution_clock::now();
    estrategia->ordenar(vetor, tamanho);
    auto fim = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracao = fim - inicio;

    std::ostringstream oss;

    std::string saida;

    if (exibirVetorNaSaida)
    {
        saida += "Vetor ordenado: ";
        for (const auto &val : vetor)
        {
            saida += std::to_string(val) + " ";
        }
        saida += "\n";
    }

    oss << std::fixed << std::setprecision(6) << duracao.count();
    saida += "Tempo de ordenação: " + oss.str() + " milissegundos\n\n";

    return saida;
}