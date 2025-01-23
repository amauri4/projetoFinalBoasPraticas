#include "BubbleSortIterativo.h"

void BubbleSortIterativo::ordenar(std::vector<int> &lista, int tamanhoLista)
{
    int tamanhoDoVetor = lista.size();

    int temporario;

    // For para percorrer o número de passagens
    for (int i = 0; i < tamanhoDoVetor - 1; i++)
    {
        bool houveTroca = false;

        // For para realizar trocas
        for (int j = 0; j < (tamanhoDoVetor - i - 1); j++)
        {
            if (lista[j] > lista[j + 1])
            {
                temporario = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temporario;
                houveTroca = true;
            }
        }

        // Se não houver troca, a lista já está ordenada
        if (!houveTroca)
        {
            break;
        }
    }
}
