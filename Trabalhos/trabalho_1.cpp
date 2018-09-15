#include <iostream>
#include "trabalho_1.hpp"
using std::cout;
using std::cin;

int main()
{
	int opcao;
	float valor;
	Deque<float> D;
	
	
	bool erro = inicializar<float>(D);
	if(erro)
	{
		cout << "Erro!\n";
		return 1;
	}
	// apresenta o menu
	while( 1 ){

		cout << "\n1 - Inserir elemento pela esquerda \n2 - Inserir elemento pela direita \n3 - Remover elemento pela esquerda \n4 - Remover elemento pela direita \n0 - Sair\n\nOpcao? ";
		cin >> opcao;

		switch(opcao){

			case 0: exit(0);

			case 1: // insere elemento pela esquerda
			
				cout << "\nValor do elemento a ser inserido pela esquerda?\n";
				cin >> valor;
				inserir_esq(D, valor);

				break;
				
			case 2: // insere elemento pela direita
			
				cout << "\nValor do elemento a ser inserido pela direita?\n";
				cin >> valor;
				inserir_dir(D, valor);

				break;

			case 3: // remove elemento pela esquerda
				if (vazio(D)){

					cout << "\nDeque vazio!!!\n\n";

				}
				else {

					valor = remover_esq(D);
					cout << valor << " removido pela esquerda com sucesso\n\n"; 

				}
				break;

			case 4: // remove elemento pela direita
				if (vazio(D)){

					cout << "\nDeque vazio!!!\n\n";

				}
				else {

					valor = remover_dir(D);
					cout << valor << " removido pela direita com sucesso\n\n"; 

				}
				break;

				default:
					cout << "\nOpcao Invalida\n\n";

		}
	}
	
}
