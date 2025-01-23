#include "QuickSortIterativo.h"
#include <stack>

void QuickSortIterativo::ordenar(std::vector<int> &lista, int tamanho)
{
    std::stack<int> pilha;

    pilha.push(0);
    pilha.push(tamanho - 1);

    while (!pilha.empty())
    {
        int direita = pilha.top();
        pilha.pop();
        int esquerda = pilha.top();
        pilha.pop();

        int pivo = particionar(lista, esquerda, direita);

        // Adiciona as subpartes à esquerda e à direita do pivô na pilha, se necessário
        if (pivo - 1 > esquerda)
        {
            pilha.push(esquerda);
            pilha.push(pivo - 1);
        }
        if (pivo + 1 < direita)
        {
            pilha.push(pivo + 1);
            pilha.push(direita);
        }
    }
}

int QuickSortIterativo::particionar(std::vector<int> &lista, int inicio, int fim)
{
    int i = inicio - 1;
    int pivo = lista[fim];

    for (int j = inicio; j < fim; j++)
    {
        if (lista[j] <= pivo)
        {
            i++;
            std::swap(lista[i], lista[j]);
        }
    }
    std::swap(lista[i + 1], lista[fim]);
    return i + 1;
}
