#include "MergeSortIterativo.h"

void MergeSortIterativo::ordenar(std::vector<int> &lista, int tamanho)
{
    int tamanhoAtual;   // Controlador do tamanho da sublista
    int inicioEsquerda; // Índice da sublista à esquerda

    for (tamanhoAtual = 1; tamanhoAtual < tamanho; tamanhoAtual = 2 * tamanhoAtual)
    {
        for (inicioEsquerda = 0; inicioEsquerda < tamanho; inicioEsquerda += 2 * tamanhoAtual)
        {
            int meio = std::min(inicioEsquerda + tamanhoAtual - 1, tamanho - 1);
            int fimDireita = std::min(inicioEsquerda + 2 * tamanhoAtual - 1, tamanho - 1);
            MergeSortIterativo::merge(lista, inicioEsquerda, meio, fimDireita);
        }
    }
}

void MergeSortIterativo::merge(std::vector<int> &lista, int inicio, int meio, int fim)
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

    // Mescla os subvetores de volta na lista original
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
