#ifndef READ_H_
#define READ_H_

#include "includes.hpp"

vector<int> v;
unordered_map<string, vector<int>> texto;

vector<int> v2;
unordered_map<string, vector<int>> texto2;

set<string, string> nomes;

class Ler{
    public:
        void ler();
        void ler2();
        void Hash();
        void Hash2();
        void HashNomes1();
        void HashNomes2();
        void Token();
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
            key = to_string(coluna) + ", " + string(token);
            texto[key].push_back(linha);
            token = strtok(NULL, ",");
            coluna++;
        }
        linha++;
    }

    getchar();
    getchar();

    file1.close();
}

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

void Hash(){
    int cont=0;
    for (auto mapIt = begin(texto); mapIt != end(texto); ++mapIt){
        cout<<"\n";
        cont++;
        cout<<cont<<"°"<<endl;
        cout << "-> aparece [" + mapIt->first + "]"
             << " : ";

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
        cout << "-> aparece [" + mapIt->first + "]"
             << " : ";

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
        cout<<"{"<<endl;
        for(int i = 0; i < (int) tokens.size(); i++)
            cout << tokens[i] << '\n';
        cout<<"}"<<endl;
    }
    

    getchar();
    getchar();

    file1.close();
}
/*
void Nomes(){
    ifstream file1;
    file1.open("src/dataset/D.csv");
    //int cont=0;
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
        nomes.insert(tokens[tokens.size()-1], tokens[tokens.size()]); 
    }

    for (itr = nomes.begin(); itr != nomes.end(); itr++) {
        cout << *itr << " ";
    }

    getchar();
    getchar();

    file1.close();
}
*/

#endif