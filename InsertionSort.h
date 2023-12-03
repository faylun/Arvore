#ifndef INSERTIONSORT_H_INCLUDED
#define INSERTIONSORT_H_INCLUDED


using namespace std;

void insertionSort(int vet[], int n, int &comp, int &mov){
    for (int i = 1; i < n; i++) {
        int key = vet[i];
        int j = i - 1;
        comp++;
        while (j >= 0 && vet[j] < key) {
            comp++;
            vet[j + 1] = vet[j];
            j = j - 1;
            mov++;
        }
        vet[j + 1] = key;
    }
}

void exibirInsertionSort(int vet[], int n){
    for (int  i = 0; i < n; i++)
        cout << "[" << vet[i] << "]";
    cout << "\n";
}
#endif // INSERTIONSORT_H_INCLUDED
