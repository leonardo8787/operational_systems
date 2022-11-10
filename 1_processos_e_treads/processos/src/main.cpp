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
		geral();
		break;
	default:
		cout<<"Digite uma opção válida!!!"<<endl;
		break;
	}
	return 0;
}
