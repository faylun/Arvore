#include <iostream>
#include <fstream>
#include <time.h>
#include "operacoes.h"
#include "shellsort.h"
#include "QuickSort.h"
#include "InsertionSort.h"
#define TMAX 10000

using namespace std;
int main()
{
    srand(time(NULL));
    bool continuar = true;
    int opcao, ordem, qtdeDados, c, m;
    int aux[TMAX];


    cout<<"=-=-=-= CRIACAO DO ARQUIVO =-=-=-="<<endl;
    criaArquivo(TMAX);
    system("pause");
    system("cls");

    do
    {
        cout<<"=-=-=-=-=-=-=- MENU -=-=-=-=-=-=-=\n"<<endl;
        do
        {
            cout<<" 1.Iniciar Simulacao\n 2.Sair do programa\n\nSelecione a opcao: ";
            cin>>opcao;
        }
        while(opcao>2 || opcao<1);
        system("cls");
        switch(opcao)
        {
        case 1:
        {
            cout<<"-~-~-~-~-~-~-~- ORDENACAO DE DADOS -~--~-~-~-~-~-~-\n"<<endl;
            do
            {
                cout<<"Informe a quantidade de dados para a simulacao (1 - 10.000): ";
                cin>>qtdeDados;
            }
            while(qtdeDados>10000 || qtdeDados<1);

            int dadosOriginais[qtdeDados];
            cout<<"\n-~-~-~-~-~-~-~- LEITURA DOS DADOS  -~--~-~-~-~-~-~-"<<endl;
            leituraArquivo(dadosOriginais,qtdeDados);
            cout<<"\n-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-"<<endl;

            do
            {
                cout<<"\nInforme a organizacao incial dos dados: "<<endl;
                cout<<"1.Crescente\n2.Decrescente\n3.Aleatoria\nSelecione a opcao: ";
                cin>>ordem;
            }
            while(ordem>3 || ordem<1);
            organizaOrdemInicial(dadosOriginais, ordem, qtdeDados);
            resetaVetor(dadosOriginais,aux,qtdeDados);
            system("pause");
            system("cls");

            cout<<"\n-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~--~-~-~-~-~-~-~-~- "<<endl;
            cout<<"Organizacao Inicial dos dados: "<<endl;
            exibeVetor(dadosOriginais,qtdeDados);

            float compMax, movMax;

            resetaVetor(dadosOriginais,aux,qtdeDados);
            resetaContadores(c,m);
            shellSort(aux,qtdeDados,c,m);
            int cShell = c;
            int mShell = m;
            cout<<"\n\n * SHELLSORT   \nC: "<<cShell<<" | M: "<<mShell<<endl; //teste
            exibeVetor(aux,qtdeDados); //teste

            resetaVetor(dadosOriginais, aux, qtdeDados);
            resetaContadores(c,m);
            insertionSort(aux,qtdeDados,c,m);
            int cInsert = c;
            int mInsert = m;
            cout<<"\n\n * INSERTSORT   \nC: "<<cInsert<<" | M: "<<mInsert<<endl; //teste

            exibeVetor(aux,qtdeDados);//teste

            resetaVetor(dadosOriginais, aux, qtdeDados);
            resetaContadores(c,m);
            quickSort(aux,0,qtdeDados-1,c,m);
            int cQuick = c;
            int mQuick = m;
            cout<<"\n\n * QUICKSORT   \nC: "<<cQuick<<" | M: "<<mQuick<<endl;//teste
            exibeVetor(aux,qtdeDados);//teste

            /*
                exemplo de analise de comparacao sla
                compMax = encontrarMaior(cShell, cInsert, cQuick);
                movMax = encontraMaior(mShell, mInsert, mQuick);

                compHeap = valorRelativo(compHeap, compMax);
                compMerge = valorRelativo(compMerge, compMax);
                break;
            }*/
            gravaNoRelatorio( qtdeDados, cShell, mShell, "SHELL SORT", ordem);
            gravaNoRelatorio( qtdeDados, cInsert, mInsert, "INSERTION SORT",ordem);
            gravaNoRelatorio( qtdeDados, cQuick, mQuick, "QUICK SORT",ordem);
            break;
        }
        case 2:

            cout<<"\nFinalizando sistema...\nVolte Sempre!"<<endl;
            continuar = false;
            break;
        }

        system("pause");
        system("cls");

    }
    while(continuar);

    return 0;
}
