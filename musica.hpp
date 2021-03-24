#ifndef _MUSIC_HPP_
#define _MUSIC_HPP_

#include <string>

using namespace std;

class Music
{
	string title, artist;
public:
	Music();
	void setTitle(string &titulo);
	void setArtist(string &artista);
	string getTitle();
	string getArtist();
	void newMusic();
	~Music();
};


#endif