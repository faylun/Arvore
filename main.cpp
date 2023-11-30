#include <iostream>
#include <fstream>
#define TMAX 10000

using namespace std;

int main()
{
    ifstream fin;
    int opcao, subopcao,qtdeDados, numComp, numMov; //ordenação decrescente de dados
    string nomeArquivo, diretorio, caminhoArq;
    char ch;

    //podemos deixar essa entrada para o usuário inserir onde ele quer colocar o aqrquibo
    ofstream fout("dados.txt");
    for(int i=0; i<TMAX; i++){
        fout<<i+1<<"\n";
    }
    fout.close();

    cout<<"Informe o nome do diretorio: ";
    getline(cin,diretorio);
    cout<<"Informe o nome do arquivo: ";
    getline(cin,nomeArquivo);
    caminhoArq = diretorio + "\" + nomeArquivo;
    cout<<caminhoArq<<endl;
    fin.open("dados.txt");  //depois inserir o caminho do arquivo aqui
    if(!fin)
        cout << "\nNao posso abrir arquivo copia.xxx\n";
    else
    {  //teste para leitura
         cout << "\nArquivo aberto com sucesso\n";
        while(fin.get(ch))
            cout << ch;
        fin.close();
    }
    return 0;
}
