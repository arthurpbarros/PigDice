#ifndef
#define PLAYER_H
#include <iostream>
#include <string>
	typedef struct _player{
		int parcial_score = 0, total_score = 0;
	} Player;

	void play(Player * player);

	void skip(Player * player);

	void capture_events(Player * player);
#endif