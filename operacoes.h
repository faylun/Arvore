#ifndef OPERACOES_H_INCLUDED
#define OPERACOES_H_INCLUDED

using namespace std;

void criaArquivo(int qtdeDados){
    string diretorio, nomeArquivo;
    int dado;
    cout<<"Informe o diretorio do arquivo: ";
    getline(cin, diretorio);
    nomeArquivo = diretorio +  '\\' + "dadosEmOrdemCrescente.txt";

    ofstream  fout(nomeArquivo);
    for(int i=0; i<qtdeDados; i++){
        fout<<i+1<<"\n";
    }
    fout.close();
}

void leituraArquivo(int qtdeDados){
    ifstream fin;
    char ch;
    string nomeArquivo, diretorio, caminhoArq;
    cout<<"Informe o nome do diretorio: ";
    getline(cin,diretorio);
    cout<<"Informe o nome do arquivo: ";
    getline(cin,nomeArquivo);
    caminhoArq = diretorio + '\\' + nomeArquivo;

    fin.open(caminhoArq);
    if(!fin)
        cout << "\nNao posso abrir arquivo copia.xxx\n";
    else{
        cout << "\nArquivo aberto com sucesso\n";
        while(fin.get(ch))
            cout << ch;
        fin.close();
    }
}

float valorRelativo(float valorAtual, float valorMaximo){
    return (valorAtual/valorMaximo) * 100;
}

void exibeVetor(int vet[], int tamanho){
    for (int i = 0; i < tamanho; i++)
        cout << "[" << vet[i] << "]";
    cout << "\n";
}
#endif // OPERACOES_H_INCLUDED
