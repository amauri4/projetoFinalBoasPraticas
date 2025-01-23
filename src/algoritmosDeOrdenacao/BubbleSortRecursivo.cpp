#include "BubbleSortRecursivo.h"

void BubbleSortRecursivo::ordenar(std::vector<int> &lista, int tamanhoDaLista)
{
    // Se o tamanho for menor que 2, não há nada para ordenar.
    if (tamanhoDaLista < 2)
    {
        return;
    }
    bool houveTroca = false;

    for (int i = 0; i < tamanhoDaLista - 1; i++)
    {
        if (lista[i] > lista[i + 1])
        {
            int temp = lista[i];
            lista[i] = lista[i + 1];
            lista[i + 1] = temp;
            houveTroca = true;
        }
    }
    // Se não houve troca, a lista está ordenada
    if (houveTroca == false)
    {
        return;
    }

    BubbleSortRecursivo::ordenar(lista, tamanhoDaLista - 1);
}
