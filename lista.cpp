#include "lista.hpp"
#include "plista.hpp"
#include "musica.hpp"
#include <iostream>
#include <string>

using namespace std;

//Construtor
List::List(){
	head = nullptr;
	tail = nullptr;
}

//Construtor cópia (v0.2)
List::List(const List &l){
	head = l.head;
	tail = l.tail;
}

//Retorna o primeiro elemento da lista
Node * List::getListHead(){
	return head;
}
		
//Retorna o último elemento da lista
Node * List::getListTail(){
	return tail;
}

//Imprimindo as músicas cadastradas
void List::displayList(){
	Node *temp = new Node;
	int i = 1;

	temp = head;

	cout << (">>>>>>>>>>>>>>>>>>>>>>>>") << endl;
	cout << "M U S I C   M A N A G E R" << endl;
	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<\n" << endl;

	while(temp != nullptr){
		cout << i << ". " << temp->musica.getTitle() << ", de " << temp->musica.getArtist() << endl;
		temp = temp->next;
		i += 1;
	}
}

//Verifica se uma música já foi cadastrada
bool List::searchMusic(Music m){
	Node *temp = new Node;

	if(head == nullptr){
		return false;
	}
	else{
		temp = head;
		while(temp != nullptr){
			if((temp->musica.getTitle() == m.getTitle()) && (temp->musica.getArtist() == m.getArtist())){
				return true;
			}
			else{
				temp = temp->next;
			}
		}
		return false;
	}
}

//Retorna o nó que será transferido da lista para uma playlist
Node * List::storeMusic(int pos){
	Node *temp = new Node;
	if(head == nullptr){
		return nullptr;
	}
	else{
		temp = head;
		for(int i = 1; i < pos; i++){
			temp = temp->next;
		}
		return temp;
	}	
}

//Adiciona uma nova música à lista
void List::addMusic(){
	Music m;
	Node *temp = new Node;
	bool repetida = false;

	system("clear");

	cout << (">>>>>>>>>>>>>>>>>>>>>>>>") << endl;
	cout << "M U S I C   M A N A G E R" << endl;
	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<\n" << endl;

	m.newMusic();
	temp->musica = m;
	temp->next = nullptr;
	
	repetida = searchMusic(m);
	
	if(repetida == false){
		if(head == nullptr){
			head = temp;
			tail = temp;
			temp = nullptr;
		}
		else{
			tail->next = temp;
			tail = temp;
		}
	}

	cout << "_______________________________________\n" << endl;

	if((tail->musica.getTitle() == m.getTitle()) && (tail->musica.getArtist() == m.getArtist()) && (repetida == false)){
		cout << "Música cadastrada com sucesso :D" << endl;
	}
	/*else if(((tail->musica.getTitle() != m.getTitle()) || (tail->musica.getArtist() != m.getArtist())) && (repetida == true)){
		cout << "Música já cadastrada :/" <<endl;
	}*/
	else{
		cout << "Música já cadastrada :/" << endl;
	}
}

//Adiciona uma lista de músicas á lista atual (v0.2)
void List::addMusic(List &l){
	Music m;
	Node *temp = new Node;
	bool repetida = false, sair = false;
	char resposta;

	system("clear");

	cout << (">>>>>>>>>>>>>>>>>>>>>>>>") << endl;
	cout << "M U S I C   M A N A G E R" << endl;
	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<\n" << endl;

	while(sair == true){
		m.newMusic();
		repetida = searchMusic(m);
		if(repetida == false){
			temp = l.getListHead();
			if(head == nullptr){
				head = temp;
				tail = temp;
				temp = temp->next;
				while(temp != nullptr){
					tail->next = temp;
					tail = temp;
					temp = temp->next;
				}		
			}
			else{
				while(temp != nullptr){
					tail->next = temp;
					tail = temp;
					temp = temp->next;
				}
			}
		}
		cout << "_______________________________________\n" << endl;
		cout << "Quer adicionar mais alguma música? (S/N)" << endl;
		cin >> resposta;
		//Não quer adicionar mais músicas. Qualquer entrada diferente de S ou s entenderá que o usuário não quer mais adicionar músicas.
		if((resposta != 83) || (resposta != 115)){
			return;
		}
		cout << "_______________________________________\n" << endl;
	}
}

//Remove das playlists uma música que é removida do sistema
void List::removeFromPlaylist(Plist &lp, int pos){
	Node *play = head; //O nó que vai fazer a exclusão nas playlists
	bool tem_playlist = false;

	for(int i = 1; i < pos; i++){
		play = play->next;
	}

	if(pl.getPlistHead() != nullptr){
		Pnode *pdrop = pl.getPlistHead();
		Playlist p;

		while(pdrop != nullptr){
			p = pdrop->playlist;
			tem_playlist = p.searchPMusic(play->musica);
			if(tem_playlist == true){
				Node *previous = new Node;
				Node *drop = new Node;
				
				previous = p.getPlaylistHead();
				while (previous->next != play){
					previous = previous->next;
				}
				drop = previous->next;
				previous->next = drop->next;
				delete drop;
			}
			pdrop = pdrop->next;
		}
	}
}

//Removendo uma música da lista
void List::removeMusic(Ṕlist &lp){
	int posicao;

	system("clear");

	displayList();
	cout << "_______________________________________\n" << endl;
	cout << "Posição da música que será removida: ";
	cin >> posicao;

	for(int i = 1; i < pos; i++){
		play = play->next;
	}

	removeFromPlaylist(lp, posicao)

	if(posicao == 0){
		return;
	}
	else if(posicao == 1){
		Node *temp = head;
		head = head->next;
		delete temp;
	}
	else{
		Node *pre = new Node;
		Node *curr = head;
		for(int i = 1; i < posicao; i++){
			pre = curr;
			curr = curr->next;
		}
		pre->next = curr->next;
	}
}

//Removendo uma lista de músicas do sistema (v0.2)
void List::removeMusic(Plist &lp, List &l){
	Node *temp = new Node;
	int posicao;
	char resposta;
	bool sair = false;
	Music m;

	system("clear");

	while(sair == false){
		displayList();
		cout << "_______________________________________\n" << endl;
		cout << "Posição da música que será removida: ";
		cin >> posicao;
	
		removeFromPlaylist(lp, posicao)

		if(posicao == 0){
			return;
		}
		else if(posicao == 1){
			Node *temp = head;
			head = head->next;
			delete temp;
		}
		else{
			Node *pre = new Node;
			Node *curr = head;
			for(int i = 1; i < posicao; i++){
				pre = curr;
				curr = curr->next;
			}
			pre->next = curr->next;
		}
		cout << "_______________________________________\n" << endl;
		cout << "Quer remover mais alguma música? (S/N)" << endl;
		cin >> resposta;
		//Não quer adicionar mais músicas. Qualquer entrada diferente de S ou s entenderá que o usuário não quer mais adicionar músicas.
		if((resposta != 83) || (resposta != 115)){
			return;
		}
		cout << "_______________________________________\n" << endl;		
	}
}

//Destrutor
List::~List(){
	Node *temp = new Node;

	if(head != nullptr){
		temp = head;
		while(temp != nullptr){
			delete temp;
			temp = temp->next;
		}
	}
}
