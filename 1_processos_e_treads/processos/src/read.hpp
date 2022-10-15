#ifndef READ_H_
#define READ_H_

#include "includes.hpp"
#define TAM 100

vector<string> a;
vector<string> recebe;
vector<string> tokens;
queue<string> fila;
vector<string> v0;
vector<string> permutacoes;
vector<string> v;
unordered_map<string, vector<string>> texto;
//tokeniza linha e separa valores para combinação
queue<vector<string>> antesCombinacao1;
queue<vector<string>> antesCombinacao2;
vector<string> v2;
unordered_map<string, vector<string>> texto2;
vector<string> v3;
unordered_map<string, vector<string>> texto3;
set<string, string> nomes;
//classe de flores
set<string> classes;
//classe com valores associados
unordered_map<string, set<int>> classes2;
unordered_map<string, set<int>> classes3;
//sujeito a erros de compilação se escrito de forma errada !!!

queue<vector<string>> combinacoes;
vector<string> allCombinatesLine;
string auxCombinates;

vector<string> encontroCombinacoes;
vector<string> encontroCombinacoesClasses;

class Ler{
    public:
        void ler();
        void lerT();
        void printFilaDeVector();
        void poeNaFilaALinha();
        //void combinacao();
        //void processaFila();
        //void escreveCombinacao();
        void Hash();
        void Hash2();
        void HashNomes1();
        void classeFloresMetodo();
        void HashNomes2();
        void Token();
        void Task();
        void iniciaCombinacao();
        void combinate(vector<string> vector, int perm[], int index, int n, int k);
        void printCombinacoes();
        void interseccaoEntreLinhas();
        void interseccaoClasses();
};

void ler(){

    ifstream file1;
    file1.open("src/dataset/D.csv");

    string palavra;
    string key;
    char *output;
    char *token;
    int coluna=1;
    int linha=1;
    string linhaStr;

    vector<string> aux;

    if (!file1){
        cout<<"o arquivo 1 não pode ser aberto, o programa será fechado!"<<endl;
        return;
    }
 
    int cont=0;
    while(file1){
        if (coluna==5) coluna=1;
        getline(file1, palavra);
        cout<<"\n";
        cont++;
        cout<<cont<<"° - linha"<<endl;
        cout<<palavra<<endl;
        output = const_cast<char *>(palavra.c_str());
        token = strtok(output, ",");
        while (token != NULL){
            if (coluna==5){ // aqui deveria ser 4 e não 5 !!! 
                key=string(token);
                cout<<key<<endl;
                classes2[key].insert(linha);
                token = strtok(NULL, ",");
                break;
            }else{
                key = string(token);
                linhaStr=to_string(linha);
                texto[key].push_back(linhaStr);
                token = strtok(NULL, ",");
                if(coluna<4){
                    string teste;
                    teste=to_string(coluna)+", "+string(token);
                    aux.push_back(teste);
                }
                coluna++;
            }
        }
        antesCombinacao1.push(aux);
        aux.clear();
        linha++;
    }
    getchar();
    getchar();
    file1.close();
}

void lerT(){

    ifstream file1;
    file1.open("src/dataset/T.csv");

    string palavra;
    string key;
    char *output;
    char *token;
    int coluna=1;
    int linha=1;
    string linhaStr;

    vector<string> aux;

    if (!file1){
        cout<<"o arquivo 1 não pode ser aberto, o programa será fechado!"<<endl;
        return;
    }
 
    int cont=0;
    while(file1){
        if (coluna==5) coluna=1;
        getline(file1, palavra);
        cout<<"\n";
        cont++;
        cout<<cont<<"° - linha"<<endl;
        cout<<palavra<<endl;
        output = const_cast<char *>(palavra.c_str());
        token = strtok(output, ",");
        while (token != NULL){
            if (coluna==5){ // aqui deveria ser 4 e não 5 !!! 
                key=string(token);
                cout<<key<<endl;
                classes3[key].insert(linha);
                token = strtok(NULL, ",");
                break;
            }else{
                key = string(token);
                linhaStr=to_string(linha);
                texto2[key].push_back(linhaStr);
                token = strtok(NULL, ",");
                if(coluna<4){
                    string teste;
                    teste=to_string(coluna)+", "+string(token);
                    aux.push_back(teste);
                }
                coluna++;
            }
        }
        antesCombinacao2.push(aux);
        aux.clear();
        linha++;
    }
    getchar();
    getchar();
    file1.close();
}

void printFilaDeVector(){
    queue<vector<string>> help = antesCombinacao2;
    vector<string> help2;
    while(!help.empty()){
        help2=help.front();
        help.pop();
        for(auto &i:help2){
            cout<<"["<<i<<"]"<<" ";
        }
        cout<<endl;
        help2.clear();
    }
    cout<<endl;
}

void classesFlorMetodo(){
    for (auto mapIt = begin(classes2); mapIt != end(classes2); ++mapIt){
        cout << "{"+mapIt->first+"}"
             << " : ";
        for (auto c : mapIt->second)
            cout << c << " ";
        cout << endl;
    }
}

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
/* 
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

void combinacao1(){
    vector<string> x;
    for(auto &i:recebe){
        x.push_back(i);
        combinacoes.push_back(x);
    }
    // for(auto i:combinacoes){
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     } 
    //     cout<<endl;
    // }
}
*/

void Hash(){
    for (auto mapIt = begin(texto); mapIt != end(texto); ++mapIt){
        cout <<mapIt->first
             << " : ";
        for (auto c : mapIt->second)
            cout << c << " ";
        cout << endl;
    }
}

void Hash2(){
    for (auto mapIt = begin(texto2); mapIt != end(texto2); ++mapIt){
        cout <<mapIt->first
             << " : ";
        for (auto c : mapIt->second)
            cout << c << " ";
        cout << endl;
    }
}

void HashNomes1(){
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
        if(tokens.size()){ 
            cout <<tokens[tokens.size()] << " " << tokens[tokens.size()-1] << '\n';
            string palavra=tokens[tokens.size()]+" "+tokens[tokens.size()-1];
            classes.insert(palavra);
        }
    }

    for(auto& str: classes){
        cout << str <<endl;
    }

    getchar();
    getchar();

    file1.close();
}

void mostraClasseDeFlores(){
  for(auto& str: classes)
  {
    cout << str <<endl;
  }
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

void combinate(vector<string> vector, int perm[], int index, int n, int k);

void iniciaCombinacao(){
    queue<vector<string>> help = antesCombinacao2;
    vector<string> ini;
    int perm[3] = {0};
    int index = 1;
    for (int i = 0; i < 50; i++){
        ini = help.front();
        help.pop();
        for (index = 1; index <= 3; index++)
            combinate(ini, perm, 0, 3, index);
        ini.clear();
        combinacoes.push(allCombinatesLine);
        allCombinatesLine.clear();
    }
}

void combinate(vector<string> vector, int perm[], int index, int n, int k)
{
    static int count = 0;
    if (count == k)
    {
        auxCombinates.assign("");

        for (int i = 0; i < n; i++)
            if (perm[i])
                auxCombinates.append(vector.at(i)).append("-");

        if (!auxCombinates.empty())
        {
            auxCombinates.erase(auxCombinates.end() - 1);
            allCombinatesLine.push_back(auxCombinates);
        }
    }
    else if ((n - index) >= (k - count))
    {
        perm[index] = 1;
        count++;
        combinate(vector, perm, index + 1, n, k);

        perm[index] = 0;
        count--;
        combinate(vector, perm, index + 1, n, k);
    }
}

void printCombinacoes(){
    queue<vector<string>> help = combinacoes;
    vector<string> help2;
    while(!help.empty()){
        help2=help.front();
        help.pop();
        for(auto &i:help2){
            cout<<"["<<i<<"]"<<" ";
        }
        cout<<endl;
        help2.clear();
    }
    cout<<endl;
}

void interseccaoEntreLinhas(){
    queue<vector<string>> help = combinacoes;
    vector<string> help2;
    while(!help.empty()){
        help2=help.front();
        help.pop();
        for(auto &i:help2){
            for (auto mapIt = begin(texto); mapIt != end(texto); ++mapIt){
                if(mapIt->first == i){
                    cout<<"T"<<endl;
                }
                cout << endl;
            }
        }
        cout<<endl;
        help2.clear();
    }
}

void interseccaoClasses(){

}

#endif