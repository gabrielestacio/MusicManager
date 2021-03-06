#include "music.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <stdlib.h>

using namespace std;

//Construtor
Music::Music(){
	title = new string;
	artist = new string;
}

//Insere o título da música
void Music::setTitle(string titulo){
		title = &titulo;
}

//Insere o artista da música
void Music::setArtist(string artista){
		artist = &artista;
}

//Acessa o título da música
string * Music::getTitle(){
		return title;
}

//Acessa o artista da música
string * Music::getArtist(){
		return artist;
}

//Destrutor
Music::~Music(){
		//delete title, artist;
}	

//Cria uma nova música
Music newMusic(){
	Music nova_musica;
	string titulo, artista;

	fflush(stdin);
	cout << "Título da música: ";
	cin.ignore();
	getline(cin, titulo);

	fflush(stdin);
	cout << "Artista: ";
	cin.ignore();
	getline(cin, artista);

	nova_musica.setTitle(titulo);
	nova_musica.setArtist(artista);
	return nova_musica;
}