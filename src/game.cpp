#include "../include/game.h"
bool flow(const Game & g){
	size_t i;
	for(i = 0; i < g.n;i++){
		if(g.players[i].total >= 100){
			cout << winner(&g.players[i]) << endl;
			return false;
		}
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
	if(p->is_ia){
		oss << "!!!!!!!!! O(A) COMPUTADOR(I.A.) ";
		oss << p->id;
		oss << " venceu o jogo !!!!!!!!!";
	}else{
		oss << "!!!!!!!!! O jogador ";
		oss << p->id;
		oss << " venceu o jogo !!!!!!!!!";
	}
	return oss.str();
}
void set_rand(){
	srand(time(NULL));
}
int roll (const Dice * dice){
	return rand() % dice->faces + 1;
}
bool input_params(Game & game){
	// set_rand(); //I1nicializa rand()
	cout << "Digite quantos jogadores físicos irão jogar: " << endl;
	int n,i;
	cin >> n;
	if(n >= 1 && n <= 4){
		//Definição dos parâmetros do jogo: 
		game.players = (Player*) malloc((n+1)*sizeof(Player)); //Aloca jogadores e I.A.
		game.n = n+1; //Jogadores + I.A.
		
		//Definição da I.A.
		set_rand();
		size_t id_ia = 1 + rand() % (n+1); //Escolhe um jogador para ser a I.A.
		game.players[id_ia-1].is_ia = 1; //Define o jogador como I.A.
		cout << "A I.A É O " << id_ia << " elemento" << endl;
		
		//Definição dos id
		for(i = 0; i < n+1;i++){
			game.players[i].id = i+1; //Ids começam a partir do 1.
		}
		return true;
	}else{
		return false;
	}
}