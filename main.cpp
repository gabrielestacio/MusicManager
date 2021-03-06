#include <iostream>
#include <string>
#include <cstdlib> //só pra limpar a tela do terminal
#include "music.h"
#include "linkedlist.h"
#include "playlist.h"
#include "linkedplaylist.h"

using namespace std;

//Telas principais

//Menu inicial
int telaInicial(){
	int resposta;

	system("clear");
	cout << "Olá! Seja bem-vindo! O que você deseja fazer?\nDigite 1 se você quer acessar as músicas.\nDigite 2 se você quer acessar as playlists.\nDigite qualquer outro número para sair do sistema.\n\n";
	cin >> resposta;
	return resposta;
}
//Menu de saída
int telaSaida(){
	char decisao;
	
	system("clear");
	cout << "Poxa, você já está indo? :(\nSe você tem certeza que quer sair, digite S. Se decidiu ficar mais um pouco, digite N.\n\n";
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

//Telas de gerenciamento de música

//Menu inicial da seção de músicas
int telaInicialMus(){
	int resposta;

	system("clear");
	cout << "O que você quer fazer?\nDigite 1 para adicionar uma música no sistema.\nDigite 2 para adicionar uma lista de músicas no sistema.\nDigite 3 para remover uma música do sistema.\nDigite 4 para remover uma lista de músicas do sistema.\nDigite 5 para listar as músicas cadastradas.\n\n";
	cin >> resposta;
	return resposta;
}
//Menu de adicionar uma nova música
void telaAddMus(List *l){
	Music m;

	system("clear");
	m = newMusic();
	appendMusic(l, m);
}
//Menu para adicionar múltiplas músicas
void telaAddMultMus(List *l){
	char resposta;
	bool decisao = true;
	Music m;
	List *lista = new List;
	Node *temp = new Node;

	system("clear");
	while(decisao == true){
		m = newMusic();
		cout << "\n_______________________________________\n"; 
		temp->musica = &m;
		temp->next = NULL;
		lista = lista.operator<<(temp, lista);
		cout << "Quer adicionar mais alguma música? (S/N)" << endl;
		cin >> resposta;
		//Quer adicionar mais músicas
		if((resposta == 83) || (resposta == 115)){
			decisao = true;
		}
		//Não quer adicionair mais músicas. Qualquer entrada diferente de S ou s entenderá que o usuário não quer mais adicionar músicas.
		else{
			decisao = false;
		}
		cout << "\n_______________________________________\n"; 
	}
	*l = l->operator+(*l, *lista);
}
//Menu de remover uma música
void telaRemoveMus(List *l){
	dropMusic(l);
}
//Menu de remover múltiplas músicas
void telaRemoveMultMus(List *l){
	int pos;
	char resposta;
	bool decisao = true;
	Music m;
	List *lista = new List;
	Node *temp = new Node;

	system("clear");
	while(decisao == true){
		l->displayList();
		cout << "\n_______________________________________\n"; 
		cout << "Posição da música que será excluída: ";
		cin >> pos;
		temp = l->getListHead();
		for(int i = 1; i < pos; i++){
			temp = temp->next;
		}
		lista = lista.operator<<(temp, lista);
		cout << "Quer adicionar mais alguma música? (S/N)" << endl;
		cin >> resposta;
		//Quer adicionar mais músicas
		if((resposta == 83) || (resposta == 115)){
			decisao = true;
		}
		//Não quer adicionair mais músicas. Qualquer entrada diferente de S ou s entenderá que o usuário não quer mais adicionar músicas.
		else{
			decisao = false;
		}
		cout << "\n_______________________________________\n"; 
	}
	l->deleteposition(*lista);
}
//Menu de listar as músicas
void telaListMus(List *l){
	if(l->getListHead() != NULL){
		listMusic(l);
	}
	else{
		cout << "Nenhuma música cadastrada.\n";
	}
}
//Menu de saída da seção de músicas
int telaFinalMus(){
	char decisao;

	system("clear");
	cout << "Deseja continuar gerenciando músicas? (S/N)" << endl;
	cin >> decisao;

	//Quer voltar para a tela inicial
	if((decisao == 78) || (decisao == 110)){
		return 0;
	}
	//Quer continuar
	else if((decisao == 83) || (decisao == 115)){
		return 1;
	}
	else{
		return 2;
	}
}

//Telas de gerenciamento de playlists

//Menu inicial da seção de playlists
int telaInicialPlay(){
	int resposta;

	system("clear");
	cout << "O que você quer fazer?\nDigite 1 para adicionar playlists no sistema.\nDigite 2 para remover playlists do sistema.\nDigite 3 para listar as playlists cadastradas.\nDigite 4 para adicionar músicas à uma playlist.\nDigite 5 para juntar duas playlists.\nDigite 6 para remover músicas de uma playlist.\nDigite 7 para remover as músicas uma playlist de uma outra playlist.\nDigite 8 para mover músicas dentro da playlist.\n\n";
	cin >> resposta;
	return resposta;
}
//Menu de criação de uma nova playlist
void telaNewPlay(ListPlaylist *lp){
	Playlist p;

	system("clear");
	p = newPlaylist();
	appendPlaylist(lp, p);
}
//Menu de exclusão de uma playlist
void telaDropPlay(ListPlaylist *lp){
	Playlist p;

	system("clear");
	p = newPlaylist();
	dropPlaylist(lp);
}
//Menu de listagem das playlists
void telaListPlay(ListPlaylist *lp){
	system("clear");
	listPlaylist(lp);
}
//Menu de adição de músicas à uma playlist
void telaAddPlay(ListPlaylist *lp, List *l){
	Playlist p;
	string nome;

	system("clear");
	listPlaylist(lp);
	cout << "\n\nQual o nome da playlist que você quer alterar?" << endl;
	getline(cin, nome); //incrementar isso na insertPlaylist
	cin.ignore();
	p.setPlaylistName(nome);

	cout << "\n\n_______________________________________\n\n";	
	insertPlaylist(&p, l);
}
//Menu de adição de múltiplas músicas à uma playlist baseada em outra playlist
int telaAddMultPlay(ListPlaylist *lp){
	string *nome1 = new string;
	string *nome2 = new string;
	Playlist *p = new Playlist;
	Playlist p1, p2, pfinal;
	Pnode *temp = new Pnode


	system("clear");
	cout << *lp << endl;
	cout << "\n_______________________________________\n\nPrimeira playlist: " << endl;
	getline(cin, *nome1);
	cout << "Segunda Playlist: " << endl;
	getline(cin, *nome2);
	cout << "\n_______________________________________\n\n";
	
	//Buscando a primeira playlist desejada pelo usuário
	temp = lp.getPhead();
	while(temp != NULL){
		if(temp->playlist->playlist == nome1){
			p->playlist = nome1;
			temp = NULL;
		}
		else{
			temp = temp->next;
		}
	}

	if(p->playlist == NULL){
		cout << "Nome inválido."
	}
	else{
		p1 = *p;
	}

	//Buscando a segunda playlist desejada pelo usuário
	temp = lp.getPhead();
	while(temp != NULL){
		if(temp->playlist->playlist == nome2){
			p->playlist = nome2;
			temp = NULL;
		}
		else{
			temp = temp->next;
		}
	}

	if(p->playlist == NULL){
		cout << "\nNome inválido.\n"
	}
	else{
		p2 = *p;
	}

	//Juntando as playlists
	if((p1 == NULL) || (p2 == NULL)){
		cout << "\nOperação falhou. Playlist inexistente.\n"
		return 1;
	}
	else{
		pfinal = p1.operator+(p1, p2);
		appendPlaylist(lp, pfinal);
		return 0;
	}
}
//Menu de remoção de músicas de uma playlist
void telaRemovePlay(ListPlaylist *lp){
	Playlist p;
	string nome;

	system("clear");
	listPlaylist(lp);
	cout << "\n\nQual o nome da playlist que você quer alterar?" << endl;
	getline(cin, nome); //incrementar isso na removePlaylist
	cin.ignore();
	p.setPlaylistName(nome);
	
	cout << "\n\n_______________________________________\n\n";
	removePlaylist(&p);
}
//Menu de remoção de múltiplas músicas de uma playlist baseada em outra playlist
int telaRemoveMultPlay(ListPlaylist *lp){
	string *nome1 = new string;
	string *nome2 = new string;
	Playlist *p = new Playlist;
	Playlist p1, p2, pfinal;
	Pnode *temp = new Pnode


	system("clear");
	cout << *lp << endl;
	cout << "\n_______________________________________\n\nPrimeira playlist: " << endl;
	getline(cin, *nome1);
	cout << "Segunda Playlist: " << endl;
	getline(cin, *nome2);
	cout << "\n_______________________________________\n\n";
	
	//Buscando a primeira playlist desejada pelo usuário
	temp = lp.getPhead();
	while(temp != NULL){
		if(temp->playlist->playlist == nome1){
			p->playlist = nome1;
			temp = NULL;
		}
		else{
			temp = temp->next;
		}
	}

	if(p->playlist == NULL){
		cout << "Nome inválido."
	}
	else{
		p1 = *p;
	}

	//Buscando a segunda playlist desejada pelo usuário
	temp = lp.getPhead();
	while(temp != NULL){
		if(temp->playlist->playlist == nome2){
			p->playlist = nome2;
			temp = NULL;
		}
		else{
			temp = temp->next;
		}
	}

	if(p->playlist == NULL){
		cout << "\nNome inválido.\n"
	}
	else{
		p2 = *p;
	}

	//Juntando as playlists
	if((p1 == NULL) || (p2 == NULL)){
		cout << "\nOperação falhou. Playlist inexistente.\n"
		return 1;
	}
	else{
		p1 = p1.operator-(p1, p2);
		return 0;
	}	
}
//Menu de organização de uma playlist
void telaMovePlay(ListPlaylist *lp){
	Playlist p;
	string nome;

	system("clear");
	listPlaylist(lp);
	cout << "\n\nQual o nome da playlist que você quer alterar?" << endl;
	getline(cin, nome); //incrementar isso na movePlaylist
	cin.ignore();
	p.setPlaylistName(nome);
	
	cout << "\n\n_______________________________________\n\n";
	movePlaylist(&p);
}
//Menu de saída da seção de playlists
int telaFinalPlay(){
	char decisao;

	system("clear");
	cout << "Deseja continuar gerenciando playlists? (S/N)" << endl;
	cin >> decisao;

	//Quer voltar para a tela inicial
	if((decisao == 78) || (decisao == 110)){
		return 0;
	}
	//Quer continuar
	else if((decisao == 83) || (decisao == 115)){
		return 1;
	}
	else{
		return 2;
	}
}

//Função principal
int main(int argc, char *argv[]){
	//Retornos das telas principais
	int resInicial = 0, resSaida = 0;
	//Retorno das telas de músicas
	int resIniMus = 0, resFimMus = 0;
	//Retorno das telas de playlists
	int resIniPlay = 0, resFimPlay = 0;
	//Lista geral de músicas cadastradas
	List *lista = new List;
	//Lista geral de playlists cadastradas
	ListPlaylist *playlists = new ListPlaylist;

	do{
		//Tela inicial
		resInicial = telaInicial();
	
		//Gerenciamento de músicas
		if(resInicial == 1){
			do{
				resIniMus = telaInicialMus();
	
				switch(resIniMus){
					case 1: //Adicionar música
						telaAddMus(lista);
						resFimMus = telaFinalMus();
						//Caso o usuário digite um valor diferente de S/s ou N/n em telaFinalMus(), entra no loop até ele digitar um dos valores válidos;
						while(resFimMus == 2){
							resFimMus = telaFinalMus();
						}
						break;
		
					case 2: //Adicionar várias músicas
						telaAddMultMus(lista);
						resFimMus = telaFinalMus();
						//Caso o usuário digite um valor diferente de S/s ou N/n em telaFinalMus(), entra no loop até ele digitar um dos valores válidos;
						while(resFimMus == 2){
							resFimMus = telaFinalMus();
						}
						break;

					case 3: //Excluir música
						telaRemoveMus(lista);
						resFimMus = telaFinalMus();
						//Caso o usuário digite um valor diferente de S/s ou N/n em telaFinalMus(), entra no loop até ele digitar um dos valores válidos;
						while(resFimMus == 2){
							resFimMus = telaFinalMus();
						}
						break;
	
					case 4: //Excluir várias músicas
						telaRemoveMultMus(lista);
						resFimMus = telaFinalMus();
						//Caso o usuário digite um valor diferente de S/s ou N/n em telaFinalMus(), entra no loop até ele digitar um dos valores válidos;
						while(resFimMus == 2){
							resFimMus = telaFinalMus();
						}
						break;

					case 5: //Listar músicas
						telaListMus(lista);
						resFimMus = telaFinalMus();
						//Caso o usuário digite um valor diferente de S/s ou N/n em telaFinalMus(), entra no loop até ele digitar um dos valores válidos;
						while(resFimMus == 2){
							resFimMus = telaFinalMus();
						}
						break;
	
					default:
						break;
				}
			}while(resFimMus == 1);
		}
			
		//Gerenciamento de playlists
		else if(resInicial == 2){
			do{
				resIniPlay = telaInicialPlay();
	
				switch(resIniPlay){
					case 1: //Criar playlist
						telaNewPlay(playlists);
						resFimPlay = telaFinalPlay();
						//Caso o usuário digite um valor diferente de S/s ou N/n em telaFinalPlay(), entra no loop até ele digitar um dos valores válidos;
						while(resFimPlay == 2){
							resFimPlay = telaFinalPlay();
						}
						break;

					case 2: //Excluir playlist
						telaDropPlay(playlists);
						resFimPlay = telaFinalPlay();
						//Caso o usuário digite um valor diferente de S/s ou N/n em telaFinalPlay(), entra no loop até ele digitar um dos valores válidos;
						while(resFimPlay == 2){
							resFimPlay = telaFinalPlay();
						}
						break;

					case 3: //Listar playlists
						telaListPlay(playlists);
						resFimPlay = telaFinalPlay();
						//Caso o usuário digite um valor diferente de S/s ou N/n em telaFinalPlay(), entra no loop até ele digitar um dos valores válidos;
						while(resFimPlay == 2){
							resFimPlay = telaFinalPlay();
						}
						break;

					case 4: //Incrementar playlist
						telaAddPlay(playlists, lista);
						resFimPlay = telaFinalPlay();
						//Caso o usuário digite um valor diferente de S/s ou N/n em telaFinalPlay(), entra no loop até ele digitar um dos valores válidos;
						while(resFimPlay == 2){
							resFimPlay = telaFinalPlay();
						}
						break;
		
					case 5: //Adicionar todas as músicas de uma playlist numa outra
						telaAddMultPlay(playlists);
						resFimPlay = telaFinalPlay();
						//Caso o usuário digite um valor diferente de S/s ou N/n em telaFinalPlay(), entra no loop até ele digitar um dos valores válidos;
						while(resFimPlay == 2){
							resFimPlay = telaFinalPlay();
						}
						break;

					case 6: //Reduzir playlist
						telaRemovePlay(playlists);
						resFimPlay = telaFinalPlay();
						//Caso o usuário digite um valor diferente de S/s ou N/n em telaFinalPlay(), entra no loop até ele digitar um dos valores válidos;
						while(resFimPlay == 2){
							resFimPlay = telaFinalPlay();
						}
						break;

					case 7: //Remover todas as músicas de uma playlist da outra
						telaRemoveMultPlay(playlists);
						resFimPlay = telaFinalPlay();
						//Caso o usuário digite um valor diferente de S/s ou N/n em telaFinalPlay(), entra no loop até ele digitar um dos valores válidos;
						while(resFimPlay == 2){
							resFimPlay = telaFinalPlay();
						}
						break;
	
					case 8: //Alterar ordem da playlist
						telaMovePlay(playlists);
						resFimPlay = telaFinalPlay();
						//Caso o usuário digite um valor diferente de S/s ou N/n em telaFinalPlay(), entra no loop até ele digitar um dos valores válidos;
						while(resFimPlay == 2){
							resFimPlay = telaFinalPlay();
						}
						break;
	
					default:
						break;
				}
			}while(resFimPlay == 1);
		}
	
		//Saída do sistema
		else{
			resSaida = telaSaida();
	
			//QEntrada Inválida
			if(resSaida == 2){
				while(resSaida == 2){
					resSaida = telaSaida();
				}
			}
			//Quer sair
			else if(resSaida == 1){
				system("clear");
				cout << "Até a próxima! :D\n\n";
				return 1;
			}
			//Se resSaída = 0, o programa vai simplesmente se manter dentro do do/while.
		}
	}while(resSaida != 1);

	return 0;
}