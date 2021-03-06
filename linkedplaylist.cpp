#include "linkedplaylist.h"
#include "playlist.h"
#include "linkedlist.h"
#include "music.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

//Construtor
ListPlaylist::ListPlaylist(){
	phead = NULL;
	ptail = NULL;
}

//Acessa a primeira playlist da lista de playlists
Pnode * ListPlaylist::getPhead(){
	return phead;
}

//Acessa a última playlist da lista de playlists		
Pnode * ListPlaylist::getPtail(){
	return ptail;
}

//Insere uma nova playlist na lista de playlists
void ListPlaylist::createPnode(Playlist p){
	Pnode *temp = new Pnode;
	temp->playlist = &p;
	temp->next = NULL;

	if(phead == NULL){
		phead = temp;
		ptail = temp;
		temp = NULL;
	}
	else{
		ptail->next = temp;
		ptail = temp;
	}
}

//Faz a busca de uma playlist na lista de playlists		
Pnode * ListPlaylist::search(Pnode *cabeca, Playlist p){
	Pnode *temp = cabeca;
	Playlist *pl;
	while(temp != NULL){
		pl = temp->playlist;
		if(pl->getPlaylistName() == p.getPlaylistName()){
			return temp;
		}
		else{
			temp = temp->next;
		}
	}
	return NULL;
	/*Pnode *c;
	int i;
	i = 1;
	Playlist *play;
	string *nome1, *nome2;
	for(c = cabeca; c != NULL; c = c->next){
		play = c->playlist;
		nome1 = play->getPlaylistName();
		nome2 = p.getPlaylistName();
		if(nome1 == nome2){
			return i;
		}
		i++;
	}
	i = 0;
	return i;*/
}

//Deleta a primeira playlist da lista de playlists
void ListPlaylist::deletePstart(){
	Pnode *temp = new Pnode;
	temp = phead;
	phead = phead->next;
	delete temp;
}

//Deleta uma playlist da lista de playlists numa posição específica
void ListPlaylist::deletePposition(int &position){
	Pnode *curr = new Pnode;
	Pnode *pre = new Pnode;
	curr = phead;
	for(int i = 1; i < position; i++){
		pre = curr;
		curr = curr->next;
	}
	pre->next = curr->next;
}

//Imprime a lista de playlists cadastradas
void ListPlaylist::displayListPlaylist(){
	Pnode *temp = new Pnode;
	temp = phead;
	Playlist *play;
	string *nome;
	while(temp != NULL){
		play = temp->playlist;
		nome = play->getPlaylistName();
		cout << nome << "\n";
		temp = temp->next;
	}
}

//Destrutor
ListPlaylist::~ListPlaylist(){
}

//Adiciona uma nova playlist à lista de playlists
void appendPlaylist(ListPlaylist *playlists, Playlist p){
	Pnode *temp = new Pnode;
	//int posicao;
//	Pnode *phead;

	//posicao = 1;
//	phead = playlists->getPhead();

	temp = playlists->search(playlists->getPhead(), p);
	if(temp == NULL){
		playlists->createPnode(p);
	}
	else{
		cout << "Playlist já cadastrada.\n\n";
	}
}

//Renove uma playlist da lista de playlists
void dropPlaylist(ListPlaylist *playlists){
	int posicao;
	
	cout << "\n\n_______________________________________\n\n";
	playlists->displayListPlaylist();
	cout << "\n\n_______________________________________\n\n";
	cout << "Digite a posição da playlist que você quer remover: ";
	cin >> posicao;

	if(posicao == 1){
		playlists->deletePstart();
	}
	else{
		playlists->deletePposition(posicao);
	}
}

//Lista todas as playlists cadastradas
void listPlaylist(ListPlaylist *playlists){
	playlists->displayListPlaylist();
}