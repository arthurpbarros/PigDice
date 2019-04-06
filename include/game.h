#ifndef GAME_H
#define GAME_H
#include "ia.h"
#include "objects.h"
#include <limits> //ignore
#include <iostream> //cin,cout
#include <stdlib.h> //rand
#include <cstdlib>
#include <time.h> //time
#include <sstream>//osstream
#include <string>
using namespace std;
/*!	Brief Verifica se algum jogador alcançou a pontuação máxima
* @return true, caso algum jogador venceu o jogo e false caso contrário
*/ 
bool flow(const Game & g);
/*! Brief Segura o dado, isto é, credita a pontuação parcial a pontuação total
* @param Jogador que escolheu a opção segurar
*/
void hold(Player *p);
/*! Brief Rola o dado, adicionando o valor da face a pontuação parcial.
* @param Jogador que escolheu a opção rolar
*/
void play(Game * game);
/*!	Brief Captura a escolhar de um jogador(ou ia), um de cada vez
*
*/
void capture_events(Game * game);
/*!	Brief Informa qual usuário venceu o jogo
* @param Jogador atual
*/ 
void winner(const Player * p);
/*!	Brief Fornece semente a função rand()
*/ 
void set_rand(); 
/*! Brief Rola o dado
* @param Endereço do struct dado
* @return Face obtida aṕos o lançamento
*/
int roll (const Dice * dice);
/*! Brief Fornece parâmetros iniciais para o jogo, como quantidade de jogadores e pontuação máxima 
* @param Dado do jogo
* @return Retorna se os parâmetros são válidos
*/
bool input_params(Game & game);
/*! Brief Passa a vez e exibe qual jogador irá jogar 
* @param struct Game 
*/
void show_turn(Game * game);
/*! Brief Exibe a pontuação dos jogadores 
* @param stuct Game
*/
void show_score(Game * game);
#endif 