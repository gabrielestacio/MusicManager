#include "playlist.h"
#include "linkedlist.h"
#include "music.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

//Construtor
Playlist::Playlist(){
	playlist = new string;
	playing = NULL;
	head = NULL;
	tail = NULL;
}

//Construtor cópia (v0.2)
Playlist::Playlist(const Playlist &p){
	playlist = p.playlist;
	playing = p.playing;
	head = p.head;
	tail = p.tail;
}

//Insere o nome da playlist
void Playlist::setPlaylistName(string nome){
	playlist = &nome;
}

//Acessa o nome da playlist
string * Playlist::getPlaylistName(){
	return playlist;
}

//Acessa qual é a música que está tocando
Node * Playlist::getPlaying(){
	return playing;
}

//Acessa a primeira música da playlist
Node * Playlist::getPlaylistHead(){
	return head;
}

//Acessa a última música da playlist
Node * Playlist::getPlaylistTail(){
	return tail;
}

//Armazena a música que será transferida de uma playlist para outra
Node * Playlist::storemusic(int &position){
	Node *temp = new Node;
	temp = head;
	for(int i = 1; i < position; i++){
		temp = temp->next;
	}
	return temp;
}

//Adiciona uma nova música à playlist
void Playlist::addMusic(Node *temp){
	if(head == NULL){
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else{
		tail->next = temp;
		tail = temp;
		temp->next = NULL;
	}
}

//Adiciona todas as músicas de uma playlist dada na que está sendo criada (v0.2)
void Playlist::addMusic(Playlist &p){
	Node *temp = new Node;
	temp = p.getPlaylistHead();

	tail->next = temp;
	while(temp != NULL){
		tail = temp;
		temp = temp->next;
	}
}

//Exclui uma música da playlist
void Playlist::dropMusic(int &position){
	Node *temp = new Node;
	temp = head;
		for(int i = 1; i < position; i++){
		temp = temp->next;
	}
	if(position == 1){
		head = head->next;
		delete temp;
	}
	else{
		Node *pre = new Node;
		Node *curr = new Node;
		curr = head;
		for(int i = 1; i < position; i++){
			pre = curr;
			curr = curr->next;
		}
		pre->next = curr->next;
	}
}

//Exclui todas as músicas de uma playlist dada na que está sendo criada (v0.2)
int Playlist::dropMusic(Playlist &p){
	int i = 0;
	Node *del = new Node;
	Node *head = new Node;
	Node *temp = new Node;
	Node *pre = new Node

	del = head;
	while(del != NULL){
		temp = p.getPlaylistHead();
		if(temp == del){
			del = del->next;
			head = del;
		}
		while(temp != NULL){
			if(temp == del->next){
				pre = del;
				del = del->next;
				pre->next = del->next;
				i += 1;
			}
		}
		del = del->next;
	}
	return i;
}

//Move músicas dentro da playlist
void Playlist::moveMusic(Playlist *playlist, int &ini_position, int &end_position){
	Node *tempMove = new Node;
	tempMove = head;
		for(int i = 1; i < ini_position; i++){
		tempMove = tempMove->next;
	}
	playlist->dropMusic(ini_position);
	Node *pre = new Node;
	Node *curr = new Node;
	curr = head;
	for(int i = 1; i < end_position; i++){
		pre = curr;
		curr = curr->next;
	}
	pre->next = tempMove;
	tempMove->next = curr;
}

//Toca a próxima música
Node * Playlist::playNext(){
	playing = head;
	if (playing->next != NULL){
		Node *temp = playing;
		playing = playing->next;
		return temp;
	}
	else{
		return NULL;
	}
}

//Imprime a playlist
void Playlist::displayPlaylist(){
	Node *temp = new Node;
	temp = head;
	Music mus;
	string *title, *artist;
	while(temp != NULL){
		mus = temp->musica;
		title = mus.getTitle();
		artist = mus.getArtist();
		cout << title << ", de " << artist << "\n";
		temp = temp->next;
	}
}

//Concatena duas playlists (v0.2)
Playlist Playlist::operator+(Playlist p1, Playlist p2){
	Playlist pfinal;
	Node *temp = new Node;
	Node *duplicate = new Node;

	temp = p1.getPlaylistHead();
	pfinal->head = temp;
	if(temp == NULL){
		cout << p1->playlist << " é uma playlist vazia.\n" << endl;
	}
	else{
		while(temp != NULL){
			pfinal->tail = temp;
			temp = temp->next;
		}
	}

	duplicate = pfinal.getPlaylistHead();
	for(temp = p2.getPlaylistHead(); temp != NULL; temp = temp->next){
		while(duplicate != NULL){
			if(duplicate == temp){
				temp = temp->next;
			}
			duplicate = duplicate->next;
		}
		pfinal->tail = temp;
	}
	return pfinal;
}

//Cria uma cópia de uma playlist dada com a música dada adicionada no final (v0.2)
Playlist Playlist::operator+(Playlist p, Music m){
	Node *temp = new Node;
	temp->musica = m;
	temp->next = NULL;

	p->tail->next = temp;
	p->tail = temp;

	return p;
}

//Aplica a "diferença de conjuntos" para duas playlist (v0.2)
Playlist Playlist::operator-(Playlist p1, Playlist p2){
	Playlist pfinal;
	Node *temp = new Node;
	Node *duplicate = new Node;
	Node *drop = new Node;
	Node *drop_head = new Node

	temp = p1.getPlaylistHead();
	pfinal->head = temp;
	while(temp != NULL){
		pfinal->tail = temp;
		temp = temp->next;
	}

	duplicate = pfinal.getPlaylistHead();
	temp = p2.getPlaylistHead();

	if(duplicate == temp){
		drop_head = duplicate;
		duplicate = duplicate->next;
		delete drop_head;
	}

	while(duplicate != NULL){
		while(temp != NULL){
			if(duplicate->next == temp){
				drop = duplicate;
				duplicate = duplicate->next;
				drop->next = duplicate->next;
			}
			temp = temp->next;
		}
		duplicate = duplicate->next;
	}
	return pfinal;
}

//Cria uma cópia de uma playlist excluindo a música dada (v0.2)
Playlist Playlist::operator-(Playlist p, Music m){
	Node *temp = new Node;
	Node *drop = new Node;
	Node *prox = new Node;
	temp = p.getPlaylistHead();
	
	if(temp->musica == &m){
		drop = temp;
		temp = temp->next;
		delete drop;
	}

	while(temp != NULL){
		prox = temp->next;
		if(prox->musica == &m){
			temp->next = prox->next;
		}
	}
	return p;
}

//Remove a última música de uma playlist dada e a retorna para o usuário (v0.2)
void Playlist::operator>>(Playlist &p, Music &m){
	Music *mus
	Node *temp = new Node;

	temp = p->head;
	if(temp == NULL){
		m = NULL;
	}
	else{
		while(temp->next != p->tail){
			temp = temp->next;
		}
	
		mus = p->tail->musica;
	
		p->tail = temp;
		p->tail->next = NULL;

		m = mus;
	}
	return m;
}

//Insere uma música dada no fim de uma playlist (v0.2)
void Playlist::operator<<(Playlist &p, Music m){
	Node *temp = new Node;

	if(m == NULL){
		return p;
	}
	else{
		temp = p->tail->next;
		temp->musica = &m;
		temp->next = NULL;
		p->tail = temp;
	}
}

//Destrutor	
Playlist::~Playlist(){
	//delete playlist;
}

//Cria uma nova playlist
Playlist newPlaylist(){
	string nome;

	cout << "Nome da playlist: ";
	cin.ignore();
	getline(cin, nome);

	Playlist nova_playlist;
	nova_playlist.setPlaylistName(nome);
	return nova_playlist;
}

//Adiciona uma música na playlist
void insertPlaylist(Playlist *p, List *l){
	int posicao = 1;
	Node *transferencia; //armazena a música que será transferida da lista geral pra playlist

	l->displayList();
	cout << "\nDigite a posição da música que você quer adicionar: ";
	cin >> posicao;
	transferencia = l->storeMusic(posicao);
	p->addMusic(transferencia);
}

//Exclui uma música da playlist
void removePlaylist(Playlist *p){
	int posicao = 1;

	p->displayPlaylist();
	cout << "\nDigite a posição da música que você quer remover: ";
	cin >> posicao;
	p->dropMusic(posicao);
}

//Move músicas dentro da playlist
void movePlaylist(Playlist *p){
	int posicao_inicial, posicao_final;

	p->displayPlaylist();
	cout << "\nDigite a posição da música que você quer mover: ";
	cin >> posicao_inicial;
	cout << "\nDigite a posição para a qual você quer mover a música: ";
	cin >> posicao_final;

	p->moveMusic(p, posicao_inicial, posicao_final);
}