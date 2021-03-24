#include <iostream>
#include <string>
#include <cstdlib> 
#include "telas.hpp" //Biblioteca com as funções das telas do sistema
#include "musica.hpp" //Biblioteca com as funções referentes ao tipo Music
#include "lista.hpp" //Biblioteca com as funções referentes ao tipo List
#include "playlist.hpp" //Biblioteca com as funções referentes ao tipo Playlist
#include "plista.hpp" //Biblioteca com as funções referentes ao tipo Plist

using namespace std;

int main(int argc, char const *argv[]){
	int start = 0, quit = 0; //start define pra qual área do sistema o usuário vai; quit define se o sistema vai encerrar ou não.
	int startMus = 0, quitMus = 0; //tem as mesmas funções das variáveis acima, só que dentro do módulo de músicas.
	int startPlaylist = 0, quitPlaylist = 0; //tem as mesmas funções das variáveis acima, só que dentro do módulo de playlists.
	List lista; //Lista de músicas cadastradas no sistema
	Plist playlists;//Lista de playlists cadastradas no sistema

	do{
		//Iniciando o sistema
		start = telaInicial();

		//Gerenciamento de músicas
		if(start == 1){
			do{
				startMus = telaInicialMus();

				switch(startMus){
					case 1: //Adicionar uma música
						lista.addMusic(); //addMusic é uma função da biblioteca "lista".
					//	cout << "Pressione ENTER para continuar.\n" << endl;
					//	getchar();
						quitMus = telaSaidaMus();
						//Caso o usuário digite um valor diferente de S/s ou N/n em telaSaidaMus(), entra no loop até ele digitar um dos valores válidos;
						while(quitMus == 2){
							quitMus = telaSaidaMus();
						}
						break;

					case 2: //Remover uma música
						lista.removeMusic(playlists); //removeMusic é uma função da biblioteca "lista".
						quitMus = telaSaidaMus();
						//Caso o usuário digite um valor diferente de S/s ou N/n em telaSaidaMus(), entra no loop até ele digitar um dos valores válidos;
						while(quitMus == 2){
							quitMus = telaSaidaMus();
						}
						break;

					case 3: //Listar as músicas cadastradas no sistema.
						lista.displayList(); //displayList é uma função da biblioteca "lista".
					//	cout << "Pressione ENTER para continuar.\n" << endl;
					//	getchar();
						quitMus = telaSaidaMus();
						//Caso o usuário digite um valor diferente de S/s ou N/n em telaSaidaMus(), entra no loop até ele digitar um dos valores válidos;
						while(quitMus == 2){
							quitMus = telaSaidaMus();
						}
						break;

					default:
						quitMus = 0;
						break;
				}
			}while(quitMus == 1);
		}
		else if(start == 2){
			do{
				startPlaylist = telaInicialPlaylist();

				switch(startPlaylist){
					case 1: //Criar uma playlist
						playlists.addPlaylist();
						quitPlaylist = telaSaidaPlaylist();
						//Caso o usuário digite um valor diferente de S/s ou N/n em telaSaidaPlaylist(), entra no loop até ele digitar um dos valores válidos;
						while(quitPlaylist == 2){
							quitPlaylist = telaSaidaPlaylist();
						}
						break;

					case 2: //Adicionar uma música à playlist
						playlists.insertMusic(lista);
						quitPlaylist = telaSaidaPlaylist();
						//Caso o usuário digite um valor diferente de S/s ou N/n em telaSaidaPlaylist(), entra no loop até ele digitar um dos valores válidos;
						while(quitPlaylist == 2){
							quitPlaylist = telaSaidaPlaylist();
						}
						break;

					case 3: //Removendo uma música da playlist
						playlists.dropMusic();
						quitPlaylist = telaSaidaPlaylist();
						//Caso o usuário digite um valor diferente de S/s ou N/n em telaSaidaPlaylist(), entra no loop até ele digitar um dos valores válidos;
						while(quitPlaylist == 2){
							quitPlaylist = telaSaidaPlaylist();
						}
						break;

					case 4: //Movendo uma música dentro da playlist
						playlists.orderMusic();
						quitPlaylist = telaSaidaPlaylist();
						//Caso o usuário digite um valor diferente de S/s ou N/n em telaSaidaPlaylist(), entra no loop até ele digitar um dos valores válidos;
						while(quitPlaylist == 2){
							quitPlaylist = telaSaidaPlaylist();
						}
						break;

					case 5: //Excluindo uma playlist
						playlists.removePlaylist();
						quitPlaylist = telaSaidaPlaylist();
						//Caso o usuário digite um valor diferente de S/s ou N/n em telaSaidaPlaylist(), entra no loop até ele digitar um dos valores válidos;
						while(quitPlaylist == 2){
							quitPlaylist = telaSaidaPlaylist();
						}
						break;

					case 6: //Listando as playlists cadastradas
						playlists.displayPlist();
						quitPlaylist = telaSaidaPlaylist();
						//Caso o usuário digite um valor diferente de S/s ou N/n em telaSaidaPlaylist(), entra no loop até ele digitar um dos valores válidos;
						while(quitPlaylist == 2){
							quitPlaylist = telaSaidaPlaylist();
						}
						break;

					default:
						quitPlaylist = 0;
						break;
				}
			}while(quitPlaylist == 1);
		}
		else{
			//Saindo do sistema
			quit = telaSaida();

			//Entrada Inválida
			if(quit == 2){
				while(quit == 2){
					quit = telaSaida();
				}
			}
			//Saindo do sistema
			else if(quit == 1){
				system("clear");

				cout << (">>>>>>>>>>>>>>>>>>>>>>>>>") << endl;
				cout << "M U S I C   M A N A G E R" << endl;
				cout << "<<<<<<<<<<<<<<<<<<<<<<<<<\n" << endl;

				cout << "Obrigado por usar o MusicManager!" << endl;
				cout << "Até a próxima! :D\n\n" << endl;
			}
			//Se quit = 0, o programa vai simplesmente se manter dentro do do/while.
		}
	}while(quit != 1); //Enquanto o usuário não digitar S na tela de saída, o sistema vai continuar ativo.
	return 0;
}