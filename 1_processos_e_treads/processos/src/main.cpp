#include "menu.hpp"
#include "includes.hpp"

int main(){ 
	cin.tie(0);
	cout.tie(0);
	cout<<"0 - sair"<<endl;
	cout<<"1 - Usar menu por partes"<<endl;
	cout<<"2 - Usar 1 opção para simular todo o SO"<<endl;
	int op; cin>>op;
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
		geral();
		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<double> elapsed_seconds = end-start;
		std::cout << "tempo: " << elapsed_seconds.count() <<endl;
		break;
	}
	return 0;
}
