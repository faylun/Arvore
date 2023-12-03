#ifndef SHELLSORT_H_INCLUDED
#define SHELLSORT_H_INCLUDED


/*OBJETIVO: comparar e trocar elementos que estão distantes
uns dos outros em vez de apenas elementos adjacentes
envolve dividir a lista em subgrupos menores
e aplicar o Insertion Sort em cada subgrupo.*/


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

void exibeShellSort(int vet[], int n)
{
    for (int i = 0; i < n; i++)
        cout << "[" << vet[i] << "]";
    cout << "\n";
}

#endif // SHELLSORT_H_INCLUDED
