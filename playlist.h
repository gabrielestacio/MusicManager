#ifndef _PLAYLIST_H_
#define _PLAYLIST_H_

#include "linkedlist.h"
#include <string>

using namespace std;

class Playlist{
		string *playlist;
		Node *playing, *head, *tail;
	public:
		Playlist();
		Playlist(const Playlist &p);
		
		void setPlaylistName(string nome);
		string * getPlaylistName();
		Node * getPlaying();
		Node * getPlaylistHead();
		Node * getPlaylistTail();
		
		Node * storemusic(int &position);
		
		void addMusic(Node *temp);
		void addMusic(Playlist &p);
		
		void dropMusic(int &position);
		int dropMusic(Playlist &p);
		
		void moveMusic(Playlist *playlist, int &ini_position, int &end_position);
		
		Node * playNext();
		
		void displayPlaylist();

		Playlist operator+(Playlist p1, Playlist p2);
		Playlist operator+(Playlist p, Music m);
		Playlist operator-(Playlist p1, Playlist p2);
		Playlist operator-(Playlist p, Music m);
		void operator>>(Playlist &p, Music &m);
		void operator<<(Playlist &p, Music m);

		~Playlist();
};

Playlist newPlaylist();
void insertPlaylist(Playlist *p, List *l);
void removePlaylist(Playlist *p);
void movePlaylist(Playlist *p);

#endif