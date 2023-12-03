#ifndef SHELLSORT_H_INCLUDED
#define SHELLSORT_H_INCLUDED

using namespace std;

void shellSort(int vet[], int tamanho, int &c, int &m)
{
    for (int gap = tamanho / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < tamanho; i ++)
        {
            int temp = vet[i];
            int j;
            for (j = i; j >= gap && vet[j - gap] < temp; j -= gap)
            {
                vet[j] = vet[j - gap];
                c++;
            }
            vet[j] = temp;
            c++;
        }
    }
}

#endif // SHELLSORT_H_INCLUDED
