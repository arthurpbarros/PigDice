#ifndef GAME_h
#define GAME_H
#include "objects.h"
#include <iostream> //cin,cout
#include <stdlib.h> //rand
#include <time.h> //time
#include <sstream>//osstream
#include <string>
using namespace std;
/*!	Brief Verifica se algum jogador alcançou a pontuação máxima
* @return true, caso algum jogador venceu o jogo e false caso contrário
*/ 
bool flow(const Game & g);
/*!	Brief Captura a escolhar de um jogador(ou ia), um de cada vez
*
*/
void capture_events(Game * game);
/*!	Brief Informa qual usuário venceu o jogo
* @return mensagem sobre o vencedor.
*/ 
string winner(const Player * p);
/*!	Brief Fornece semente a função rand()
*/ 
void set_rand(); 
/*! Brief Rola o dado
* @param Endereço do struct dado
* @return Face obtida aṕos o lançamento
*/
int roll (const Dice * dice);
/*! Brief Fornece parâmetros iniciais para o jogo, como quantidade de jogadores e pontuação máxima 
* @return Retorna se os parâmetros são válidos
*/
bool input_params(Game & game);
#endif 