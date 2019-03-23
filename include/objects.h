#ifndef OBJECTS_H
#define OBJECTS_H
#include <cstdlib>
struct Dice
{
   size_t faces = 6;
}; // end struct Dice

struct Player
{
   size_t id;
   size_t partial = 0;
   size_t total   = 0;
   size_t is_ia = 0; //Inicialmente, todos os jogadores são físicos. Mas no método input_params() a I.A. é escolhida
}; // end struct Player
struct Game
{
	Dice dice;
	Player * players;
	size_t n;
	size_t target_score;
	// colocar size_t vez = 0 aqui? ao invés do main();
	// Player ia
};
#endif