#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED

using namespace std;

using namespace std;

void troca(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int particiona(int vet[], int esq, int dir, int &mov, int &comp) {
    int pivo = vet[dir];
    int i = (esq - 1);

    for (int j = esq; j <= dir - 1; j++) {
        comp++;
        if (vet[j] > pivo) {  // Modificação aqui para ordenação decrescente
            i++;
             troca(&vet[i], &vet[j]);
            mov++;
        }
    }
    troca(&vet[i + 1], &vet[dir]);
    mov++;
    return (i + 1);
}

void quickSort(int vet[], int esq, int dir, int &comp, int &mov) {
    dir--;
    if (esq < dir) {
        int pi = particiona(vet, esq, dir, mov, comp);
        quickSort(vet, esq, pi - 1, comp, mov);
        quickSort(vet, pi + 1, dir, comp, mov);
    }
}


#endif // QUICKSORT_H_INCLUDED
