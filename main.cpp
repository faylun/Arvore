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
    int opcao, subopcao,qtdeDados = 10, numComp, numMov; //ordenação decrescente de dados


    cout<<"=-=-=-= CRIACAO DO ARQUIVO =-=-=-="<<endl;
    criaArquivo(TMAX);
    system("pause");
    system("cls");

    int dados[TMAX];
    try
    {
        leituraArquivo(dados,qtdeDados);
        exibeVetor(dados,qtdeDados);

        cout<<"\n\nORDEM ALEATORIA"<<endl;
        transformaOrdemAleatoria(dados, qtdeDados);
        exibeVetor(dados,qtdeDados);
    }
    catch (const char* msg)
    {
        cerr<<msg<<endl;
    }

    /*
        do{
           cout<<"=-=-=-=-=-=-=-= MANIPULACAO DOS DADOS =-=-=-=-=-=-=-="<<endl;
           do{
                cout<<"1.Iniciar Simulacao\n2.Sair do programa\nOpcao: ";
                cin>>opcao;
           }while(opcao>2 || opcao<1);
           system("cls");

           switch(opcao){
           case 1:
               do{
                    cout<<"Informe a quantidade de dados para a simulacao (1 - 10.000): ";
                    cin>>qtdeDados;
               }while(qtdeDados>10000 || qtdeDados<1);
               int dados[qtdeDados];   //aqui declaramos o vetor que irá armazenar as informações


               do{
                    cout<<"Informe a organizacao incial dos dados: "<<endl;
                    cout<<"1.Crescente\n2.Decrescente\n3.Aleatoria\nOpcao: ";
                    cin>>subopcao;
               }while(subopcao>3 || subopcao<1);

               break;
           }

        }while(continuar);*/

    return 0;
}
