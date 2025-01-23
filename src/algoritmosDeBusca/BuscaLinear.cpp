#include "BuscaLinear.h"

int BuscaLinear::buscar(const std::vector<int> &lista, int valor, int tamanho)
{
    for (int i = 0; i < tamanho; ++i)
    {
        if (lista[i] == valor)
        {
            return i;
        }
    }
    return -1;
}
