#ifndef ETAPAS_H_
#define ETAPAS_H_

#include "menu.hpp"
#include "includes.hpp"
#include "read.hpp"

class Etapas{
	private:

    public:
		void geralFIFO();
		void geralFistJob();
		void etapa1();
		void etapa2();
		void etapa3();
		void etapa4();
		void etapa5();
		void etapa6();
};

void geralFIFO(){
	// auto start = std::chrono::steady_clock::now();
	// vector<double> tempo;
	// clock_t t;
	// int tam=10;
	// while(tam--) {
		auto start = std::chrono::steady_clock::now();
		ler();
		Hash();
		HashNomes1();
		classesFlorMetodo();
		lerT();
		// printFilaDeVector();
		iniciaCombinacao();
		produtorEconsumidor();
		interseccoes1();
		interseccaoDasCombinacoes();
		// printaPegaInterseccao2();
		interseccaoClasse();
		interseccaoDasCombinacoes();
		numeroClassesIteracoes();
		cashHash();
		// printaCash();
		interseccaoEtapa4();
		interseccaoDasCombinacoesEtapa4();
		interseccaoClasseEtapa4();
		numeroClassesIteracoesEtapa4();
		// t=clock() - t;
		// cout<<((double)t)/((CLOCKS_PER_SEC/1000))<<endl;
		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<double> elapsed_seconds = end-start;
		std::cout << "tempo geral FIFO: " << elapsed_seconds.count() <<endl;
		// tempo.push_back(elapsed_seconds.count());
	// }
}

void geralFirstJob(){
	// int tam=10;
	// while (tam--)
	// {
		auto start = std::chrono::steady_clock::now();
		ler();
		Hash();
		HashNomes1();
		classesFlorMetodo();
		lerT();
		// printFilaDeVector();
		iniciaCombinacaofirstJob();
		// printCombinacoes();
		interseccoes1();
		interseccaoDasCombinacoes();
		// printaPegaInterseccao2();
		interseccaoClasse();
		interseccaoDasCombinacoes();
		numeroClassesIteracoes();
		cashHash();
		// printaCash();
		interseccaoEtapa4();
		interseccaoDasCombinacoesEtapa4();
		interseccaoClasseEtapa4();
		numeroClassesIteracoesEtapa4();
		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<double> elapsed_seconds = end-start;
		std::cout << "tempo Geral First Job: " << elapsed_seconds.count() <<endl;	
	// }
}

void etapa1(){
	int op;
	do{
		cout<<"========================================================"<<endl;
		cout<<"Aluno: Leonardo de Oliveira Campos"<<endl;
		cout<<"Centro Federal de Educa????o Tecnol??gica de Minas Gerais"<<endl;
		cout<<"========================================================"<<endl;
		cout<<"===MENU==="<<endl;
		cout<<"0 - limpa tela"<<endl;
		cout<<"1 - ler (D)"<<endl;
		cout<<"2 - ler arquivo tokenizado com index (D)"<<endl;
		cout<<"3 - ler nomes associados a index (D)"<<endl;
		cout<<"4 - mostra classes de flores"<<endl;
		cout<<"5 - mostra classes de flores com associa????es"<<endl;
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
			case 5:
				classesFlorMetodo();
				break;
			case 111:
				cout<<"saindo..."<<endl;
				break;
			default:
				cout<<"Escolha uma op????o v??lida"<<endl;
				break;
		}
	}while(op != 111);
}

void etapa2(){
	int op;
	do{
		cout<<"========================================================"<<endl;
		cout<<"Aluno: Leonardo de Oliveira Campos"<<endl;
		cout<<"Centro Federal de Educa????o Tecnol??gica de Minas Gerais"<<endl;
		cout<<"========================================================"<<endl;
		cout<<"===MENU==="<<endl;
		cout<<"1 - ler (T) coloca em Fila e tokeniza"<<endl;
		cout<<"2 - processaFila"<<endl;
		cout<<"3 - Combina dados T.csv"<<endl;
		cout<<"111 - voltar"<<endl;
		cin>>op;
		switch (op)
		{
			case 0:
				system("clear || cls"); 
				break;
			case 1:
				lerT();
				break;
			case 2:
                printFilaDeVector();
				break;
			case 3:
				iniciaCombinacao();
				produtorEconsumidor();
				// printCombinacoes();
				break;
			case 111:
				cout<<"saindo..."<<endl;
				break;
			default:
				cout<<"Escolha uma op????o v??lida"<<endl;
				break;
		}
	}while(op != 111);
}

void etapa3(){
	int op;
	do{
		cout<<"========================================================"<<endl;
		cout<<"Aluno: Leonardo de Oliveira Campos"<<endl;
		cout<<"Centro Federal de Educa????o Tecnol??gica de Minas Gerais"<<endl;
		cout<<"========================================================"<<endl;
		cout<<"===MENU==="<<endl;
		cout<<"1 - intersec????o entre as linhas"<<endl;
		cout<<"2 - printa as intersec????es"<<endl;
		cout<<"3 - printa valores da intersec????o"<<endl;
		cout<<"4 - intersec????o com as classes das flores"<<endl;
		cout<<"111 - voltar"<<endl;
		cin>>op;
		switch (op)
		{
			case 0:
				system("clear || cls"); 
				break;
			case 1:
				interseccoes1();
				break;
			case 2:
				interseccaoDasCombinacoes();
				break;
			case 3:
				printaPegaInterseccao2();
				// printFilaVector();
				break;
			case 4:
            	interseccaoClasse();
				break;
			case 9:
				interseccaoDasCombinacoes();
				break;
			case 111:
				cout<<"saindo..."<<endl;
				break;
			default:
				cout<<"Escolha uma op????o v??lida"<<endl;
				break;
		}
	}while(op != 111);
}

void etapa4(){
	int op;
	do{
		cout<<"========================================================"<<endl;
		cout<<"Aluno: Leonardo de Oliveira Campos"<<endl;
		cout<<"Centro Federal de Educa????o Tecnol??gica de Minas Gerais"<<endl;
		cout<<"========================================================"<<endl;
		cout<<"===MENU==="<<endl;
		cout<<"1 - Intera????es com Classe de flores"<<endl;
		cout<<"2 - passa pela cash"<<endl;
		cout<<"3 - printa Cash"<<endl;
		cout<<"4 - procura intersec????es para nova computa????o"<<endl;
		cout<<"5 - faz computa????o novamente"<<endl;
		cout<<"111 - voltar"<<endl;
		cin>>op;
		switch (op)
		{
			case 0:
				system("clear || cls"); 
				break;
			case 1:
				numeroClassesIteracoes();
				break;
			case 2:
				cashHash();
				break;
			case 3:
				printaCash();
				break;
			case 4:
				interseccaoEtapa4();
				break;
			case 5:
				interseccaoDasCombinacoesEtapa4();
				interseccaoClasseEtapa4();
				numeroClassesIteracoesEtapa4();
				break;
			default:
				cout<<"Escolha uma op????o v??lida"<<endl;
				break;
		}
	}while(op != 111);
}

void etapa5(){
	int op;
	do{
		cout<<"========================================================"<<endl;
		cout<<"Aluno: Leonardo de Oliveira Campos"<<endl;
		cout<<"Centro Federal de Educa????o Tecnol??gica de Minas Gerais"<<endl;
		cout<<"========================================================"<<endl;
		cout<<"===MENU==="<<endl;
		cout<<"1 - POL??TICA(First Job)"<<endl;
		cout<<"111 - voltar"<<endl;
		cin>>op;
		switch (op)
		{
			case 0:
				system("clear || cls"); 
				break;
			case 1:
				break;
			default:
				cout<<"Escolha uma op????o v??lida"<<endl;
				break;
		}
	}while(op != 111);
}

void etapa6(){
	int op;
	do{
		cout<<"========================================================"<<endl;
		cout<<"Aluno: Leonardo de Oliveira Campos"<<endl;
		cout<<"Centro Federal de Educa????o Tecnol??gica de Minas Gerais"<<endl;
		cout<<"========================================================"<<endl;
		cout<<"===MENU==="<<endl;
		cout<<"1 - Produtor e Consumidor com thread"<<endl;
		// cout<<"2 - "<<endl;
		cout<<"111 - voltar"<<endl;
		cin>>op;
		switch (op)
		{
			case 0:
				system("clear || cls"); 
				break;
			case 1:
				auto start = std::chrono::steady_clock::now();
				produtorEconsumidor();
				auto end = std::chrono::steady_clock::now();
				std::chrono::duration<double> elapsed_seconds = end-start;
				std::cout << "tempo: " << elapsed_seconds.count() <<endl;
				break;
		}
	}while(op != 111);
}

#endif 