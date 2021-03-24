#ifndef _PLISTA_HPP_
#define _PLISTA_HPP_

#include "musica.hpp"
#include "lista.hpp"
#include "playlist.hpp"

struct Pnode{
	Playlist playlist;
	Pnode *next;
};

class Plist{
		Pnode *head, *tail;
	public:
		Plist();

		Pnode * getPlistHead();
		Pnode * getPlistTail();
		
		void displayPlist();

		bool searchPlaylist(Playlist p);

		void insertMusic(List l);
		void dropMusic();
		void orderMusic();
		void addPlaylist();
		void removePlaylist();

		~Plist();
};

#endif