#include <iostream>
#include <cstdlib>
#include "telas.hpp"

using namespace std;

//Tela Inical
int telaInicial(){
	int resposta; //Armazena a resposta do usuário

	system("clear");

	cout << ">>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	cout << "M U S I C   M A N A G E R" << endl;
	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<\n\n" << endl;

	//Imprimindo as opções do usuário
	cout << "Olá! Seja bem-vindo! O que você deseja gerenciar? Digite o número correspondente." << endl;
	cout << "1 = Músicas" << endl;
	cout << "2 = Playlists" << endl;
	cout << "Qualquer outro número = Sair do sistema\n" << endl;
	cin >> resposta;
	return resposta;
}

//Tela de Saída
int telaSaida(){
	char decisao; //Define se o usuário quer sair ou não do sistema
	
	system("clear");

	cout << ">>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	cout << "M U S I C   M A N A G E R" << endl;
	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<\n\n" << endl;

	//Verificando se o usuário quer mesmo sair
	cout << "Poxa, você já está indo? :(" << endl;
	cout << "Se você tem certeza que quer sair, digite S. Se decidiu ficar mais um pouco, digite N.\n" << endl;
	cin >> decisao;

	//Quer continuar (78 e 110 correspondem a N e n na tabela ASCII)
	if((decisao == 78) || (decisao == 110)){
		return 0;
	}
	//Quer sair (83 e 115 correspondem a S e s na tabela ASCII)
	else if((decisao == 83) || (decisao == 115)){
		return 1;
	}
	//Entrada inválida
	else{
		return 2;
	}
}

//Tela inicial da seção de músicas
int telaInicialMus(){
	int resposta; //Armazena a resposta do usuário

	system("clear");

	cout << ">>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	cout << "M U S I C   M A N A G E R" << endl;
	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<\n\n" << endl;

	cout << "O que você quer fazer?" << endl;
	cout << "1 = Adicionar uma música no sistema." << endl;
	cout << "2 = Remover uma música no sistema." << endl;
	cout << "3 = Listar as músicas cadastradas no sistema." << endl;
	//cout << "2 = Adicionar uma lista de músicas no sistema.\nDigite 3 para remover uma música do sistema.\nDigite 4 para remover uma lista de músicas do sistema.\nDigite 5 para listar as músicas cadastradas.\n\n";
	cout << "Qualquer outro número = Voltar para a tela inicial.\n" << endl;
	cin >> resposta;
	return resposta;
}

//Tela de saída da seção de músicas
int telaSaidaMus(){
	char decisao; //Define se o usuário quer continuar gerenciando músicas ou não.

	cout << "\n_______________________________________\n\n" << endl;
	cout << "Deseja continuar gerenciando músicas? (S/N)\n" << endl;
	cin >> decisao;

	//Quer voltar para a tela inicial
	if((decisao == 78) || (decisao == 110)){
		return 0;
	}
	//Quer continuar
	else if((decisao == 83) || (decisao == 115)){
		return 1;
	}
	//Entrada Inválida
	else{
		return 2;
	}
}

//Tela inicial da seção de playlists
int telaInicialPlaylist(){
	int resposta; //Armazena a resposta do usuário

	system("clear");

	cout << ">>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	cout << "M U S I C   M A N A G E R" << endl;
	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<\n\n" << endl;

	cout << "O que você quer fazer?" << endl;
	cout << "1 = Criar uma nova playlist." << endl;
	cout << "2 = Adicionar uma música numa playlist." << endl;
	cout << "3 = Remover uma música de uma playlist." << endl;
	cout << "4 = Mover uma música dentro de uma playlist." << endl;
	cout << "5 = Excluir uma playlist do sistema." << endl;
	cout << "6 = Listar as playlists cadastradas no sistema." << endl;
	cout << "Qualquer outro número = Voltar para a tela inicial.\n" << endl;
	cin >> resposta;
	return resposta;
}

//Tela de saída da seção de playlists
int telaSaidaPlaylist(){
	char decisao; //Define se o usuário quer continuar gerenciando playlists ou não.

	cout << "\n_______________________________________\n\n" << endl;
	cout << "Deseja continuar gerenciando playlists? (S/N)\n" << endl;
	cin >> decisao;

	//Quer voltar para a tela inicial
	if((decisao == 78) || (decisao == 110)){
		return 0;
	}
	//Quer continuar
	else if((decisao == 83) || (decisao == 115)){
		return 1;
	}
	//Entrada Inválida
	else{
		return 2;
	}
}