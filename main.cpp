#include <iostream>
#include <fstream>
#include "operacoes.h"
#define TMAX 10000

using namespace std;

int main()
{
    bool continuar = true;
    int opcao, subopcao,qtdeDados, numComp, numMov; //ordenação decrescente de dados

    cout<<"=-=-=-= CRIAÇÃO DO ARQUIVO =-=-=-=\n"<<endl;
    criaArquivo(TMAX);


    do{
       cout<<"=-=-=-=-=-=-=-= MANIPULAÇÃO DOS DADOS =-=-=-=-=-=-=-="<<endl;
       do{
            cout<<"1.Iniciar Simulação\n2.Sair do programa"<<endl;
            cin>>opcao;
       }while(opcao>2 || opcao<1);
       system("cls");

       switch(opcao){
       case 1:
           do{
                cout<<"Informe a quantidade de dados para a simulação (1 - 10.000): ";
                cin>>qtdeDados;
           }while(qtdeDados>10.000 || qtdeDados<1);
           int dados[qtdeDados];   //aqui declaramos o vetor que irá armazenar as informações
           do{
                cout<<"Informe a organizacao incial dos dados: "<<endl;
                cout<<"1.Crescente\n2.Decrescente\n3.Aleatoria\nOpcao: ";
                cin>>subopcao;
           }while(subopcao>3 || subopcao<1);
            //EM DESENVOLVIMENTO
           break;
       }


    }while(continuar);

    return 0;
}
