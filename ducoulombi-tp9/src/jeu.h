/**
 * @file jeu.h
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-09
 * 
 * @brief 
 * 
 */
#ifndef __jeu_h_
#define __jeu_h_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef enum eCouleur
{
    carreau,
    coeur,
    trefle,
    pique
}eCouleur;

typedef enum valeurCarte
{
    AS = 1,
    DEUX,
    TROIS,
    QUATRE,
    CINQ,
    SIX,
    SEPT,
    HUIT,
    NEUF,
    DIX,
    VALET = 10,
    DAME = 10,
    ROI = 10
}valeurCarte;

typedef struct carte
{
    valeurCarte valeur;
    eCouleur couleur;
}carte;

typedef struct joueur
{
    int argent;
    carte carte;
    char nom[30];
    char prenom[30];
}joueur;

/**
 * 
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-09
 * 
 * @brief 
 * 
 * @param paquet 
 */
void melange(carte *paquet);

/**
 * 
 * @author Quentin Ducoulombier (ducoulombi@cy-tech.fr)
 * @version 0.1
 * @date 2022-12-09
 * 
 * @brief 
 * 
 * @param paquet 
 * @param joueur 
 */
void donneCarte(carte *paquet, joueur* joueur);

#endif
