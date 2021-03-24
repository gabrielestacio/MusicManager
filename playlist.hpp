#ifndef _PLAYLIST_HPP_
#define _PLAYLIST_HPP_

#include "musica.hpp"
#include "lista.hpp"

class Playlist{
		string name;
		Node *playing, *head, *tail;
	public:
		Playlist();
		Playlist(const Playlist &p);

		void setPlaylistName(string nome);
		
		string getPlaylistName();
		Node * getPlaying();
		Node * getPlaylistHead();
		Node * getPlaylistTail();
		
		//tem que ir pra lista de playlists
		void newPlaylist();

		void displayPlaylist();

		bool searchPMusic(Music m);

		void addMusic(List l);
		void addMusic(Playlist &p);
		void removeMusic();
		void removeMusic(Playlist &p);
		void moveMusic();

		Node * playNext();

		~Playlist();
};

#endif