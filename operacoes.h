#ifndef OPERACOES_H_INCLUDED
#define OPERACOES_H_INCLUDED

using namespace std;

void criaArquivo(int qtdeDados)
{
    string diretorio, nomeArquivo;
    int opcao;

    do
    {
        cout<<"\n1.Criar arquivo no diretorio fonte\n2.Criar arquivo em diretorio externo\nSelecione a opcao: ";
        cin>>opcao;
    }
    while(opcao>2 || opcao<1);
    cin.ignore();

    if(opcao == 2)
    {
        cout<<"Informe o diretorio do arquivo: ";
        getline(cin, diretorio);
        nomeArquivo = diretorio +  '\\' + "dados.txt";
    }
    else
        nomeArquivo = "dados.txt";

    ofstream  outputFile(nomeArquivo);
    for(int i=0; i<qtdeDados; i++)
        outputFile<<i+1<<"\n";

    outputFile.close();
    cout<<"\nArquivo criado com sucesso em: "<<nomeArquivo<<"!\n"<<endl;
}

void leituraArquivo(int vet[], int qtdeDados)
{
    ifstream inputFile;
    string caminho = "", diretorio, nomeArquivo;
    int n=0, opcao, valor;
    do
    {
        cout<<"\n1.Ler arquivo do diretorio fonte\n2.Ler arquivo de um diretorio externo\nSelecione a opcao: ";
        cin>>opcao;
    }
    while(opcao>2 || opcao<1);
    cin.ignore();

    if(opcao == 2)
    {
        cout<<"Informe o diretorio do arquivo: ";
        getline(cin, diretorio);
        caminho = diretorio +  '\\' ;
    }
    cout<<"Informe o nome do arquivo: ";
    getline(cin,nomeArquivo);
    caminho += nomeArquivo;
    cout<<caminho<<endl;
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
        cout << "\nArquivo aberto com sucesso\n";
    }
}

float valorRelativo(float valorAtual, float valorMaximo)
{
    return (valorAtual/valorMaximo) * 100;
}

void exibeVetor(int vet[], int tamanho)
{

    for (int i = 0; i < tamanho; i++)
        cout << "[" << vet[i] << "]";
    cout << "\n";
}

void transformaOrdemAleatoria(int vet[], int n){
    srand(time(0));

    for (int i = 0; i < n; i ++){
        int j = rand() % n;

        int temp = vet[i];
        vet[i] = vet[j];
        vet[j] = temp;
    }
}
#endif // OPERACOES_H_INCLUDED
