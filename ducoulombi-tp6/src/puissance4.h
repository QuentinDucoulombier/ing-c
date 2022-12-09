/**
 * @file puissance4.h
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-07
 * 
 * @brief fichier avec les appels de fonctions pour le puissance 4
 * 
 */
#ifndef __puissance4_h_
#define __puissance4_h_

#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>

#define N 7

/**
 * @fn void init (int ttint_plateau[N][N])
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-07
 * 
 * @brief procedure qui initialise le tableau a -1
 * 
 * @param ttint_plateau 
 */
void init (int ttint_plateau[N][N]);

/**
 * @fn void affichageP4(int ttint_plateau[N][N])
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-07
 * 
 * @brief affichage du tableau
 * 
 * @param ttint_plateau 
 */
void affichageP4(int ttint_plateau[N][N]);

/**
 * @fn int jouer(int ttint_plateau[N][N], int int_joueur, int int_x)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-07
 * 
 * @brief fonction jouer qui permet à un joueur donné de jouer dans une colonne spécifique. Si la colonne est pleine, afficher un message d’erreur. La méthode retournera 1 si tout s’est bien passé, et 0 si une erreur est survenue.
 * 
 * @param ttint_plateau 
 * @param int_joueur 
 * @param int_x 
 * @return 0 si pas d'erreur, 1 sinon
 */
int jouer(int ttint_plateau[N][N], int int_joueur, int int_x);

/**
 * @fn int aGagne(int ttint_plateau[N][N])
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-07
 * 
 * @brief fonction qui verifie qui a gagné
 * 
 * @param ttint_plateau 
 * @return le gagnant est retourner (0 ou 1), le match null est -2, et si erreur -1
 */
int aGagne(int ttint_plateau[N][N]);

/**
 * @fn void tourDeJeu_rotation(int ttint_plateau[N][N])
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-07
 * 
 * @brief Fonction tour de jeu avec rotation (mais la rotation marche pas vrmt)
 * 
 * @param ttint_plateau 
 */
void tourDeJeu_rotation(int ttint_plateau[N][N]);


#endif