||| Aluno: Gabriel Estácio de Souza Passos
||| Turma: T03
||| Matrícula: 20190038990

||| Instruções de compilação e execução:
Inicialmente, eu usei a seguinte linha de compilação:

--> g++ -o main -Wall -ansi -pedantic -O0 -g main.cpp music.cpp playlist.cpp linkedplaylist.cpp linkedlist.cpp

Depois, construí o makefile usando estes comandos:

--> all: main

--> main: main.o music.o linkedlist.o playlist.o linkedplaylist.o
		g++ -o main main.o music.o linkedlist.o playlist.o linkedplaylist.o  

--> main.o: main.cpp music.h linkedlist.h playlist.h linkedplaylist.h
		g++ -o main.o main.cpp -c -W -Wall -ansi -pedantic -O0 -g

--> music.o: music.cpp music.h
		g++ -o music.o music.cpp -c -W -Wall -ansi -pedantic -O0 -g

--> linkedlist.o: linkedlist.cpp linkedlist.h
		g++ -o linkedlist.o linkedlist.cpp -c -W -Wall -ansi -pedantic -O0 -g

--> playlist.o: playlist.cpp playlist.h
		g++ -o playlist.o playlist.cpp -c -W -Wall -ansi -pedantic -O0 -g

--> linkedplaylist.o: linkedplaylist.cpp linkedplaylist.h
		g++ -o linkedplaylist.o linkedplaylist.cpp -c -W -Wall -ansi -pedantic -O0 -g	

--> clean:
		rm -rf *.o *~ main

Para a execução, a partir do .exe criado, simplesmente é necessário usar:

--> ./main

||| Roteiro:
A tela inicial do  programa oferece três opções: gerenciar músicas, gerenciar playlists e sair do programa.

Se o  usuário escolher sair do programa, ele vai ser redirecionado a uma tela onde ele deve confirmar se quer sair do programa. Caso ele responda sim (usando "S" ou "s"), o programa termina. Se ele responde com "N" ou "n", o programa voltará à tela inicial. Se ele responder com qualquer outra informação, o programa irá ignorar a entrada e refazer a pergunta de confirmação.

Se o usuário optar por gerenciar as playlists, ele tem 6 opções:
	1) criar uma nova playlist:
		Será redirecionado para uma página onde deve inserir o nome da playlist que será criada.
	2) excluir uma playlist:
		Será redirecionado para uma página onde deve inserir o nome da playlist que será excluída.
	3) listar as playlists existentes:
		Será redirecionado para uma página onde aparece a listagem de todas as playlists existentes.
	4) adicionar músicas a uma playlist existente:
		Será redirecionado para uma página onde deve escolher, da lista de músicas cadastradas no sistema, qual música ele quer inserir na playlist.
	5) remover músicas de uma playlist existente:
		Será redirecionado para uma página onde deve escolher, da lista de músicas cadastradas na playlist, qual música ele quer remover.
	6) mover músicas dentro de uma playlist existente:
		Será redirecionado para uma página onde deve escolher a música que quer mover e pra qual posição quer movê-la.

Se o usuário optar por gerenciar as músicas, ele tem 3 opções:
	1) adicionar novas músicas ao sistema:
		Será redirecionado para uma página onde deve inserir o título e o artista da música que será inserida.
	2) remover uma música do sistema:
		Será redirecionado para uma página onde deve inserir o título e o artista da música que será removida.
	3) listar músicas cadastradas no sistema:
			Será redirecionado para uma página onde estarão listadas todas as músicas cadastradas no sistema.

Tanto para adicionar óu remover músicas, quanto playlists, o programa verifica se essa música/playlist já está cadastrada (no caso da adição) ou se ela não existe (no caso da remoção).

Um exemplo de execução é:
--> ./main

Olá! Seja bem-vindo! O que você deseja fazer?
Digite 1 se você quer acessar as músicas.
Digite 2 se você quer acessar as playlists.
Digite qualquer outro número para sair do sistema.

--> 1

O que você quer fazer?
Digite 1 para adicionar músicas no sistema.
Digite 2 para remover músicas do sistema.
Digite 3 para listar as músicas cadastradas.
Digite qualquer outro número para voltar para a tela inicial.

--> 1

_______________________________________

Título da música: Corcovado
Artista: Tom Jobim

Quer continuar gerenciando músicas? Escolha o que fazer! Lembre-se:
Digite 1 para adicionar músicas no sistema.
Digite 2 para remover músicas do sistema.
Digite 3 para listar as músicas cadastradas.
Digite qualquer outro número para voltar para a tela inicial.

--> 3

Corcovado, de Tom Jobim

Quer continuar gerenciando músicas? Escolha o que fazer! Lembre-se:
Digite 1 para adicionar músicas no sistema.
Digite 2 para remover músicas do sistema.
Digite 3 para listar as músicas cadastradas.
Digite qualquer outro número para voltar para a tela inicial.

--> 0

Olá! Seja bem-vindo! O que você deseja fazer?
Digite 1 se você quer acessar as músicas.
Digite 2 se você quer acessar as playlists.
Digite qualquer outro número para sair do sistema.

--> 7

Poxa, você já está indo? :(
Se você tem certeza que quer sair, digite S. Se decidiu ficar mais um pouco, digite N.

--> A

Poxa, você já está indo? :(
Se você tem certeza que quer sair, digite S. Se decidiu ficar mais um pouco, digite N.

--> S

Até a próxima! :D

||| Limitações:
O exemplo acima seria o ideal, o esperado, mas o programa apresentou um problema e não imprime a listagem, nem das músicas, nem das listas/playlists. Nenhum módulo de listagem imprimiu corretamente. As funções que deveriam fazer essas listagem são:
	em linkedlist.cpp: displayList() e listMusic();
	em playlist.cpp: displayPlaylist();
	em linkedplaylist.cpp: displayListPlaylist() e listPlaylist().

||| Dificuldades:
Tive dificuldade (que, na verdade, é algo que trago de ITP) de saber exatamente quando usar ponteiros. Eu tenho uma grande dificuldade de entender o conceito, a aplicação e a utilidade dos ponteiros (quando e porque eu preciso usar).