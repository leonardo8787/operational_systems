#include<bits/stdc++.h>
using namespace std;

//#define _ ios_base::sync_with_stdio(false); //cin.tie(0);cout.tie(0);
//#define endl '\n'

const int INF = 0x3b3b3b3b;

typedef long long ll;

int32_t main(){

	FILE *arquivo1;
	FILE *arquivo2;

	system("clear || cls"); 

	arquivo1 = fopen("D.csv","r");
	arquivo2 = fopen("T.csv", "r");

	unordered_map<string, int> umap;

	string linha[100], result;
	int op;
	do{
		system("clear || cls"); 
		cout<<"========================================================"<<endl;
		cout<<"Aluno: Leonardo de Oliveira Campos"<<endl;
		cout<<"Centro Federal de Educação Tecnológica de Minas Gerais"<<endl;
		cout<<"========================================================"<<endl;
		cout<<"===MENU==="<<endl;
		cout<<"1 - ler arquivos"<<endl;
		cout<<"2 - escrever novo arquivo toquenizado"<<endl;
		cout<<"3 - ler arquivo toquenizado"<<endl;
		cout<<"4 - sair"<<endl;
		cin>>op;
		switch (op)
		{
		case 1:
			if(arquivo1==NULL || arquivo2==NULL){
				cout<<"erro no arquivo"<<"\n";
				return 0;
			}else {
				cout<<"-------C.csv-------\n\n\n";
				while(!feof(arquivo1)) {
					result = fgets(linha, 100, arquivo1);
					if(result){
						cout<<result<<endl;
					}
				}
				cout<<"\n\n\n-------T.csv-------\n\n\n";
				while(!feof(arquivo2)) {
					result = fgets(linha, 100, arquivo2);
					if(result){
						cout<<result<<endl;
					}
				}
				cout<<"\n\n\n--------fim--------\n\n\n";
			}
			getchar();
			getchar();
			break;
		case 2: 
			if(arquivo1==NULL || arquivo2==NULL){
				cout<<"erro no arquivo"<<"\n";
				return 0;
			}else {
				while(!feof(arquivo1)) {
					result = fgets(linha, 100, arquivo1);
					if(result){
						string palavra = strtok(result, ",");
						for(auto i : palavra){
							cout<<i;
						}
						cout<<endl;
					}
				}
			}
			getchar();
			getchar();
			break;
		case 3:
			if(arquivo1==NULL || arquivo2==NULL){
				cout<<"erro no arquivo"<<"\n";
				return 0;
			}else {
				cout<<"-------C.csv-------\n\n\n";
				while(!feof(arquivo1)) {
					result = fgets(linha, 100, arquivo1);
					if(result){
						cout<<result<<endl;
					}
				}
				cout<<"\n\n\n-------T.csv-------\n\n\n";
				while(!feof(arquivo2)) {
					result = fgets(linha, 100, arquivo2);
					if(result){
						cout<<result<<endl;
					}
				}
				cout<<"\n\n\n--------fim--------\n\n\n";
			}
			getchar();
			getchar();
			break;
		case 4:
			cout<<"saindo..."<<endl;
			break;
		default:
			cout<<"Escolha uma opção válida"<<endl;
			break;
		}
	}while(op != 4);

	//unordered_map<string, int> umap;

	/*for(auto i:umap){
		cout<<i.first<<" "<<i.second<<"\n";
	}*/

	fclose(arquivo1);
	fclose(arquivo2);
	return 0;
}
