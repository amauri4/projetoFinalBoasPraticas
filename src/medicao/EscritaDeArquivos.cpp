#include "EscritaDeArquivos.h"

// Função para gravar logs em um arquivo com quebra de linha a cada 120 caracteres
void EscritaDeArquivos::gravarEmArquivo(const std::string &mensagem, const std::string &caminhoArquivo, size_t limite)
{
    std::ofstream arquivo(caminhoArquivo, std::ios_base::app);
    if (arquivo.is_open())
    {
        size_t pos = 0;
        size_t mensagemTamanho = mensagem.length();

        // Escreve no arquivo de forma que, a cada 120 caracteres, seja inserida uma quebra de linha
        while (pos < mensagemTamanho)
        {
            size_t proximoLimite = std::min(pos + limite, mensagemTamanho);
            arquivo << mensagem.substr(pos, proximoLimite - pos);
            pos = proximoLimite;
            if (pos < mensagemTamanho)
            {
                arquivo << std::endl;
            }
        }
    }
    else
    {
        std::cerr << "Erro ao abrir o arquivo de log." << std::endl;
    }
}
