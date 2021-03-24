#include "playlist.hpp"
#include "lista.hpp"
#include "musica.hpp"
#include <iostream>
#include <string>

using namespace std;

//Construtor
Playlist::Playlist(){
	playing = nullptr;
	head = nullptr;
	tail = nullptr;
}

//Construtor cópia (v0.2)
Playlist::Playlist(const Playlist &p){
	name = p.name;
	playing = p.playing;
	head = p.head;
	tail = p.tail;
}

//Insere o nome na playlist
void Playlist::setPlaylistName(string nome){
	this->name = nome;
}

//Retorna o nome da playlist
string Playlist::getPlaylistName(){
	return name;
}

//Retorna a música que está sendo tocada
Node * Playlist::getPlaying(){
	return playing;
}

//Retorna a primeira música da playlist
Node * Playlist::getPlaylistHead(){
	return head;
}

//Retorna a última música da playlist
Node * Playlist::getPlaylistTail(){
	return tail;
}

//Cria uma nova playlist
void Playlist::newPlaylist(){
	string nome;

	system("clear");

	cout << (">>>>>>>>>>>>>>>>>>>>>>>>") << endl;
	cout << "M U S I C   M A N A G E R" << endl;
	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<\n" << endl;

	cout << "Nome da playlist: ";
	cin.ignore();
	getline(cin, nome);

	setPlaylistName(nome);
}

//Imprime a playlist na tela
void Playlist::displayPlaylist(){
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

//Verifica se uma música já está cadastrada na playlist
bool Playlist::searchPMusic(Music m){
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

//Adicionando uma música na playlist
void Playlist::addMusic(List l){
	Node *temp = new Node;
	List lista = l;
	bool repetida = false;
	int posicao;

	system("clear");

	lista.displayList();
	cout << "_______________________________________\n" << endl;
	
	//Buscando a música que será adicionada
	cout << "Posição da música que será adicionada: ";
	cin >> posicao;

	//Até aqui funciona
	//	cout << "DEBUG" << endl;
	//	getchar();

	if(posicao == 0){
		return;
	}
	else{
		temp = lista.storeMusic(posicao);
	}

	if(temp == nullptr){
		cout << "_______________________________________\n" << endl;
		cout << "Nenhuma música cadastrada no sistema ou posição inválida." << endl;
		return;
	}
	else{
		if(head == nullptr){
			head = temp;
			tail = temp;
			temp = nullptr;
		}
		else{
			//Verificando se a música escolhida já está na playlist
			repetida = searchPMusic(temp->musica);
			if(repetida == false){
				tail->next = temp;
				tail = temp;			
			}
		}
	}

	
	//Caso o temp tenha recebido null quando a lista era vazia
	if(temp == nullptr){
		temp = tail;
	}

	cout << "_______________________________________\n" << endl;
	if((tail == temp) && (repetida == false)){
		cout << "Música adicionada com sucesso :D" << endl;
	}
	else{
		cout << "Música já cadastrada na playlist :/" << endl;
	}

	//cout << tail->musica.getTitle() << " é igual a " << temp->musica.getTitle() << "?" << endl;
}

//Adiciona todas as músicas de uma playlist dada na que está sendo criada (v0.2)
void Playlist::addMusic(Playlist &p){
	Node *temp = new Node;
	Music m;
	bool repetida = false;
	
	temp = p.getPlaylistHead();

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
			m = temp->musica;
			repetida = searchPMusic(m);
			if(repetida == false){
				tail->next = temp;
				tail = temp;
				temp = temp->next;
			}
			else{
				temp = temp->next;
			}
		}
	}
}

//Removendo uma música da playlist
void Playlist::removeMusic(){
	int posicao;

	system("clear");

	displayPlaylist();
	cout << "_______________________________________\n" << endl;
	cout << "Posição da música que será removida: ";
	cin >> posicao;

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

//Exclui todas as músicas de uma playlist dada na que está sendo criada (v0.2)
void Playlist::removeMusic(Playlist &p){
	Node *temp = new Node;

	temp = p.getPlaylistHead();
	if(head != nullptr){
		while(temp != nullptr){
			if(searchPMusic(temp->musica) == true){
				if(temp == head){
					temp = head;
					head = head->next;
					delete temp;
				}
				else{
					Node *pre = p.getPlaylistHead();
					Node *curr = temp;
					while(pre->next != curr){
						pre = pre->next;
					}
					pre->next = curr->next;
				}

			}
		}
	}


}

//Movendo uma música dentro da playlist
void Playlist::moveMusic(){
	Node *store = new Node;
	int pinicial, pfinal;

	system("clear");

	displayPlaylist();
	cout << "_______________________________________\n" << endl;
	cout << "Posição da música que será movida: ";
	cin >> pinicial;
	cout << "\nPosição onde a música será inserida: ";
	cin >> pfinal;

	//Buscando o node que será movido
	Node *temp = head;
	Node *pre = new Node;
	for(int i = 1; i < pinicial; i++){
		pre = temp;
		temp = temp->next;
	}

	//Armazenando o node antes de movê-lo
	store->musica = temp->musica;
	store->next = nullptr;

	//Excluindo o node da posição antiga
	pre->next = temp->next;

	//Inserindo o node na nova posição
	temp = head;
	for(int i = 1; i < pfinal; i++){
		pre = temp;
		temp = temp->next;
	}
	pre->next = store;
	store->next = temp;
}

//Retornando a próxima música
Node * Playlist::playNext(){
	if(playing == nullptr){
		playing = head;
		return playing;
	}
	else{
		if (playing->next != nullptr){
			playing = playing->next;
			return playing;
		}
		else{
			return nullptr;
		}
	}
}

//Destrutor
Playlist::~Playlist(){
	Node *temp = new Node;

	if(head != nullptr){
		temp = head;
		while(temp != nullptr){
			delete temp;
			temp = temp->next;
		}
	}
}