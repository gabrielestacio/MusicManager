#include "musica.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

//Construtor
Music::Music(){
}

//Insere o título da música
void Music::setTitle(string &titulo){
	this->title = titulo;
}

//Insere o artista da música
void Music::setArtist(string &artista){
	this->artist = artista;
}

//Acessa o título da música
string Music::getTitle(){
	return title;
}

//Acessa o artista da música
string Music::getArtist(){
	return artist;
}

//Cria uma nova música
void Music::newMusic(){
	string titulo = "No Title", artista = "Unknown";

	cout << "Título: ";
	cin.ignore();
	getline(cin, titulo);

	cout << "Artista: ";
	cin.ignore(0);
	getline(cin, artista);

	setTitle(titulo);
	setArtist(artista);
}

//Destrutor
Music::~Music(){
}	
