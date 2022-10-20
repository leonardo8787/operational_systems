#ifndef MENU_H_
#define MENU_H_

#include "read.hpp"
#include "includes.hpp"
#include "etapas.hpp"

class Menu{
	private:

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

		cout<<"Este trabalho tem por objetivo desenvolver o aprendizado" 
		"em processos e threads dentro do escopo de sistemas operacionais"<<endl;


		cout<<"===MENU==="<<endl;
		cout<<"0 - limpa tela"<<endl;
		cout<<"1 - Etapa 1"<<endl;
		cout<<"2 - Etapa 2"<<endl;
		cout<<"3 - Etapa 3"<<endl;
		cout<<"4 - Etapa 4"<<endl;
		cout<<"5 - Etapa 5"<<endl;
		cout<<"6 - Etapa 6"<<endl;
		cout<<"111 - sair"<<endl;
		cin>>op;
		switch (op)
		{
			case 0:
				system("clear || cls"); 
				break;
			case 1:
				etapa1();
				break;
			case 2: 
				etapa2();
				break;
			case 3:
				etapa3();
				break;
			case 4:
				etapa4();
				break;
			case 111:
				cout<<"saindo..."<<endl;
				break;
			default:
				cout<<"Escolha uma opção válida"<<endl;
				break;
		}
	}while(op != 111);
}

#endif 