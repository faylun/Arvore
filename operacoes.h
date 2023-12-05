#ifndef OPERACOES_H_INCLUDED
#define OPERACOES_H_INCLUDED
#include "shellsort.h"
#include <iomanip>

using namespace std;

void criaArquivo(int qtdeDados)
{
    string diretorio, nomeArquivo;
    int opcao;

    do
    {
        cout<<"\n1.Criar arquivo no diretorio fonte\n2.Criar arquivo em diretorio externo\n3.Arquivo existente\n\nSelecione a opcao: ";
        cin>>opcao;
    }
    while(opcao>3 || opcao<1);
    cin.ignore();

    if(opcao == 1)
        nomeArquivo = "dados.txt";
    else if(opcao == 2)
    {
        cout<<"\nInforme o diretorio do arquivo: ";
        getline(cin, diretorio);
        nomeArquivo = diretorio +  '\\' + "dados.txt";
    }else{
        cout<<"\n"<<endl;
        return;
    }

    ofstream  outputFile(nomeArquivo);
    for(int i=0; i<qtdeDados; i++)
        outputFile<<i+1<<"\n";

    outputFile.close();
    cout<<"\nArquivo criado com sucesso em: "<<nomeArquivo<<"!\n"<<endl;
}

string leituraArquivo(int vet[], int qtdeDados)
{
    ifstream inputFile;
    string caminho = "", diretorio, nomeArquivo;
    int n=0, opcao, valor;
    do
    {
        cout<<"\nSelecione a origem dos dados\n1.Ler arquivo do diretorio fonte\n2.Ler arquivo de um diretorio externo\nOpcao: ";
        cin>>opcao;
    }
    while(opcao>2 || opcao<1);
    cin.ignore();

    if(opcao == 2)
    {
        cout<<"\nInforme o diretorio do arquivo: ";
        getline(cin, diretorio);
        caminho = diretorio +  '\\' ;
    }
    cout<<"\nInforme o nome do arquivo: ";
    getline(cin,nomeArquivo);
    caminho += nomeArquivo;
    inputFile.open(caminho);
    if(!inputFile)
        throw "Erro ao abrir o arquivo" ;
    else
    {
        while (inputFile >> valor && n < qtdeDados)
        {
            vet[n++] = valor;
        }
        inputFile.close();
        cout << "\nArquivo aberto com sucesso!\n";
    }
    return caminho;
}

void gravaNoRelatorio(int n, int comp, int mov, float compRelativa, float movRelativa, string ordenacao, int ordem) {
    ofstream relatorio("relatorio.txt", ios_base::app);

    if (!relatorio.is_open()) {
        cerr << "Erro ao abrir o arquivo de relatório." << endl;
        return;
    }
    // Adicione informações ao relatório conforme necessário
    relatorio << "\n\n-=-=-=-=--=-=-=-=--=-=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=-=-=-=-=-= " << ordenacao << " -=-=-=-=--=-=-=-=--=-=-=-=-=--=-=-=-=--=-=-=-=--=-=-=-=-=-=-=-=-=\n";
    if(ordenacao == "SHELL SORT"){
        string modelo;
        if(ordem == 1)
            modelo = "CRESCENTE";
        else if(ordem == 2)
            modelo = "DECRESCENTE";
        else
            modelo = "ALEATORIO";
        relatorio << "\n|\tOrdem Original dos dados: "<< modelo<<"\n";
    }

    relatorio << "\n" << "+---------------------------------+-----------------------+------------------------+----------------------------+-------------------------------+";
    relatorio << "\n|\tQuantidade de dados\t  |\t  Comparação\t  |\t  Movimentação\t   |\t  Comparação Relat. \t|\t  Movimentação Relat.\t|\n\n";
    relatorio << "|        \t" << n << "\t\t  |\t    " << comp << "\t\t  |\t    " << mov << "\t\t   |\t\t " << fixed << setprecision(2) << compRelativa << "\t\t|\t\t"  << fixed << setprecision(2) << movRelativa << "\t\t|\n\n";
    relatorio << "+---------------------------------+-----------------------+------------------------+----------------------------+-------------------------------+" << "\n";
    relatorio.close();
    mov = 0;
    comp = 0;
}

float encontrarMaior(float a,float  b, float  c){
    float maior = a;

    if(b > maior)
        maior = b;

    if(c > maior)
        maior = c;

    return maior;
}

float valorRelativo(float valorAtual, float valorMaximo)
{
    return (valorAtual/valorMaximo) * 100;
}

void exibeVetor(int vet[], int tamanho)
{
    cout<<"[ ";
    for (int i = 0; i < tamanho; i++)
    {
        cout << vet[i];
        if(i <tamanho -1)
            cout << ", ";
    }
    cout << "]\n";
}

void transformaOrdemAleatoria(int vet[], int qtdeDados)
{
    srand(time(0));

    for (int i = 0; i < qtdeDados; i ++)
    {
        int j = rand() % qtdeDados;

        int temp = vet[i];
        vet[i] = vet[j];
        vet[j] = temp;
    }
}

void organizaOrdemInicial(int vetor[], int ordem, int qtdeDados)
{
    int c = 0, m = 0 ;
    if(ordem == 2)
        shellSort(vetor,qtdeDados,c,m);
    else if(ordem == 3)
        transformaOrdemAleatoria(vetor,qtdeDados);
}

void resetaVetor(int vetor[], int aux[], int qtdeDados)
{
    for(int i=0; i<qtdeDados; i++)
    {
        aux[i] = vetor[i];
    }
}

void resetaContadores(int &c, int &m)
{
    c = 0;
    m = 0;
}
#endif // OPERACOES_H_INCLUDED
