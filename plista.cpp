#include "plista.hpp"
#include "playlist.hpp"
#include "lista.hpp"
#include "musica.hpp"
#include <iostream>
#include <string>

using namespace std;

//construtor
Plist::Plist(){
	head = nullptr;
	tail = nullptr;
}

//Retorna a primeira playlist
Pnode * Plist::getPlistHead(){
	return head;
}

//Retorna a última playlist
Pnode * Plist::getPlistTail(){
	return tail;
}

//Imprime a lista de playlists na tela
void Plist::displayPlist(){
	Pnode *temp = new Pnode;
	int i = 1;

	temp = head;

	cout << (">>>>>>>>>>>>>>>>>>>>>>>>") << endl;
	cout << "M U S I C   M A N A G E R" << endl;
	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<\n" << endl;	

	while(temp != nullptr){
		cout << i << ". " << temp->playlist.getPlaylistName() << endl;
		temp = temp->next;
		i += 1;
	}
}

//Verifica se uma playlist já está cadastrada no sistema
bool Plist::searchPlaylist(Playlist p){
	Pnode *temp = new Pnode;

	if(head == nullptr){
		return false;
	}
	else{
		temp = head;
		while(temp != nullptr){
			if(temp->playlist.getPlaylistName() == p.getPlaylistName()){
				return true;
			}
			else{
				temp = temp->next;
			}
		}
		return false;
	}
}

//Adicionando uma música na playlist
void Plist::insertMusic(List l){
	Pnode *temp = head;
	List lista = l;
	Playlist p;
	int posicaoplaylist;

	system("clear");

	displayPlist();
	cout << "_______________________________________\n" << endl;
	cout << "Posição da playlist que será alterada: ";
	cin >> posicaoplaylist;
	if(posicaoplaylist == 0){
		return;
	}
	else{
		for(int i = 1; i < posicaoplaylist; i++){
			temp = temp->next;
		}
		p = temp->playlist;
	}

	p.addMusic(lista);
}

//Removendo uma música da playlist
void Plist::dropMusic(){
	Pnode *play = head;
	Playlist p;
	int posicaoplaylist;

	system("clear");

	displayPlist();
	cout << "_______________________________________\n" << endl;
	cout << "Posição da playlist que será alterada: ";
	cin >> posicaoplaylist;
	if(posicaoplaylist == 0){
		return;
	}
	else if(posicaoplaylist == 1){
		p = play->playlist;
	}
	else{
		for(int i = 1; i < posicaoplaylist; i++){
			play = play->next;
		}
		p = play->playlist;
	}

	p.removeMusic();
}

//Movendo uma música dentro da playlist
void Plist::orderMusic(){
	Pnode *play = head;
	Playlist p;
	int posicaoplaylist;

	system("clear");

	displayPlist();
	cout << "_______________________________________\n" << endl;
	cout << "Posição da playlist que será alterada: ";
	cin >> posicaoplaylist;
	if(posicaoplaylist == 0){
		return;
	}
	else if(posicaoplaylist == 1){
		p = play->playlist;
	}
	else{
		for(int i = 1; i < posicaoplaylist; i++){
			play = play->next;
		}
		p = play->playlist;
	}

	p.moveMusic();
}

//Adicionando uma nova playlist
void Plist::addPlaylist(){
	Playlist p;
	Pnode *temp = new Pnode;
	bool repetida = false;

	system("clear");

	cout << (">>>>>>>>>>>>>>>>>>>>>>>>") << endl;
	cout << "M U S I C   M A N A G E R" << endl;
	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<\n" << endl;

	p.newPlaylist();
	temp->playlist = p;
	temp->next = nullptr;

	repetida = searchPlaylist(p);

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

	if((tail->playlist.getPlaylistName() == p.getPlaylistName()) && (repetida == false)){
		cout << "Playlist cadastrada com sucesso :D" << endl;
	}
	/*else if(((tail->musica.getTitle() != m.getTitle()) || (tail->musica.getArtist() != m.getArtist())) && (repetida == true)){
		cout << "Música já cadastrada :/" <<endl;
	}*/
	else{
		cout << "Playlist já cadastrada :/" << endl;
	}
}

//Removendo uma playlist do sistema
void Plist::removePlaylist(){
	int posicao;

	system("clear");

	displayPlist();
	cout << "_______________________________________\n" << endl;
	cout << "Posição da playlist que será removida: ";
	cin >> posicao;

	if(posicao == 0){
		return;
	}
	else if(posicao == 1){
		Pnode *temp = head;
		head = head->next;
		delete temp;
	}
	else{
		Pnode *pre = new Pnode;
		Pnode *curr = head;
		for(int i = 1; i < posicao; i++){
			pre = curr;
			curr = curr->next;
		}
		if(curr == tail){
			pre->next = nullptr;
			tail = pre;
			delete curr;
		}
		else{
			pre->next = curr->next;
		}
	}
}

//Destrutor
Plist::~Plist(){
	Pnode *temp = new Pnode;

	if(head != nullptr){
		temp = head;
		while(temp != nullptr){
			delete temp;
			temp = temp->next;
		}
	}
}