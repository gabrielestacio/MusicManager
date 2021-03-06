#ifndef __LINKEDPLAYLIST_H_
#define __LINKEDPLAYLIST_H_

#include "playlist.h"

using namespace std;

struct Pnode{
		Playlist *playlist;
		Pnode *next;
};

class ListPlaylist{
		Pnode *phead, *ptail;
	public:
		ListPlaylist();
		Pnode * getPhead();
		Pnode * getPtail();
		void createPnode(Playlist p);
		Pnode * search(Pnode *cabeca, Playlist p);
		void deletePstart();
		void deletePposition(int &position);
		void displayListPlaylist();
		~ListPlaylist();
};

void appendPlaylist(ListPlaylist *playlists, Playlist p);
void dropPlaylist(ListPlaylist *playlists);
void listPlaylist(ListPlaylist *playlists);

#endif