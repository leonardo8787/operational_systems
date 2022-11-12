#ifndef READ_H_
#define READ_H_

#include "includes.hpp"
#define TAM 100

int cont1 = 0; // flor -> versiculor
int cont2 = 0; // flor -> virginica
int cont3 = 0; // flor -> setosa
vector<string> a;
vector<string> recebe;
vector<string> tokens;
queue<string> fila;
vector<string> v0;
vector<string> permutacoes;
vector<string> v;
unordered_map<string, vector<string>> texto;
// tokeniza linha e separa valores para combinação
queue<vector<string>> antesCombinacao1;
queue<vector<string>> antesCombinacao2;
vector<string> v2;
unordered_map<string, vector<string>> texto2;
vector<string> v3;
unordered_map<string, vector<string>> texto3;
set<string, string> nomes;
// classe de flores
set<string> classes;
// classe com valores associados
unordered_map<string, set<int>> classes2;
unordered_map<string, vector<int>> classes3;
// sujeito a erros de compilação se escrito de forma errada !!!

queue<vector<string>> combinacoes;
vector<string> allCombinatesLine;
string auxCombinates;

vector<string> encontroCombinacoes;
vector<string> encontroCombinacoesClasses;

vector<string> pegaInterseccao; // intersecção2
queue<vector<string>> pegaInterseccao2; // intersecção dos valores associados as chaves
vector<vector<int>> pegaInterseccao3;
set<int> multiInterseccoes;

//classes de flores
vector<int> versiculor;
vector<int> virginica;
vector<int> setosa;

//cash
unordered_map<string, vector<int>> cash;

class Ler
{
public:
    void ler();
    void lerT();
    void printFilaDeVector();
    void poeNaFilaALinha();
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
    void interseccoes1();
    void printaVectorProcura(vector<string> v);
    void interseccao2(string recebe);
    void interseccao3(vector<int> v1, vector<int> v2);
    void interseccaoClasse();
    void printFilaVector();
    void interseccaoDasCombinacoes();
    void numeroClassesIteracoes();
    void cashHash();
    void printaCash();
    void interseccaoEtapa4();
    void interseccao2Etapa4(string recebe);
    void interseccaoDasCombinacoesEtapa4();
    void interseccaoClasseEtapa4();
    void umeroClassesIteracoesEtapa4();
};

void ler()
{
    auto start = std::chrono::steady_clock::now();
    ifstream file1;
    file1.open("src/dataset/D.csv");

    string palavra;
    string key;
    char *output;
    char *token;
    int coluna = 1;
    int linha = 1;
    string linhaStr;

    vector<string> aux;

    if (!file1)
    {
        cout << "o arquivo 1 não pode ser aberto, o programa será fechado!" << endl;
        return;
    }

    int cont = 0;
    while (file1)
    {
        if (coluna == 5)
            coluna = 1;
        getline(file1, palavra);
        cout << "\n";
        cont++;
        cout << cont << "° - linha" << endl;
        cout << palavra << endl;
        output = const_cast<char *>(palavra.c_str());
        token = strtok(output, ",");
        while (token != NULL)
        {
            if (coluna == 5)
            { 
                key = string(token);
                cout << key << endl;
                classes2[key].insert(linha);
                token = strtok(NULL, ",");
                break;
            }
            key = to_string(coluna) + ", " + string(token);
            linhaStr = to_string(linha);
            texto[key].push_back(linhaStr);
            token = strtok(NULL, ",");
            if (coluna < 4)
            {
                string teste;
                teste = to_string(coluna) + ", " + string(token);
                aux.push_back(teste);
            }
            coluna++;
        }
        antesCombinacao1.push(aux);
        aux.clear();
        linha++;
    }
    getchar();
    getchar();
    file1.close();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "tempo: " << elapsed_seconds.count() <<endl;
}

void lerT()
{
    auto start = std::chrono::steady_clock::now();
    ifstream file1;
    file1.open("src/dataset/T.csv");

    string palavra;
    string key;
    char *output;
    char *token;
    int coluna = 1;
    int linha = 1;
    string linhaStr;

    vector<string> aux;

    if (!file1)
    {
        cout << "o arquivo 1 não pode ser aberto, o programa será fechado!" << endl;
        return;
    }

    int cont = 0;
    while (file1)
    {
        if (coluna == 5)
            coluna = 1;
        getline(file1, palavra);
        cout << "\n";
        cont++;
        cout << cont << "° - linha" << endl;
        cout << palavra << endl;
        output = const_cast<char *>(palavra.c_str());
        token = strtok(output, ",");
        while (token != NULL)
        {
            if (coluna == 5)
            { 
                key = string(token);
                cout << key << endl;
                classes3[key].push_back(linha);
                token = strtok(NULL, ","); 
                coluna=1;
                break;
            }
            key = string(token);
            linhaStr = to_string(linha);
            texto2[key].push_back(linhaStr);
            token = strtok(NULL, ",");
            if(coluna<4){ 
                string teste;
                teste = to_string(coluna) + ", " + string(token);
                aux.push_back(teste);
            }
            coluna++;
        }
        antesCombinacao2.push(aux);
        aux.clear();
        linha++;
    }
    getchar();
    getchar();
    file1.close();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "tempo: " << elapsed_seconds.count() <<endl;
}

void printFilaDeVector()
{
    auto start = std::chrono::steady_clock::now();
    queue<vector<string>> help = antesCombinacao2;
    vector<string> help2;
    while (!help.empty())
    {
        help2 = help.front();
        help.pop();
        for (auto &i : help2)
        {
            cout << "[" << i << "]"
                 << " ";
        }
        cout << endl;
        help2.clear();
    }
    cout << endl;
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "tempo: " << elapsed_seconds.count() <<endl;
}

void classesFlorMetodo()
{
    auto start = std::chrono::steady_clock::now();
    int cont = 0;
    for (auto mapIt = begin(classes2); mapIt != end(classes2); ++mapIt)
    {
        if(cont == 0){
            cout << cont << " : ";
            cont1++; 
        }else if(cont == 1){
            cout << cont << " : ";
            cont2++; 
        }else if(cont == 2){
            cout << cont << " : ";
            cont3++;
        }
        for (auto c : mapIt->second)
            cout << c << " ";
        cout << endl;

        cont++;
    }
    cout<<endl<<" 0 - versicolor \n 1 - virginica \n 2 - setosa "<<endl;
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "tempo: " << elapsed_seconds.count() <<endl;
}

void poeNaFilaALinha()
{
    auto start = std::chrono::steady_clock::now();
    ifstream file;
    file.open("src/dataset/T.csv");

    if (!file)
    {
        cout << "o arquivo 2 não pode ser aberto, o programa será fechado!" << endl;
        return;
    }

    while (file)
    {
        string palavra;
        getline(file, palavra);
        stringstream check1(palavra);
        string intermediate;
        while (getline(check1, intermediate, ','))
        {
            tokens.push_back(intermediate);
        }
        tokens.erase(tokens.end());
    }
    for (int i = 0; i < (int)tokens.size(); i++)
    {
        cout << tokens[i] << ' ';
    }
    cout << endl;

    getchar();
    getchar();

    file.close();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "tempo: " << elapsed_seconds.count() <<endl;
}

void Hash()
{
    auto start = std::chrono::steady_clock::now();
    for (auto mapIt = begin(texto); mapIt != end(texto); ++mapIt)
    {
        cout << mapIt->first
             << " : ";
        for (auto c : mapIt->second)
            cout << c << " ";
        cout << endl;
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "tempo: " << elapsed_seconds.count() <<endl;
}

void Hash2()
{
    auto start = std::chrono::steady_clock::now();
    for (auto mapIt = begin(texto2); mapIt != end(texto2); ++mapIt)
    {
        cout << mapIt->first
             << " : ";
        for (auto c : mapIt->second)
            cout << c << " ";
        cout << endl;
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "tempo: " << elapsed_seconds.count() <<endl;
}

void HashNomes1()
{
    auto start = std::chrono::steady_clock::now();
    ifstream file1;
    file1.open("src/dataset/D.csv");

    while (file1)
    {
        string palavra;
        getline(file1, palavra);
        vector<string> tokens;
        stringstream check1(palavra);
        string intermediate;
        while (getline(check1, intermediate, ','))
        {
            tokens.push_back(intermediate);
        }
        if (tokens.size())
        {
            cout << tokens[tokens.size()] << " " << tokens[tokens.size() - 1] << '\n';
            string palavra = tokens[tokens.size()] + " " + tokens[tokens.size() - 1];
            classes.insert(palavra);
        }
    }

    for (auto &str : classes)
    {
        cout << str << endl;
    }

    getchar();
    getchar();

    file1.close();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "tempo: " << elapsed_seconds.count() <<endl;
}

void mostraClasseDeFlores()
{
    auto start = std::chrono::steady_clock::now();
    for (auto &str : classes)
    {
        cout << str << endl;
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "tempo: " << elapsed_seconds.count() <<endl;
}

void HashNomes2()
{
    auto start = std::chrono::steady_clock::now();
    ifstream file2;
    file2.open("src/dataset/T.csv");
    int cont = 0;
    while (file2)
    {
        string palavra;
        getline(file2, palavra);
        vector<string> tokens;
        stringstream check1(palavra);
        string intermediate;
        while (getline(check1, intermediate, ','))
        {
            tokens.push_back(intermediate);
        }
        cout << cont++ << "° : " << tokens[tokens.size() - 1] << " " << tokens[tokens.size()] << '\n';
    }

    getchar();
    getchar();

    file2.close();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "tempo: " << elapsed_seconds.count() <<endl;
}

void Token()
{
    auto start = std::chrono::steady_clock::now();
    ifstream file1;
    file1.open("src/dataset/D.csv");

    while (file1)
    {
        string palavra;
        getline(file1, palavra);
        vector<string> tokens;
        stringstream check1(palavra);
        string intermediate;
        while (getline(check1, intermediate, ','))
        {
            tokens.push_back(intermediate);
        }
        cout << "{ ";
        for (int i = 0; i < (int)tokens.size(); i++)
        {
            cout << tokens[i] << ' ';
        }
        cout << "}" << endl;
    }

    getchar();
    getchar();

    file1.close();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "tempo: " << elapsed_seconds.count() <<endl;
}

void combinate(vector<string> vector, int perm[], int index, int n, int k);

void iniciaCombinacao()
{
    auto start = std::chrono::steady_clock::now();
    queue<vector<string>> help = antesCombinacao2;
    vector<string> ini;
    int perm[3] = {0};
    int index = 1;
    for (int i = 0; i < 50; i++)
    {
        ini = help.front();
        help.pop();
        for (index = 1; index <= 3; index++)
            combinate(ini, perm, 0, 3, index);
        ini.clear();
        combinacoes.push(allCombinatesLine);
        allCombinatesLine.clear();
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "tempo: " << elapsed_seconds.count() <<endl;
}

void combinate(vector<string> vector, int perm[], int index, int n, int k)
{
    auto start = std::chrono::steady_clock::now();
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
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "tempo: " << elapsed_seconds.count() <<endl;
}

void printCombinacoes()
{
    auto start = std::chrono::steady_clock::now();
    queue<vector<string>> help = combinacoes;
    vector<string> help2;
    while (!help.empty())
    {
        help2 = help.front();
        help.pop();
        for (auto &i : help2)
        {
            cout << "[" << i << "]"
                 << " ";
        }
        cout << endl;
        help2.clear();
    }
    cout << endl;
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "tempo: " << elapsed_seconds.count() <<endl;
}

void interseccao2(string recebe);

void interseccoes1()
{
    auto start = std::chrono::steady_clock::now();
    cout << "=======interações e intersecções=======" << endl;
    queue<vector<string>> help = combinacoes;
    vector<string> help2;
    while (!help.empty())
    {
        help2 = help.front();
        help.pop();
        for (auto &i : help2)
            interseccao2(i);
        cout << endl;
        help2.clear();
    }
    cout << endl;
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "tempo: " << elapsed_seconds.count() <<endl;
}

vector<int> interseccao3(vector<int> v1, vector<int> v2);
void intersectionHash(vector<int> v);
void printaVectorProcura(vector<string> v);
vector<int> intersection(vector<int> v1, vector<int> v2);

void interseccao2(string recebe)
{
    auto start = std::chrono::steady_clock::now();
    vector<string> auxilia;
    vector<vector<string>> auxilia2;
    vector<string> procura;
    vector<vector<string>> procura2;
    char vetor[25];
    strcpy(vetor, recebe.c_str());
    char *token = strtok(vetor, "-");
    cout << "[" << recebe << "]" << endl;
    while (token != NULL)
    {
        string chave = (string) token;
        procura.push_back(chave);
        token = strtok(NULL, "-");
        cout<<"chave: "<<chave<<endl;
        if (texto.find(chave) != texto.end()) {
            vector<int> aux2;
            cout << " Chave encontrada! :" << chave << endl;
            for(auto i:texto.find(chave)->second){
                int a = stoi(i);
                aux2.push_back(a);   
            }
            pegaInterseccao3.push_back(aux2);
        }
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "tempo: " << elapsed_seconds.count() <<endl;
}

void interseccaoDasCombinacoes(){
    auto start = std::chrono::steady_clock::now();
    for(auto i:pegaInterseccao3){ 
        for(auto j:i){
            cout<<j<<" ";
            multiInterseccoes.insert(j);
        }
    }
    cout<<endl<<endl;
    cout<<"Intersecções: "<<endl;
    for(auto i:multiInterseccoes){
        cout<<i<<" ";
    }
    cout<<endl;
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "tempo: " << elapsed_seconds.count() <<endl;
}

void printaVectorProcura(){
    auto start = std::chrono::steady_clock::now();
    for(auto i:pegaInterseccao){
        cout<<i<<endl;
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "tempo: " << elapsed_seconds.count() <<endl;
}

void printaPegaInterseccao2(){
    auto start = std::chrono::steady_clock::now();
    for(auto i:pegaInterseccao3){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "tempo: " << elapsed_seconds.count() <<endl;
}

void printFilaVector(){
    auto start = std::chrono::steady_clock::now();
    queue<vector<string>> help = pegaInterseccao2;
    vector<string> help2;
    while (!help.empty())
    {
        help2 = help.front();
        help.pop();
        for (auto &i : help2)
            cout<<i<<endl;
        cout << endl;
        help2.clear();
    }
    cout << endl;
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "tempo: " << elapsed_seconds.count() <<endl;
}

void interseccaoClasse(){
    auto start = std::chrono::steady_clock::now();
    cout<<"Interseccções da versiculor"<<endl;
    int cont =0;
    for (auto mapIt = begin(classes2); mapIt != end(classes2); ++mapIt)
    {
        if(cont == 0){
            for(auto i:multiInterseccoes){
                    for (auto c : mapIt->second){ 
                        cout << c << " ";
                        if(c == i){
                            cont1++;
                            versiculor.push_back(c);
                        }
                    }   
                cout << endl;
            }
        }
        break;
    }
    cont++;
    cout<<"Interseccções da virginica"<<endl;
    for (auto mapIt = begin(classes2); mapIt != end(classes2); ++mapIt)
    {
        if(cont == 1){
            for(auto i:multiInterseccoes){
                    for (auto c : mapIt->second){ 
                        cout << c << " ";
                        if(c == i){
                            cont2++;
                            virginica.push_back(c);
                        }
                    }
                cout << endl;
            }
        }
        break;
    }
    cont++;
    cout<<"setosa"<<endl;
    for (auto mapIt = begin(classes2); mapIt != end(classes2); ++mapIt)
    {
        if(cont == 2){
            for(auto i:multiInterseccoes){
                    for (auto c : mapIt->second){ 
                        cout << c << " ";
                        if(c == i){
                            cont3++;
                            setosa.push_back(c);
                        }
                    }
                cout << endl;
            }
        }
        break;
    }

    cout<<"Resultados: "<<endl;
    cout<<" versiculor: "<<cont1<<endl;
    cout<<" virginica: "<<cont2<<endl;
    cout<<" setosa: "<<cont3<<endl;
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "tempo: " << elapsed_seconds.count() <<endl;
}

void numeroClassesIteracoes(){
    auto start = std::chrono::steady_clock::now();
    cout<<"ETAPA 4"<<endl<<endl;
    int soma1=0;
    int soma2=0; 
    int soma3=0;
    cout<<"Versiculor"<<endl;
    for(auto i:versiculor){
        cout<<i<<" ";
        soma1+=i;
    }
    cout<<"Soma versiculor: "<<soma1<<endl<<endl;
    cout<<"Virginica"<<endl;
    for(auto i:virginica){
        cout<<i<<" ";
        soma2+=i;
    }
    cout<<"Soma Virginica: "<<soma2<<endl<<endl;
    cout<<"Setosa"<<endl;
    for(auto i:setosa){
        cout<<i<<" ";
        soma3+=i;
    }
    cout<<"Soma setosa: "<<soma3<<endl<<endl;
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "tempo: " << elapsed_seconds.count() <<endl;
}

void cashHash(){
    auto start = std::chrono::steady_clock::now();
    cout<<"======Cash-Hash======"<<endl;
    queue<vector<string>> help = combinacoes;
    vector<string> help2;
    vector<int> auxInterseccoes;

    while (!help.empty())
    {
        help2 = help.front();
        help.pop();
        for (auto &i : help2){ 
            char vetor[25];
            strcpy(vetor, i.c_str());
            char *token = strtok(vetor, "-");
            cout<<i<<endl;
            string chave = (string) token;
            cout<<chave<<endl;
            if (texto.find(chave) != texto.end()) {
                vector<int> auxT;
                for(auto j:texto.find(chave)->second){
                    auxT.push_back(stoi(j));   
                }
                string key = string(i);
                cash[key] = auxT;
            }            
        }
        cout << endl;
        help2.clear();
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "tempo: " << elapsed_seconds.count() <<endl;
}

void printaCash(){
    auto start = std::chrono::steady_clock::now();
    cout<<"Valores da Cash"<<endl;
    for (auto mapIt = begin(cash); mapIt != end(cash); ++mapIt)
    {
        cout << mapIt->first
             << " : ";
        for (auto c : mapIt->second)
            cout << c << " ";
        cout << endl;
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "tempo: " << elapsed_seconds.count() <<endl;
}

void interseccao2Etapa4(string recebe);

void interseccaoEtapa4(){
    auto start = std::chrono::steady_clock::now();
    queue<vector<string>> help = combinacoes;
    vector<string> help2;
    while (!help.empty())
    {
        help2 = help.front();
        help.pop();
        for (auto &i : help2)
            interseccao2Etapa4(i);
        cout << endl;
        help2.clear();
    }
    cout << endl;
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "tempo: " << elapsed_seconds.count() <<endl;
}

vector<vector<int>> pegaInterseccaoEtapa4;
set<int> multiInterseccoes2;

void interseccao2Etapa4(string recebe)
{
    auto start = std::chrono::steady_clock::now();
    vector<string> auxilia;
    vector<vector<string>> auxilia2;
    vector<string> procura;
    vector<vector<string>> procura2;
    char vetor[25];
    strcpy(vetor, recebe.c_str());
    char *token = strtok(vetor, "-");
    while (token != NULL)
    {
        string chave = (string) token;
        procura.push_back(chave);
        token = strtok(NULL, "-");
        if (texto.find(chave) != texto.end()) {
            vector<int> aux2;
            for(auto i:texto.find(chave)->second){
                int a = stoi(i);
                aux2.push_back(a);   
            }
            for (auto mapIt = begin(cash); mapIt != end(cash); ++mapIt)
            {
                // for (auto c : mapIt->second){
                    if(aux2 == mapIt->second){
                        cout<<"encontrou um igual!!!"<<endl;
                        pegaInterseccaoEtapa4.push_back(aux2);
                        for(auto m:aux2){
                            cout<<m<<" ";
                        }
                        cout<<endl;
                    }
                // }
            }
        }
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "tempo: " << elapsed_seconds.count() <<endl;
}

void interseccaoDasCombinacoesEtapa4(){
    auto start = std::chrono::steady_clock::now();
    for(auto i:pegaInterseccaoEtapa4){ 
        for(auto j:i){
            cout<<j<<" ";
            multiInterseccoes.insert(j);
        }
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "tempo: " << elapsed_seconds.count() <<endl;
}

void interseccaoClasseEtapa4(){
    auto start = std::chrono::steady_clock::now();
    cout<<"Interseccções da versiculor"<<endl;
    int cont =0;
    for (auto mapIt = begin(classes2); mapIt != end(classes2); ++mapIt)
    {
        if(cont == 0){
            for(auto i:multiInterseccoes2){
                    for (auto c : mapIt->second){ 
                        cout << c << " ";
                        if(c == i){
                            cont1++;
                            versiculor.push_back(c);
                        }
                    }   
                cout << endl;
            }
        }
        break;
    }
    cont++;
    cout<<"Interseccções da virginica"<<endl;
    for (auto mapIt = begin(classes2); mapIt != end(classes2); ++mapIt)
    {
        if(cont == 1){
            for(auto i:multiInterseccoes2){
                    for (auto c : mapIt->second){ 
                        cout << c << " ";
                        if(c == i){
                            cont2++;
                            virginica.push_back(c);
                        }
                    }
                cout << endl;
            }
        }
        break;
    }
    cont++;
    cout<<"setosa"<<endl;
    for (auto mapIt = begin(classes2); mapIt != end(classes2); ++mapIt)
    {
        if(cont == 2){
            for(auto i:multiInterseccoes2){
                    for (auto c : mapIt->second){ 
                        cout << c << " ";
                        if(c == i){
                            cont3++;
                            setosa.push_back(c);
                        }
                    }
                cout << endl;
            }
        }
        break;
    }

    cout<<"Resultados: "<<endl;
    cout<<" versiculor: "<<cont1<<endl;
    cout<<" virginica: "<<cont2<<endl;
    cout<<" setosa: "<<cont3<<endl;
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "tempo: " << elapsed_seconds.count() <<endl;
}

void numeroClassesIteracoesEtapa4(){
    auto start = std::chrono::steady_clock::now();
    cout<<"ETAPA 4"<<endl<<endl;
    int soma1=0;
    int soma2=0; 
    int soma3=0;
    cout<<"Versiculor"<<endl;
    for(auto i:versiculor){
        cout<<i<<" ";
        soma1+=i;
    }
    cout<<"Soma versiculor: "<<soma1<<endl<<endl;
    cout<<"Virginica"<<endl;
    for(auto i:virginica){
        cout<<i<<" ";
        soma2+=i;
    }
    cout<<"Soma Virginica: "<<soma2<<endl<<endl;
    cout<<"Setosa"<<endl;
    for(auto i:setosa){
        cout<<i<<" ";
        soma3+=i;
    }
    cout<<"Soma setosa: "<<soma3<<endl<<endl;
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "tempo: " << elapsed_seconds.count() <<endl;
}

#endif