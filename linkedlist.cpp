#include "linkedlist.h"
#include "music.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

//Construtor
List::List(){
	head = NULL;
	tail = NULL;
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

//Inserindo um valor no nó cauda da lista (v0.2)
/*void List::setListTail(Node *t){
	tail = t;
}

//Inserindo um valor no nó seguinte da cauda da lista (v0.2)
void List::setListTailNext(Node *t){
	tail->next = t;
}

//Inserindo um valor no nó cabeça da lista (v0.2)
void List::setListHead(Node *t){
	head = t;
}*/

//Retorna o elemento que será transferido de uma lista para outra
Node * List::storeMusic(int &position){
	Node *temp = new Node;
	temp = head;

	for(int i = 1; i < position; i++){
		temp = temp->next;
	}
	return temp;
}
		
//Cria novos nós "simples" na lista, inserindo-os no final da lista
void List::createNode(Music m){
	Node *temp = new Node;
	temp->musica = &m;
	temp->next = NULL;

	if(head == NULL){
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else{
		tail->next = temp;
		tail = temp;
	}
}

//Cria nós que armazenam outras listas, inserindo-os no final da lista (v0.2)
void List::createNode(List &l){
	Node *temp = new Node;
	temp = l.getListHead();

	if(head == NULL){
		head = temp;
		tail = temp;
		temp = temp->next;
		while(temp != NULL){
			tail = temp;
			temp = temp->next;
		}
	}
	else{
		tail->next = temp
		while(temp->next != NULL){
			tail = temp;
			temp = temp->next;
		}
	}
}

//Lista todas as músicas cadastradas no sistema
void List::displayList(){
	Node *temp = head;
	Music *mus;
	string *title, *artist;
	//temp = getListHead();	
	while(temp != NULL){
		mus = temp->musica;
		title = mus->getTitle();
		artist = mus->getArtist();
		cout << title << ", de " << artist << endl;
		temp = temp->next;
	}
}

//Varre a lista de músicas cadastradas para saber se uma música já foi inserida ou não
Node * List::search(Node *head, Music m/*, int &pos*/){
	Node *temp = head;
	Music *mus;
	while(temp != NULL){
		mus = temp->musica;
		if((mus->getTitle() == m.getTitle()) && (mus->getArtist() == m.getArtist())){
			return temp;
		}
		else{
			temp = temp->next;
		}
	}
	return NULL;

//Insere um nó no começo da lista
void List::insertStart(Music m){
	Node *temp = new Node;
	temp->musica = &m;
	temp->next = head;
	head = temp;
}

//Insere um nó numa posição específica
void List::insertPosition(int &position, Music m){
	Node *pre = new Node;
	Node *curr = new Node;
	Node *temp = new Node;
	curr = head;
	for(int i = 1; i < position; i++){
		pre = curr;
		curr = curr->next;
	}
	temp->musica = &m;
	pre->next = temp;
	temp->next = curr;
}

//Deleta o primeiro nó da lista
void List::deleteStart(){
	Node *temp = new Node;
	temp = head;
	head = head->next;
	delete temp;
}

//Deleta o último nó da lista
void List::deleteEnd(){
	Node *curr = new Node;
	Node *pre = new Node;
	curr = head;
	while(curr->next != NULL){
		pre = curr;
		curr = curr->next;
	}
	tail = pre;
	pre->next = NULL;
	delete curr;
}

//Deleta o nó de uma posição específica
void List::deletePosition(int &position){
	Node *curr = new Node;
	Node *pre = new Node;
	curr = head;
	for(int i = 1; i < position; i++){
		pre = curr;
		curr = curr->next;
	}
	pre->next = curr->next;
}

//Deleta uma lista de nós passada (v0.2)
void List::deletePosition(List &l){
	Node *del = new Node;
	Node *head = new Node;
	Node *temp = new Node;
	Node *pre = new Node;

	del = head;
	temp = l.getListHead();
	if(temp == del){ //se o cabeça tiver que ser removido
		del = del->next;
		head = del;
	}
	if(temp != NULL){ //se a lista passada não for vazia
		while(del != NULL){
			while(temp != NULL){
				if(del->next == temp){
					pre = del;
					del = del->next;
					pre->next = del->next;
				}
				temp = temp->next;
			}
			del = del->next;
		}
	}
}

//Concatena duas listas (v0.2)
List List::operator+(List a, List b){
	List c;
	Node *temp = new Node;

	temp = a.getListHead();
	c->head = temp;
	while(temp != NULL){
		c->tail = temp;
		temp = temp->next;
	}

	temp = b.getListHead();
	c->tail->next = temp;
	while(temp != NULL){
		c->tail = temp;
		temp = temp->next;
	}
	return c;
}

//Extrai o último elemento de uma lista (v0.2)
Node * List::operator>>(Node *no, List l){
	Node *curr = new Node;
	Node *pre = new Node;
	curr = l.getListHead();

	if(l->head != NULL){
		no = l.getListTail();
		while(curr->next != NULL){
			pre = curr;
			curr = curr->next;
		}
		l->tail = pre;
		pre->next = NULL;
		delete curr;
	}
	else{
		no = NULL;
	}
	return no;
}

//Insere um nó como último elemento de uma lista (v0.2)
List List::operator<<(Node *no, List l){
	if(no == NULL){
		return NULL;
	}
	else{
		l->tail->next = no;
		l->tail = no;
		return l;
	}
}

//Destrutor
List::~List(){
}

//Adiciona uma nova música à lista
void appendMusic(List *lista, Music mus){
	//Node *head = new Node;
	Node *temp = new Node;

	//head = lista->getListHead();

	temp = lista->search(lista->getListHead(), mus);
	if(temp == NULL){
		lista->createNode(mus);
	}
	else{
		cout << "Música já cadastrada.\n\n";
	}
}

//Exclui uma música da lista
void dropMusic(List *lista){
	int posicao;

	cout << "\n\n_______________________________________\n\n";
	lista->displayList();
	cout << "\n\n_______________________________________\n\n";
	cout << "Digite a posição da música que você quer remover: ";
	cin >> posicao;

	if(posicao == 1){
		lista->deleteStart();
	}
	else{
		lista->deletePosition(posicao);
	}
}

//Lista as músicas cadastradas
void listMusic(List *lista){
	lista->displayList();
}