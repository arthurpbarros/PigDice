#include "../include/ia.h"

bool metaAtingida( Player * players, size_t n )
{
    size_t id_ia = getIdIA( players, n );
    size_t meta = getMeta( players, n );

    return players[ id_ia ].partial >= meta;
}

size_t getMeta( Player * players, size_t n )
{
    // posição da IA em relação a pontução total do jogo
    size_t rank = getRank( players, n );
    size_t id_ia = getIdIA( players, n );
    size_t meta = 0;
    size_t i;
    if ( rank != 1 )
    {
        for (i = 0; i < n; ++i )
        {
            if ( i != id_ia )
            {
                // encontra a maior pontução total do jogo
                meta = ( players[ i ].total > meta ) ? players[ i ].total : meta;
            } // end inner if
        } // end for

        // verifica quantos pontos numa parcial são necessários
        // para alcançar o primeiro lugar. 20 é o valor máximo para a meta.
        meta = ( meta - players[ id_ia ].total > 20 ) ? 20 : meta;
    } // end outer if
    else
    {
        // pontução mínimia a ser atingida numa parcial
        meta = 12;
    }

    return meta;
} // end function getMeta

size_t getRank( Player * players, size_t n )
{
    size_t id_ia = getIdIA(players,n);
    size_t total_score = players[ id_ia ].total;
    size_t rank = 1;
    size_t i;
    for (i = 0; i < n; ++i )
    {
        if ( !( i == id_ia ) )
        {
            rank += players[ i ].total > total_score ? 1 : 0;
        }
    } // end for

    return rank;
} // end function getRank

size_t getIdIA( Player * players, size_t n )
{   
    size_t m,i;
    for (i = 0; i < n; ++i )
    {
        if ( players[ i ].is_ia )
        {
            m = i; break;
        }
    }
    return m; 
} // end function getInfoIA