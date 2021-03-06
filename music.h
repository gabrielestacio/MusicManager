#ifndef _MUSIC_H_
#define _MUSIC_H_

#include <string>

using namespace std;

class Music
{
	string *title, *artist;
public:
	Music();
	void setTitle(string titulo);
	void setArtist(string artista);
	string * getTitle();
	string * getArtist();
	~Music();	
};

Music newMusic();

#endif