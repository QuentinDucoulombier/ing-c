/**
 * @file affichage.h
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-23
 * 
 * @brief 
 * 
 */
#ifndef __affichage_h_
#define __affichage_h_

#include "jeu.h"

/**
 * @fn void afficheCarte(int couleur, int chiffre, int valeur)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-23
 * 
 * @brief 
 * 
 * @param couleur 
 * @param chiffre 
 * @param valeur 
 */
void afficheCarte(int couleur, int chiffre, int valeur);

/**
 * @fn void AfficherP(paquet p)
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-23
 * 
 * @brief 
 * 
 * @param p 
 */
void AfficherP(paquet p);

#endif