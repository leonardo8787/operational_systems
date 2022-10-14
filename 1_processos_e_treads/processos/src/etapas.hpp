#ifndef ETAPAS_H_
#define ETAPAS_H_

#include "menu.hpp"
#include "includes.hpp"
#include "read.hpp"

class Etapas{
	private:

    public:
		void etapa1();
		void etapa2();
		void etapa3();
		void etapa4();
};

void etapa1(){
	int op;
	do{
		cout<<"========================================================"<<endl;
		cout<<"Aluno: Leonardo de Oliveira Campos"<<endl;
		cout<<"Centro Federal de Educação Tecnológica de Minas Gerais"<<endl;
		cout<<"========================================================"<<endl;
		cout<<"===MENU==="<<endl;
		cout<<"0 - limpa tela"<<endl;
		cout<<"1 - ler (D)"<<endl;
		cout<<"2 - ler arquivo tokenizado com index (D)"<<endl;
		cout<<"3 - ler nomes associados a index (D)"<<endl;
		cout<<"4 - mostra classes de flores"<<endl;
		cout<<"111 - voltar"<<endl;
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
				mostraClasseDeFlores();
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

void etapa2(){
	int op;
	do{
		cout<<"========================================================"<<endl;
		cout<<"Aluno: Leonardo de Oliveira Campos"<<endl;
		cout<<"Centro Federal de Educação Tecnológica de Minas Gerais"<<endl;
		cout<<"========================================================"<<endl;
		cout<<"===MENU==="<<endl;
		cout<<"1 - ler (T) coloca em Fila e tokeniza"<<endl;
		cout<<"2 - processaFila"<<endl;
		cout<<"3 - Combinações"<<endl;
		cout<<"111 - voltar"<<endl;
		cin>>op;
		switch (op)
		{
			case 0:
				system("clear || cls"); 
				break;
			case 1:
				poeNaFilaALinha();
				break;
			case 2:
                processaFila();
				break;
			case 3:
				//combinacao1();
				//combinacao2();
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

void etapa3(){}

void etapa4(){}

#endif 