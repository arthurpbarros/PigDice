#include "../include/dice.h"
void set_rand(){
	srand(time(NULL));
}
int roll (int faces){
	return rand() % faces + 1;
}