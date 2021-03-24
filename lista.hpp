#ifndef _LISTA_HPP_
#define _LISTA_HPP_

#include "musica.hpp"

struct Node{
		Music musica;
		Node *next;
};

class List{
		Node *head, *tail;
	public:
		List();
		List(const List &l);
		Node * getListHead();
		Node * getListTail();
		void displayList();
		bool searchMusic(Music m);
		Node * storeMusic(int pos);
		void addMusic();
		void addMusic(List &l);
		void removeFromPlaylist(Plist &lp, int pos);
		void removeMusic(Plist &lp);
		void removeMusic(Plist &lp, List &l);
		void printMusic();
		~List();
};


#endif