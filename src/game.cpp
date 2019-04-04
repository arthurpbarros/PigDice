#include "../include/game.h"
bool flow(const Game & g){
	size_t i;
	for(i = 0; i < g.n;i++){
		if(g.players[i].total >= 100){
			winner(&g.players[i]);
			return false;
		}
	}
	return true;
}
void hold(Player *p){
	p->total += p->partial;
}
void play(Game * game){
	int face = roll(&game->dice);
	size_t * score_partial = &game->players[game->vez].partial;
	if(face == 1){
		*score_partial += 0; //Zera a pontuação parcial
		show_turn(game);
	}else{
		*score_partial += face;
	}
}
void capture_events(Game * game){
	string res;
	cout << "Digite algo para SEGURAR o dado ou Tecle [ENTER] para ROLAR o dado" << endl;
	cin.ignore(); // CHAMAR FUNÇÃO "LIMPAR BUFFER CIN"
	getline(cin,res);
	int vez = game->vez % game->n;
	/* 
	* LUCAS, AQUI SE COLOCA A ESCOLHA DA I.A
	* use game->players[game->vez % game->n].is_ia para saber se o player atual é I.A.
	*/
	if(res == ""){
		//cout << "rolar" << endl;
		play(game);
	}else{
		//cout << "segurar" << endl;
		hold(&game->players[vez]);
		show_turn(game);
	}
}
void winner(const Player * p){
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
	cout << oss.str() << endl;
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
void show_turn(Game * game){
	game->vez++;
	std::ostringstream oss;
	bool player_is_ia = game->players[game->vez % game->n].is_ia;
	oss << "!!!!!!!!! É A VEZ D";
	if(player_is_ia){
		oss << "A I.A !!!!!!!!!";
	}else{
		oss << "O JOGADOR !!!!!!!!";
		oss << game->players[game->vez % game->n].id;
	}
	cout << oss.str() << endl;
	//chamar funcao show_score(game)
}
