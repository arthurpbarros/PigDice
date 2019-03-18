#include "../include/player.h"
#include "../include/dice.h"
void play(Player * player){
	roll(); //Rolar dado
}
void skip(Player * player){
	player->total_score += parcial_score;
}
void capture_events(Player * player){
	string res;
	cout << "Type anything for roll the dice or type enter for hold" << endl;
	getline(cin, res);
	if(res != ""){
		play(player);
	}else{
		skip(player);
	}
}