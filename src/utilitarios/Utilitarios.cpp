#include "Utilitarios.h"

void Utilitarios::exibirMenu()
{
    std::string borda = "=======================================";
    std::string titulo = "        MENU DE OPCOES        ";
    std::string mensagem = "\n";

    mensagem += borda + "\n";
    mensagem += titulo + "\n";
    mensagem += borda + "\n";
    mensagem += " 1. Bubble Sort Iterativo\n";
    mensagem += " 2. Bubble Sort Recursivo\n";
    mensagem += " 3. Quick Sort Iterativo\n";
    mensagem += " 4. Quick Sort Recursivo\n";
    mensagem += " 5. Merge Sort Iterativo\n";
    mensagem += " 6. Merge Sort Recursivo\n";
    mensagem += " 7. Busca Linear\n";
    mensagem += " 8. Busca Binária\n";
    mensagem += " 9. Busca Binária Recursiva\n";
    mensagem += "10. Executar todos os testes\n";
    mensagem += "0. Sair\n";
    mensagem += borda + "\n";
    mensagem += "Escolha uma opcao: ";

    std::cout << mensagem;
}

std::string Utilitarios::tipoDeAlgoritmoOrdenacao(const std::unique_ptr<StrategyOrdenacao>& algoritmo)
{
    if (dynamic_cast<BubbleSortIterativo*>(algoritmo.get()))
        return "Bubble Sort Iterativo";
    if (dynamic_cast<BubbleSortRecursivo*>(algoritmo.get()))
        return "Bubble Sort Recursivo";
    if (dynamic_cast<QuickSortIterativo*>(algoritmo.get()))
        return "Quick Sort Iterativo";
    if (dynamic_cast<QuickSortRecursivo*>(algoritmo.get()))
        return "Quick Sort Recursivo";
    if (dynamic_cast<MergeSortIterativo*>(algoritmo.get()))
        return "Merge Sort Iterativo";
    if (dynamic_cast<MergeSortRecursivo*>(algoritmo.get()))
        return "Merge Sort Recursivo";
    if (dynamic_cast<BuscaLinear*>(algoritmo.get()))
        return "Busca Linear";
    if (dynamic_cast<BuscaBinaria*>(algoritmo.get()))
        return "Busca Binária";
    if (dynamic_cast<BuscaBinariaRecursiva*>(algoritmo.get()))
        return "Busca Binária Recursiva";
    return "Algoritmo desconhecido";
}

std::string Utilitarios::tipoDeAlgoritmoBusca(const std::unique_ptr<StrategyBusca>& algoritmo)
{
    if (dynamic_cast<BuscaLinear*>(algoritmo.get()))
        return "Busca Linear";
    if (dynamic_cast<BuscaBinaria*>(algoritmo.get()))
        return "Busca Binária";
    if (dynamic_cast<BuscaBinariaRecursiva*>(algoritmo.get()))
        return "Busca Binária Recursiva";
    return "Algoritmo desconhecido";
}

std::vector<int> Utilitarios::clonarVetor(const std::vector<int> &vetorOriginal)
{
    return vetorOriginal;
}

void Utilitarios::executarEGravarOrdenacao(std::unique_ptr<StrategyOrdenacao> algoritmo,
                                           std::vector<int> vetorParaOrdenar,
                                           MedicaoDeTempo &medicao, bool exibirVetorNaSaida)
{
    std::string algoritmoNome = tipoDeAlgoritmoOrdenacao(algoritmo);
    std::cout << "Executando " << algoritmoNome << "...\n";
    EscritaDeArquivos::gravarEmArquivo("Executando " + algoritmoNome + "...\n");
    EscritaDeArquivos::gravarEmArquivo(medicao.medirOrdenacao(std::move(algoritmo), vetorParaOrdenar, 
                                       vetorParaOrdenar.size(), exibirVetorNaSaida));
}

void Utilitarios::executarEgravarBusca(std::unique_ptr<StrategyBusca> algoritmo, 
                                       std::vector<int> vetor, 
                                       int valorParaBuscar, 
                                       MedicaoDeTempo& medicao, bool exibirVetorNaSaida)
{
    std::string algoritmoNome = tipoDeAlgoritmoBusca(algoritmo);
    std::string mensagem = "Executando Busca Binária...\n";
    std::cout << "Executando " << algoritmoNome << "...\n";
    EscritaDeArquivos::gravarEmArquivo("Executando " + algoritmoNome + "...\n");
    std::sort(vetor.begin(), vetor.end());

    EscritaDeArquivos::gravarEmArquivo(medicao.medirBusca(std::move(algoritmo), vetor, valorParaBuscar, vetor.size(), exibirVetorNaSaida));
}

std::vector<int> Utilitarios::gerarImprimirEGravarVetor(int tamanho,
                                                        int VALOR_MINIMO,
                                                        int VALOR_MAXIMO)
{
    std::vector<int> vetor = gerarVetorAleatorio<int>(tamanho, VALOR_MINIMO, VALOR_MAXIMO);
    std::string vetorGerado = "O vetor gerado foi: \n" + EscritaDeArquivos::vetorParaString(vetor) + "\n";
    std::cout << vetorGerado;
    std::string tamanhoMensagem = "\nTamanho do vetor: " + std::to_string(tamanho) + "\n";
    std::cout << tamanhoMensagem;
    EscritaDeArquivos::gravarEmArquivo(tamanhoMensagem);
    return vetor;
}

size_t Utilitarios::obterNumero()
{
    size_t numero;
    while (true)
    {
        if (std::cin >> numero)
        {
            if (numero >= 0)
                return numero;
        }
        else
        {
            std::cerr << "Entrada inválida. Por favor, insira um número inteiro.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

bool Utilitarios::verificarEntradaYS()
{
    char opcao;
    while (true)
    {
        std::cout << "Você gostaria de ver o vetor no arquivo de saída (Y/N)? ";
        std::cin >> opcao;

        if (opcao == 'Y' || opcao == 'y')
        {
            return true;
        }
        else if (opcao == 'N' || opcao == 'n')
        {
            return false;
        }
        else
        {
            std::cout << "Entrada inválida. Por favor, insira 'Y' para sim ou 'S' para não.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}