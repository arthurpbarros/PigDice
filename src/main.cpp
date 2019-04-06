#include "game.h"
int main(){
	Game game;
	if(input_params(game)){ //Se os parametros do jogo foram dados
		while(flow(game)){ //Se alguém ganhou
			capture_events(&game);
		}
	}
}