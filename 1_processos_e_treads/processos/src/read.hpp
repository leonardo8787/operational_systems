#ifndef READ_H_
#define READ_H_

#include "includes.hpp"
#define TAM 100

vector<string> a;
vector<vector<string>> combinacoes;
vector<string> recebe;
vector<string> tokens;
queue<string> fila;
vector<string> v0;
vector<string> permutacoes;
vector<string> v;
unordered_map<string, vector<string>> texto;
vector<string> v2;
unordered_map<string, vector<string>> texto2;
vector<string> v3;
unordered_map<string, vector<string>> texto3;
set<string, string> nomes;

class Ler{
    public:
        void ler();
        void ler2();
        void poeNaFilaALinha();
        void combinacao();
        void processaFila();
        void escreveCombinacao();
        void Hash();
        void Hash2();
        void HashNomes1();
        void HashNomes2();
        void Token();
        void Task();
};

void ler(){

    ifstream file1;
    file1.open("src/dataset/D.csv");

	//vector<string> token;
	//unordered_map<string, int> umap;

    string palavra;
    string key;
    char *output;
    char *token;
    int coluna=1;
    int linha=1;
    string linhaStr;

    if (!file1){
        cout<<"o arquivo 1 não pode ser aberto, o programa será fechado!"<<endl;
        return;
    }
 
    int cont=0;
    while(file1){
        if (coluna==4) coluna=1;
        getline(file1, palavra);
        cout<<"\n";
        cont++;
        cout<<cont<<"° - linha"<<endl;
        cout<<"{"<<palavra<<"}"<<endl;
        output = const_cast<char *>(palavra.c_str());
        token = strtok(output, ",");
        while (token != NULL){
            if (coluna==4) break;
            key = string(token);
            linhaStr=to_string(linha);
            texto[key].push_back(linhaStr);
            token = strtok(NULL, ",");
            coluna++;
        }
        linha++;
    }

    getchar();
    getchar();

    file1.close();
}
/*
void ler2(){

    ifstream file2;
    file2.open("src/dataset/T.csv");

	//vector<string> token;
	//unordered_map<string, int> umap;

    string palavra;
    string key;
    char *output;
    char *token;
    int coluna=1;
    int linha=1;

    if (!file2){
        cout<<"o arquivo 2 não pode ser aberto, o programa será fechado!"<<endl;
        return;
    }

    int cont=0;
    while(file2){
        if (coluna==4) coluna=1;
        getline(file2, palavra);
        cout<<"\n";
        cont++;
        cout<<cont<<"° - linha"<<endl;
        cout<<"{"<<palavra<<"}"<<endl;
        output = const_cast<char *>(palavra.c_str());
        token = strtok(output, ",");
        while (token != NULL){
            if (coluna==4) break;
            key = to_string(coluna) + ", " + string(token);
            texto2[key].push_back(linha);
            token = strtok(NULL, ",");
            coluna++;
        }
        linha++;
    }

    getchar();
    getchar();

    file2.close();
}
*/
void poeNaFilaALinha(){

    ifstream file;
    file.open("src/dataset/T.csv");

    if (!file){
        cout<<"o arquivo 2 não pode ser aberto, o programa será fechado!"<<endl;
        return;
    }
    
    while(file){ 
        string palavra;
        getline(file, palavra);
        stringstream check1(palavra);
        string intermediate;
        while(getline(check1, intermediate, ','))
        {
            tokens.push_back(intermediate);
        }
        tokens.erase(tokens.end());
    }
    for(int i = 0; i < (int) tokens.size(); i++){ 
        cout << tokens[i] << ' ';
    }
    cout<<endl;


    getchar();
    getchar();

    file.close();
}

void processaFila(){
    for(auto i:tokens){
        for(auto j:texto){
            if(j.f==i){
                recebe.push_back(j.f);
            }
        }
    }
    cout<<"Resultados:"<<endl;
    for(auto k:recebe){
        cout<<k<<endl;
    }
}

void combinacao(){
    vector<string> x;
    for(auto &i:recebe){
        x.push_back(i);
        combinacoes.push_back(x);
    }
    for(auto i:combinacoes){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void escreveCombinacao(){
    string linha;
    ofstream outFile;
    outFile.open("src/dataset/combinacao.txt");
    if(!outFile){
        cout<<"Erro ao gerar o arquivo combinação.txt"<<endl;
        abort();
    }else{
        for(auto i:combinacoes){
            for(auto j:i){
                outFile<<j<<" ";
            }
            cout<<endl;
        }
    }
}

void Hash(){
    int cont=0;
    for (auto mapIt = begin(texto); mapIt != end(texto); ++mapIt){
        cout<<"\n";
        cont++;
        cout<<cont<<"°"<<endl;
        cout << "[" + mapIt->first + "]"
             << " : ";

        cout<<"aparições-> ";
        for (auto c : mapIt->second)
            cout << c << " ";

        cout << endl;
    }
}

void Hash2(){
    int cont=0;
    for (auto mapIt = begin(texto2); mapIt != end(texto2); ++mapIt){
        cout<<"\n";
        cont++;
        cout<<cont<<"°"<<endl;
        cout << "[" + mapIt->first + "]"
             << " : ";

        cout<<"aparições-> ";
        for (auto c : mapIt->second)
            cout << c << " ";

        cout << endl;
    }
}

void HashNomes1(){
    ifstream file1;
    file1.open("src/dataset/D.csv");
    int cont=0;
    while(file1){ 
        string palavra;
        getline(file1, palavra);
        //string line = "GeeksForGeeks is a must try";
        vector <string> tokens;
        stringstream check1(palavra);
        string intermediate;
        while(getline(check1, intermediate, ','))
        {
            tokens.push_back(intermediate);
        }
        //for(int i = 0; i < (int) tokens.size(); i++)
        //    cout << tokens[i] << '\n';
        cout << cont++ << "° : " << tokens[tokens.size()-1] << " " << tokens[tokens.size()] << '\n';
    }

    getchar();
    getchar();

    file1.close();
}

void HashNomes2(){
    ifstream file2;
    file2.open("src/dataset/T.csv");
    int cont=0;
    while(file2){ 
        string palavra;
        getline(file2, palavra);
        vector <string> tokens;
        stringstream check1(palavra);
        string intermediate;
        while(getline(check1, intermediate, ','))
        {
            tokens.push_back(intermediate);
        }
        cout << cont++ << "° : " << tokens[tokens.size()-1] << " " << tokens[tokens.size()] << '\n';
    }

    getchar();
    getchar();

    file2.close();
}

void Token(){
    ifstream file1;
    file1.open("src/dataset/D.csv");
    
    while(file1){ 
        string palavra;
        getline(file1, palavra);
        vector <string> tokens;
        stringstream check1(palavra);
        string intermediate;
        while(getline(check1, intermediate, ','))
        {
            tokens.push_back(intermediate);
        }
        cout<<"{ ";
        for(int i = 0; i < (int) tokens.size(); i++){ 
            cout << tokens[i] << ' ';
        }
        cout<<"}"<<endl;
    }
    

    getchar();
    getchar();

    file1.close();
}

#endif