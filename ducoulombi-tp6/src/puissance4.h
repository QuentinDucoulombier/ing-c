#ifndef __puissance4_h_
#define __puissance4_h_

#define LIGNES 6
#define COLONNES 7
#include <stdio.h>

void initialisation(int tint_tab[LIGNES][COLONNES]);
void affichageP4 (int tint_tab[LIGNES][COLONNES]);
int choixJoueur(void);
void affichageDebut(int joueur);
int aGagne(int tint_tab[LIGNES][COLONNES]);
void tourDeJeu(int tint_tab[LIGNES][COLONNES], int gagnant, int joueur);
int jouer(int tint_plateau[LIGNES][COLONNES], int joueur);


#endif