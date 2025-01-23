#include "MergeSortRecursivo.h"

void MergeSortRecursivo::ordenar(std::vector<int> &lista, int tamanhoDoVetor)
{
    mergeSort(lista, 0, lista.size() - 1);
}

void MergeSortRecursivo::merge(std::vector<int> &lista, int inicio, int meio, int fim)
{
    int tamanhoEsquerda = meio - inicio + 1;
    int tamanhoDireita = fim - meio;

    std::vector<int> sublistaEsquerda(tamanhoEsquerda), sublistaDireita(tamanhoDireita);

    for (int i = 0; i < tamanhoEsquerda; i++)
    {
        sublistaEsquerda[i] = lista[inicio + i];
    }
    for (int j = 0; j < tamanhoDireita; j++)
    {
        sublistaDireita[j] = lista[meio + 1 + j];
    }

    int i = 0, j = 0, k = inicio;

    while (i < tamanhoEsquerda && j < tamanhoDireita)
    {
        if (sublistaEsquerda[i] <= sublistaDireita[j])
        {
            lista[k] = sublistaEsquerda[i];
            i++;
        }
        else
        {
            lista[k] = sublistaDireita[j];
            j++;
        }
        k++;
    }

    while (i < tamanhoEsquerda)
    {
        lista[k] = sublistaEsquerda[i];
        i++;
        k++;
    }

    while (j < tamanhoDireita)
    {
        lista[k] = sublistaDireita[j];
        j++;
        k++;
    }
}

void MergeSortRecursivo::mergeSort(std::vector<int> &lista, int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = inicio + (fim - inicio) / 2;
        mergeSort(lista, inicio, meio);
        mergeSort(lista, meio + 1, fim);
        merge(lista, inicio, meio, fim);
    }
}
