#include "BuscaBinariaRecursiva.h"

int BuscaBinariaRecursiva::buscar(const std::vector<int> &lista, int valor, int tamanho)
{
    return buscarRecursivo(lista, valor, 0, tamanho - 1);
}

int BuscaBinariaRecursiva::buscarRecursivo(const std::vector<int> &lista, int valor, int inicio, int fim)
{
    if (inicio > fim)
    {
        return -1; // Valor não encontrado
    }

    int meio = inicio + (fim - inicio) / 2;

    if (lista[meio] == valor)
    {
        return meio;
    }
    else if (lista[meio] > valor)
    {
        return buscarRecursivo(lista, valor, inicio, meio - 1); // Busca na metade direita
    }
    else
    {
        return buscarRecursivo(lista, valor, meio + 1, fim); // Busca na metade esquerda
    }
}
