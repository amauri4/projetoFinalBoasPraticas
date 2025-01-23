#ifndef ESCRITAADEARQUIVOS_H
#define ESCRITAADEARQUIVOS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <sstream>
#include <type_traits>

/**
 * @class EscritaDeArquivos
 * @brief Classe para manipulação de arquivos, incluindo funções de gravação e conversão de vetores em string.
 */
class EscritaDeArquivos
{
public:
    /**
     * @brief Converte um vetor de inteiros para uma string.
     *
     * Esta função percorre todos os elementos do vetor e os converte para uma string, com cada valor
     * separado por espaço.
     *
     * @param vetor Vetor de inteiros a ser convertido em string.
     * @return A string resultante da conversão do vetor.
     */
    template <typename T>
    static std::string vetorParaString(std::vector<T> &vetor)
    {
        std::ostringstream oss;

        if (std::is_arithmetic<T>::value)
        {
            // Para tipos numéricos, converte com std::to_string
            for (const auto &elemento : vetor)
            {
                oss << elemento << " ";
            }
        }
        else
        {
            // Para outros tipos, concatena diretamente
            for (const auto &elemento : vetor)
            {
                oss << elemento << " ";
            }
        }

        return oss.str();
    }

    /**
     * @brief Grava uma mensagem em um arquivo com quebras de linha a cada 120 caracteres.
     *
     * A função escreve no arquivo passado como parâmetro ou no arquivo padrão `../saida.txt`. Caso a
     * mensagem tenha mais de 120 caracteres (padrão), ela será quebrada em várias linhas. Caso o arquivo não exista,
     * ele será criado. Caso contrário, a mensagem será adicionada ao final do arquivo.
     *
     * @param mensagem A mensagem a ser gravada no arquivo.
     * @param caminhoArquivo Caminho do arquivo onde a mensagem será gravada (padrão: `../saida.txt`).
     */
    static void gravarEmArquivo(const std::string &mensagem, const std::string &caminhoArquivo = "../saida.txt", size_t limite = 120);
};

#endif // ESCRITAADEARQUIVOS_H
