#include "game.h"
bool flow(const Game & g){
	size_t i;
	for(i = 0; i < g.n;i++){
		if(g.players[i].total >= 100){
			winner(&g.players[i]);
			free (g.players);
			return false;
		}
	}
	return true;
}
void hold(Player *p){
	p->total += p->partial;
	p->partial = 0;
	if(p->is_ia){
		cout << "------I.A segurou o Dado------" << endl;
	}else{
		cout << setw(30) << setfill('-') << "------O Jogador " << p->id << " segurou o Dado------" << endl;
	}
}
void play(Game * game){
	int face = roll(&game->dice);
	cout << ">>>>>";
	if(game->players[game->vez].is_ia){
		cout << " I.A rolou o dado e obteve " << face << "\n";
	}else{
		cout << " O Jogador " << game->players[game->vez].id << " rolou o dado e obteve " << face << "\n";
	}
	if(face == 1){
		game->players[game->vez].partial = 0; //Zera a pontuação parcial
		show_turn(game);
	}else{
		game->players[game->vez].partial += face;
	}
	cout << ">>>>> PONTUAÇÃO PARCIAL = " << game->players[game->vez].partial << endl;
}
void capture_events(Game * game) {
    size_t id_ia = getIdIA( game->players, game->n );
    if ( game->vez == id_ia ){
        bool meta_alcancada = metaAtingida( game->players, game->n );
        if ( !meta_alcancada ){
            play(game);
        } // end inner if
        else{
            hold(&game->players[id_ia]);
    		show_turn(game);
        } // end else
    } // end outer if
    else{
      	string res;
        cout << "Jogador " << game->players[game->vez].id << "," << endl;
        cout << "Digite 'a' para SEGURAR o dado ou Tecle ";
		cout << "outro caracter para ROLAR o dado: " << endl;
    	getline(cin,res);
        if(res.compare("a") != 0){
    		//cout << "rolar" << endl;
    		play(game);
    	}else{
    		//cout << "segurar" << endl;
    		hold(&game->players[game->vez]);
    		show_turn(game);
    	}
    } // end else
    show_score(game);
}
void winner(const Player * p){
	cout << setw(30) << setfill('!');
	if(p->is_ia){
		cout << " O(A) COMPUTADOR(I.A.) VENCEU O JOGO " << endl;
	}else{
		cout << " O(A) JOGADOR(A) ";
		cout << p->id;
		cout << " VENCEU O JOGO " << endl;
	}
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
		cout << "************************" << endl;
		cout << "A I.A É O " << id_ia << " jogador" << endl;
		cout << "************************" << endl;
		//Definição dos id
		for(i = 0; i < n+1;i++){
			game.players[i].id = i+1; //Ids começam a partir do 1.
		}
		cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		return true;
	}else{
		cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		return false;
	}
}
void show_turn(Game * game){
	game->vez++;
	if(game->vez == game->n){
		game->vez = 0;
	}
	bool player_is_ia = game->players[game->vez % game->n].is_ia;
	cout << setw(30) << setfill('-') << "";
	cout << "-------------> É A VEZ D";
	if(player_is_ia){
		cout << "A I.A ";
	}else{
		cout << "O JOGADOR ";
		cout << game->players[game->vez % game->n].id;
	}
	cout << endl;
}
void show_score(Game * game){
	cout << setw(30) << setfill('-') << "" << endl;
	cout << setw(30) << setfill(' ') << " JOGADOR         | PONTOS " << endl;
	cout << setw(30) << setfill('-') << "" << endl;
	size_t i;
	for (i = 0; i < game->n;i++){
		if(game->players[i].is_ia){
			cout << " IA                  | " << game->players[i].total << endl;
		}else{
			cout << " Jogador " << game->players[i].id << "           | " << game->players[i].total << endl;
		}
	}
	cout << setw(30) << setfill('-') << "" << endl;
}
