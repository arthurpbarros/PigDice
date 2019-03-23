#include "../include/game.h"
int main(){
	Game game;
	int vez = 0;
	if(input_params(game)){ //Se os parametros do jogo foram dados
		while(flow(game)){ //Se alguém ganhou
			capture_events(&game);
			vez++;
		}
	}
}