
all: main

main: main.o music.o linkedlist.o playlist.o linkedplaylist.o
	g++ -o main main.o music.o linkedlist.o playlist.o linkedplaylist.o  

main.o: main.cpp music.h linkedlist.h playlist.h linkedplaylist.h
	g++ -o main.o main.cpp -W -Wall -ansi -pedantic -O0 -fsanitize=address -g

music.o: music.cpp music.h
	g++ -o music.o music.cpp -W -Wall -ansi -pedantic -O0 -fsanitize=address -g

linkedlist.o: linkedlist.cpp linkedlist.h
	g++ -o linkedlist.o linkedlist.cpp -W -Wall -ansi -pedantic -O0 -fsanitize=address -g

playlist.o: playlist.cpp playlist.h
	g++ -o playlist.o playlist.cpp -W -Wall -ansi -pedantic -O0 -fsanitize=address -g

linkedplaylist.o: linkedplaylist.cpp linkedplaylist.h
	g++ -o linkedplaylist.o linkedplaylist.cpp -W -Wall -ansi -pedantic -O0 -fsanitize=address -g	

clean:
	rm -rf *.o *~ main