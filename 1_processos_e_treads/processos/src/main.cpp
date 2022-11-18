#include "menu.hpp"
#include "includes.hpp"

int main(){ 
	cin.tie(0);
	cout.tie(0);
	cout<<"0 - sair"<<endl;
	cout<<"1 - Passo a Passo"<<endl;
	cout<<"2 - Usar 1 opção para simular todo o SO (FIFO)"<<endl;
	cout<<"3 - Usar 2 opção para simular todo o SO (First Job)"<<endl;
	int op; 
	cin>>op;
	switch (op)
	{
		case 0:
			return 0;
			break;
		case 1:
			menu();
			break;
		case 2:
			auto start = std::chrono::steady_clock::now();
			geralFIFO();
			auto end = std::chrono::steady_clock::now();
			std::chrono::duration<double> elapsed_seconds = end-start;
			std::cout << "tempo: " << elapsed_seconds.count() <<endl;
			break;
		// case 3:
		// 	geralFirstJob();
		// 	break;
	}
	return 0;
}
