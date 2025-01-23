#include "BuscaBinaria.h"

int BuscaBinaria::buscar(const std::vector<int> &lista, int valor, int tamanho)
{
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        if (lista[meio] == valor)
        {
            return meio;
        }
        else if (lista[meio] < valor)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }

    return -1; // Valor não encontrado
}
