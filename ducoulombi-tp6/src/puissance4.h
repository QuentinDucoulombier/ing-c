#ifndef __puissance4_h_
#define __puissance4_h_

#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>

#define N 7

void init (int ttint_plateau[N][N]);
void affichageP4(int ttint_plateau[N][N]);
int jouer(int ttint_plateau[N][N], int int_joueur, int int_x );
int aGagne(int ttint_plateau[N][N]);
void tourDeJeu_rotation(int ttint_plateau[N][N]);


#endif