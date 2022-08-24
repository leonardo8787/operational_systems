#ifndef MENU_H_
#define MENU_H_

#include "read.hpp"
#include "includes.hpp"

class Menu{
    public:
        void menu();
};

void menu(){
	int op;
	do{
		cout<<"========================================================"<<endl;
		cout<<"Aluno: Leonardo de Oliveira Campos"<<endl;
		cout<<"Centro Federal de Educação Tecnológica de Minas Gerais"<<endl;
		cout<<"========================================================"<<endl;
		cout<<"===MENU==="<<endl;
		cout<<"0 - limpa tela"<<endl;
		cout<<"1 - ler (arquivo1)"<<endl;
		cout<<"2 - ler arquivo tokenizado com index (arquivo1)"<<endl;
		cout<<"3 - ler nomes associados a index(arquivo1)"<<endl;
		cout<<"4 - ler (Task)"<<endl;
		cout<<"5 - ler arquivo tokenizado com index (Task)"<<endl;
		cout<<"6 - ler nomes associados a index(Task)"<<endl;
		cout<<"7 - token (testes)"<<endl;
		cout<<"8 - Intersecção"<<endl;
		cout<<"9 - sair"<<endl;
		cin>>op;
		switch (op)
		{
		case 0:
			system("clear || cls"); 
			break;
		case 1:
            ler();
			break;
		case 2: 
           	Hash();
			break;
		case 3:
            HashNomes1();
			break;
		case 4:
			ler2();
			break;
		case 5:
			Hash2();
			break;
		case 6:
			HashNomes2();
			break;
		case 7:
			Token();
			break;
		case 8:
			ComparaUnoderMap();
			break;
		case 9:
			cout<<"saindo..."<<endl;
			break;
		default:
			cout<<"Escolha uma opção válida"<<endl;
			break;
		}
	}while(op != 8);
}

#endif 