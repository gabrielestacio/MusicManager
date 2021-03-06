#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include "music.h"

struct Node{
		Music *musica;
		Node *next;
};

class List{
		Node *head, *tail;
	public:
		List();
		List(const List &l);
		
		Node * getListHead();
		Node * getListTail();
		//void setListTail(Node *t);
		//void setListTailNext(Node *t);
		//void setListHead(Node *t);

		Node * storeMusic(int &position);
		
		void createNode(Music m);
		void createNode(List &l);
		
		void displayList();
		
		Node * search(Node *head, Music m/*, int &pos*/);
		
		void insertStart(Music m);
		void insertPosition(int &position, Music m);
		
		void deleteStart();
		void deleteEnd();
		void deletePosition(int &position);
		void deletePosition(List &l);
		
		List operator+(List a, List b);
		Node * operator>>(Node *no, List l);
		List operator<<(Node *no, List l);

		~List();
};

void appendMusic(List *lista, Music mus);
void dropMusic(List *lista);
void listMusic(List *lista);

#endif