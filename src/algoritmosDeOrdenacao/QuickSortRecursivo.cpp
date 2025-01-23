#include "QuickSortRecursivo.h"

void QuickSortRecursivo::ordenar(std::vector<int> &lista, int tamanhoLista)
{
    quickSort(lista, 0, tamanhoLista - 1);
}

void QuickSortRecursivo::quickSort(std::vector<int> &lista, int esquerda, int direita)
{
    if (esquerda < direita)
    {
        int pivo = particionar(lista, esquerda, direita);

        quickSort(lista, esquerda, pivo - 1);

        quickSort(lista, pivo + 1, direita);
    }
}

int QuickSortRecursivo::particionar(std::vector<int> &lista, int esquerda, int direita)
{
    int i = esquerda - 1;
    int pivo = lista[direita];

    for (int j = esquerda; j < direita; j++)
    {
        if (lista[j] <= pivo)
        {
            i++;
            std::swap(lista[i], lista[j]);
        }
    }
    std::swap(lista[i + 1], lista[direita]);
    return i + 1; // Retorna a posição do pivô
}
