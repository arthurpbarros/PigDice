#include "../include/game.h"
bool flow(const Game & g){
	size_t i;
	for(i = 0; i < g.n;i++){
		if(g.players[i].total >= 100){
			cout << winner(&g.players[i]) << endl;
			return false;
		}
	}
	//Pergunta se ia ganha
	if (g.ia.total >= 100){
		cout << winner(&g.ia) << endl;
		return false;
	} 
	return true;

}
void capture_events(Game * game){
	string res;
	cout << "Digite algo para SEGURAR o dado ou Tecle [ENTER] para ROLAR o dado" << endl;
	cin.ignore();
	getline(cin,res);
	if(res == ""){
		cout << "rolar" << endl;
	}else{
		cout << "segurar" << endl;
	}
}
string winner(const Player * p){
	std::ostringstream oss;
	oss << "!!!!!!!!! O jogador ";
	oss << p->id;
	oss << " venceu o jogo !!!!!!!!!";
	return oss.str();
}
void set_rand(){
	srand(time(NULL));
}
int roll (const Dice * dice){
	return rand() % dice->faces + 1;
}
bool input_params(Game & game){
	set_rand();
	cout << "Digite quantos jogadores físicos irão jogar: " << endl;
	int n,i;
	cin >> n;
	if(n > 0 && n <= 5){
		game.players = (Player*) malloc(n*sizeof(Player));
		game.n = n;
		game.ia.id = n+1;
		for(i = 0; i < n;i++){
			game.players[i].id = i+1;
		}
		return true;
	}else{
		return false;
	}
}