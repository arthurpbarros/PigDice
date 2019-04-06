#ifndef IA_H
#define IA_H

#include "objects.h"

// retorna true se IA atingiu a meta de pontuação parcial,
// false caso contrário.
bool metaAtingida( Player * players, size_t n );

// meta de pontução parcial para IA atingir
size_t getMeta( Player * players, size_t n );

// obtém a classificação da IA no jogo
size_t getRank( Player * players, size_t n );

// copia os dados da IA para uma variável do tipo struct Ia
size_t getIdIA( Player * players, size_t n );


#endif
